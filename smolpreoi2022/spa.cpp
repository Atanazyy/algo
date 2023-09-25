#include <bits/stdc++.h>
#define ld long double
#define ll long long
using namespace std;

const int r = 109;
const ll inf = 1e15; 
const ld eps = 1e-6;
ll G[r][r];
ld T[r][r];
int n, m;

ld minld(ld a, ld b)
{
    if(a - b > eps) return b;
    return a;
}

bool czy(ld sr)
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            T[i][j] = (T[i][j] < inf) ? (G[i][j] - sr) : inf;
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                if(T[i][k] < inf && T[k][j] < inf)
                    T[i][j] = minld(T[i][j], T[i][k] + T[k][j]);
    for(int i = 1; i <= n; i++)
        if(T[i][i] < 0) 
            return 1;
    return 0;
}

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            G[i][j] = inf;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        G[a][b] = min(c, G[a][b]);
    }
    ld poc = -1e9, kon = 1e9;
    while(kon - poc > eps)
    {
        ld sr = (kon + poc) / 2;
        if(czy(sr))
            kon = sr;
        else
            poc = sr;
    }
    cout << fixed << setprecision(3) << poc;
}