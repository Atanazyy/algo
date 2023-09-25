#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 2e5 + 9;
vector <pair <int, int> > G[r];
int kar[r];
int wyn[r];

struct ele
{
    long long odl;
    int poc;
    int kon;
    friend bool operator<(ele a, ele b)
    {
        if(a.odl != b.odl) 
            return a.odl > b.odl;
        return kar[a.poc] > kar[b.poc];
    }
};

priority_queue <ele> kol;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        G[b].push_back({a, c});
    }
    for(int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        if(kar[x] == 0) 
        {
            kar[x] = i;
            kol.push({0, x, x});
        }   
    }
    while(!kol.empty())
    {
        auto x = kol.top();
        //cout << x.odl << " " << x.poc << "\n";
        kol.pop();
        if(wyn[x.kon] != 0)
            continue;
        wyn[x.kon] = x.poc;
        for(auto y : G[x.kon])
            kol.push({y.s + x.odl, x.poc, y.f});
    }
    for(int i = 1; i <= n; i++)
        cout << ((wyn[i]) ? wyn[i] : -1) << " ";
}