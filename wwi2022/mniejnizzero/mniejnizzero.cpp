#include <bits/stdc++.h>

#define f first
#define s second
using namespace std;

const int r = 1e6 + 10;
vector <pair<int, int> > tab;
vector <vector<int> > spo;
vector <pair<int, int> > dwu;
int kol [r];
bool czy[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tab.push_back({x, i});
    }
    sort(tab.begin(), tab.end());
    reverse(tab.begin(), tab.end());
    for(int i = 0; i < n; i++)
        kol[tab[i].s] = i;
    for(int i = 0; i < n; i++)
    {
        if(czy[i])
            continue;
        vector <int> xd;
        spo.push_back(xd);
        int x = kol[i];
        spo.back().push_back(i);
        czy[i] = 1;
        while(x != i)
        {
            spo.back().push_back(x);
            czy[x] = 1;
            x = kol[x];
        }
    }
    int par = 0;
    for(auto x : spo)
        if(x.size() % 2 == 0)
            par ++;
    if(par % 2 == 0)
        cout << "TAK\n";
    else
    {
        cout << "NIE\n";
        return 0;
    }
    int wyn = 0;
    for(auto x : spo)
    {
        if(x.size() % 2 == 0)
            wyn += (x.size() - 2) / 2;
        else
            wyn += 1 + (x.size() - 3) / 2;
    }
    cout << wyn + par << "\n";
    for(auto x : spo)
    {
        if(x.size() % 2 == 0)
        {
            dwu.push_back({x[0], x[x.size() - 1]});
            for(int i = 0; i + 2 < (int)x.size(); i += 2)
                cout << x[0] + 1 << " " << x[i + 1] + 1<< " " << x[i + 2] + 1<< "\n";
        }
        else
            for(int i = 0; i + 2 < (int)x.size(); i += 2)
                cout << x[0] + 1 << " " << x[i + 1] + 1 << " " << x[i + 2] + 1<< "\n";
    }
    for(int i = 0; i < (int)dwu.size(); i += 2)
    {
        cout << dwu[i].f + 1<< " " << dwu[i].s + 1 << " " << dwu[i + 1].f + 1<< "\n"; 
        cout << dwu[i].f + 1<< " " << dwu[i + 1].s + 1 << " " << dwu[i + 1].f + 1 << "\n";
    }
}