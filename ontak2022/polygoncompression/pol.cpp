#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int r = 2e3 + 9;
const long double inf = 1e9;
long double dist[r][r];
pair <long double, long double> tab[r];
bool zro[r];

void solve(int p)
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        zro[i] = 0;
        int x, y;
        cin >> x >> y;
        tab[i] = {x, y};
    }
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = sqrt((tab[i].f - tab[j].f) * (tab[i].f - tab[j].f) + ((tab[i].s - tab[j].s) * (tab[i].s - tab[j].s)));
        }
    priority_queue <pair<long double, int> > kol;
    kol.push({0, 0});
    long double wyn = 0;
    while(!kol.empty())
    {
        int v = kol.top().second;
        long double o = -kol.top().first;
        kol.pop();
        if(zro[v] == 1)
            continue;
        zro[v] = 1;
        wyn += o;
        for(int i = 0; i < n; i++)
        {
            if(!zro[i]) 
                kol.push({-dist[v][i], i});
        }
    }
    cout << fixed << setprecision(10) << wyn << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int p, t;
    cin >> p >> t;
    while(t--)
        solve(p); 
}