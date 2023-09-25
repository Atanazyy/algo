#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 5e3;
int tab[r];
int pop[r];
bool ogr[r];
bool ogr2[r];
int gdz[r];
vector <pair<int, int> > sor;
vector <int> poc;
vector <int> kon;

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        sor.push_back({tab[i], i});
    }
    sort(sor.begin(), sor.end());
    for(int i = 0; i < n; i++)
    {
        pop[sor[i].s] = i + 1;
        gdz[i + 1] = sor[i].s;
    }
    bool f = 1;
    for(int i = 1; i <= n; i++)
        if(pop[i] != i)
            f = 0;
    if(f)
    {
        cout << 0;
        return 0;
    }
    f = 1;
    for(int i = 1; i <= n; i++)
    {
        if(pop[pop[i]] != i)
            f = 0;
        else if(!ogr[i] && i != pop[i])
        {
            ogr[i] = 1;
            ogr[pop[i]] = 1;
            poc.push_back(i);
            kon.push_back(pop[i]);
        }
    }
    if(f)
    {
        cout << "1\n" << poc.size() * 2<< "\n";
        for(auto x : poc)
            cout << x << " ";
        reverse(kon.begin(), kon.end());
        for(auto x : kon)
            cout << x << " ";
        return 0;
    }
    poc.clear();
    kon.clear();
    for(int i = 1; i <= n; i++)
    {
        if(ogr[i])
            continue;
        int w = i;
        while(pop[pop[w]] != w && pop[w] != w)
        {
            //cout << w << " " << pop[w] << " " << gdz[w] << "\n";
            poc.push_back(pop[w]);
            kon.push_back(gdz[w]);
            pop[gdz[w]] = pop[pop[w]];
            gdz[pop[pop[w]]] = gdz[w];
            int sw = w;
            ogr[w] = 1;
            w = gdz[w];
            pop[pop[sw]] = sw;
            gdz[sw] = pop[sw];
            ogr[w] = 1;
        }
        ogr[w] = 1;
        ogr[pop[w]] = 1;
    }
    cout << "2\n" << poc.size() * 2 << "\n";
    for(auto x : poc)
        cout << x << " ";
    reverse(kon.begin(), kon.end());
    for(auto x : kon)
        cout << x << " ";
    poc.clear();
    kon.clear();
    for(int i = 1; i <= n; i++)
    {
        if(!ogr2[i] && i != pop[i])
        {
            ogr2[pop[i]] = 1;
            poc.push_back(i);
            kon.push_back(pop[i]);
        }
    }
    cout << "\n" << poc.size() * 2 << "\n";
    for(auto x : poc)
        cout << x << " ";
    reverse(kon.begin(), kon.end());
    for(auto x : kon)
        cout << x << " ";
    return 0;
}