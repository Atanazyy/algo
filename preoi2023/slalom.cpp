#include <bits/stdc++.h>

using namespace std;

struct edg
{
    int v;
    long long cp, cd;
};

struct nod
{
    long long pie, drb, drn;
};
const int r = 3e3 + 9;
const long long inf = 1e17;
nod dp[r];
int sto[r];
vector <edg> G[r];
vector <edg> O[r];

int main()
{
    int n, m;
    cin >> n >> m;
    while(m--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        G[a].push_back({b, c, d});
        G[b].push_back({a, c, d});
        sto[b] ++;
    }
    stack <int> top;
    top.push(1);
    while(!top.empty())
    {
        int v = sto.top();
        for(auto x : G[v])
        {
            sto[x.v]--;
            if(sto[x.v] == 0)
                top.push(x.v);
        }
        dp[v].pie = dp[v].drn = dp[v].drb;
        for(auto x : O[v])
        {
            dp[v].pie = min(dp[v].pie, dp[x.v].pie + x.cp);
            dp[v].drn = min(dp[v].drn, min(dp[x.v].drn + x.cp, dp[x.v].drb + x.cp));
            dp[v].drb = min(dp[v].drb, dp[x.v].drb + x.cp + x.cd);
        }
        for(auto x : O[v])
            for(auto y : O[v])
                if(x.v != y.v)
                    dp[v].drb = min(dp[v].drb, dp[x.v].pie + x.cp + dp);
    }
    cout << dp[n].drb;
}
