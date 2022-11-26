#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 1e5 + 9;
vector <pair <int, int> > tab[r];  
int odl[r];
int dp[r];
int dl[r];
long long drz[4 * r][4];
int n, k;

struct Solve1
{
    void dfs(int v, int o)
    {
        for(auto x : tab[v])
        {
            if(x.f == o)
                continue;
            odl[x.f] = odl[v] + x.s;
            dfs(x.f, v);
        }
    }

    void solve1()
    {
        for(int i = 1; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            tab[a].push_back({b, c});
            tab[b].push_back({a, c});
        }
        long long wyn = 0;
        vector <int> kro;
        kro.push_back(1);
        for(int i = 1; i <= k; i++)
        {
            int v;
            cin >> v;
            odl[v] = 0;
            dfs(v, v);
            for(auto x : kro)
                wyn += 2 * odl[x];
            kro.push_back(v);
            cout << wyn << "\n";
        }
    }
};

struct Solve2
{
    int roz;
    long long kuery(int v, int d)
    {
        v += roz;
        long long wyn = 0;
        while(v > 0)
        {
            wyn += drz[v][d];
            v /= 2;
        }
        return wyn;
    } 
    void ubdat(int a, int b, int c, int d)
    {
        a += roz;
        b += roz;
        if(a == b)
        {
            drz[a][d] += c;
            return;
        }
        drz[a][d] += c;
        drz[b][d] += c;
        while(a / 2 != b / 2)
        {
            if(a % 2 == 0) drz[a + 1][d] += c;
            if(b % 2 == 1) drz[b - 1][d] += c;
            a /= 2;
            b /= 2;
        }
    }
    void solve2()
    {
        roz = ceil(log2(n + 5));
        roz = 1 << roz;
        roz --;
        for(int i = 1; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            tab[a].push_back({b, c});
            tab[b].push_back({a, c});
            odl[min(a, b)] = c;
        }
        for(int i = 2; i <= n; i++)
            dl[i] = dl[i - 1] + odl[i - 1];
        for(int i = n - 1; i >= 1; i--)
            dp[i] = dp[i + 1] + odl[i];
        long long wyn = 0;
        ubdat(1, n, 1, 0);
        for(int i = 0; i < k; i++)
        {
            int v; 
            cin >> v;
            wyn += dl[v] * kuery(v, 0) + dp[v] * kuery(v, 2) - kuery(v, 1) - kuery(v, 3);
            cout << wyn * 2 << "\n";
            ubdat(v, n, 1, 0);
            ubdat(1, v, 1, 2);
            ubdat(v, n, dl[v], 1);
            ubdat(1, v, dp[v], 3);
        }
    }
};

int main()
{
    cin >> n >> k;
    if((long long)n * (long long)k <= (long long)r)
    {
        Solve1 S;
        S.solve1();
    }
    else
    {
        Solve2 S;
        S.solve2();
    }
}