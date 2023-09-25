#include <bits/stdc++.h>

using namespace std;

const int r = 2e5 + 9, p1 = 313, p2 = 997, m1 = 1e9 + 7, m2 = 1e9 + 9;
int tab[r];
set <pair<long long, long long> > moz;
long long dpd1[r], dpd2[r], dpg1[r], dpg2[r];
vector <int> G[r];

void dfs1(int v, int o)
{
    for(auto x : G[v])
    {
        if(x == o)
            continue;
        dfs1(x, v);
        dpd1[v] = (dpd1[v] + dpd1[x]) % m1; 
        dpd2[v] = (dpd2[v] + dpd2[x]) % m2; 
    }
    dpd1[v] = (dpd1[v] * p1 + 1) % m1;
    dpd2[v] = (dpd2[v] * p2 + 1) % m2;
}

void dfs2(int v, int o)
{
    if(v != 1)
    {
        dpg1[v] = (dpg1[o] * p1 + dpd1[o] - ((dpd1[v] * p1) % m1) + m1) % m1;
        dpg2[v] = (dpg2[o] * p2 + dpd2[o] - ((dpd2[v] * p2) % m2) + m2) % m2;
    }
    for(auto x : G[v])
    {
        if(x == o)
            continue;
        dfs2(x, v);
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int x;
        cin >> x;
        tab[x] ++;
    }
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    long long H1 = 0;
    long long H2 = 0;
    for(int i = n - 1; i >= 0; i--)
    {
        H1 = (H1 * p1 + tab[i]) % m1;
        H2 = (H2 * p2 + tab[i]) % m2;
    }
    long long d1 = 1;
    long long d2 = 1;
    for(int i = 0; i <= n - 1; i++)
    {
        moz.insert({(H1 + d1) % m1, (H2 + d2) % m2});
        d1 = (d1 * p1) % m1;
        d2 = (d2 * p2) % m2;
    }
    dfs1(1, 1);
    dfs2(1, 1);
    set <int> wyn;
    for(int i = 1; i <= n; i++)
    {
        long long h1 = (dpd1[i] + p1 * dpg1[i]) % m1;
        long long h2 = (dpd2[i] + p2 * dpg2[i]) % m2;
        if(moz.find({h1, h2}) != moz.end())
            wyn.insert(i);
    }
    cout << wyn.size() << "\n";
    for(auto x : wyn)
        cout << x << " ";
}