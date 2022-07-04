#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 1e5;
vector <pair<int, int> > tab[r];
vector <pair<int, int> > kra;
vector <int> W[r];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[a].push_back({b, i});
        tab[b].push_back({a, i});
        kra.push_back({a, b});
    }
    for(int i = 1; i < n; i++)
    {
        for(auto x : tab[kra[i - 1].f])
            if(i != x.s) 
                W[i].push_back(x.s);
        /*for(auto x : tab[kra[i - 1].s])
            W[i].push_back(x.s);*/
    }
    for(int i = 1; i <= n; i++)
    {
        for(auto x : W[i])
            cout << i << " " << x << "\n";
    }
}