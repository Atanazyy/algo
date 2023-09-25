#include <bits/stdc++.h>

#define f first
#define s second
#define LD long double
#define LL long long

using namespace std;

const int r = 2e3 + 9;
pair<LL, LL> tab[r]; 
vector <pair<LL, int> > G[r];
bool odw[r];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> tab[i].f >> tab[i].s;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
        {
            LL odl = (tab[i].f - tab[j].f) * (tab[i].f - tab[j].f) + (tab[i].s - tab[j].s) * (tab[i].s - tab[j].s);
            G[i].push_back({odl, j});
            G[j].push_back({odl, i});
        }
    priority_queue <pair<LL, int> > kol;
    kol.push({0, 1});
    LD wyn = 0;
    while(!kol.empty())
    {
        auto x = kol.top();
        kol.pop();
        if(odw[x.s])
            continue;
        wyn += sqrt(abs(x.f));
        odw[x.s] = 1;
        for(auto y : G[x.s])
        {
            if(!odw[y.s])
                kol.push({-y.f, y.s});
        }
    }
    cout << fixed << setprecision(6) << wyn;
}