#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

map <long long, pair<long long, long long> > dp[809];
vector<pair <int, long long> > G[809];
long long zar[809];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, p;
        cin >> n >> m >> p;
        for(int i = 1; i <= n; i++)
        {
            cin >> zar[i];
            G[i].clear();
            dp[i].clear();
        }
        for(int i = 0; i < m; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            G[a].push_back({b, c});
        }
        priority_queue<pair<pair<long long, long long>, pair<int, long long> > > pq;
        pq.push({{0, p}, {1, 0}});
        while(!pq.empty())
        {
            auto k = pq.top();
            pq.pop();
            if(dp[k.s.f].find(k.s.s) != dp[k.s.f].end())
                continue;
           // cout << k.f.f << " " << k.f.s << " " << k.s.f << " " << k.s.s << "\n";
            dp[k.s.f][k.s.s] = {-k.f.f, k.f.s};
            for(auto x : G[k.s.f])
            {
                long long mz = max(k.s.s, zar[k.s.f]);
                double zos = k.f.s - x.s;
                if(zos >= 0)
                    pq.push({{k.f.f, zos}, {x.f, mz}});
                else
                {
                    zos = abs(zos);
                    long long pra = ceil(zos / mz);
                    pq.push({{k.f.f - pra, pra * mz - zos}, {x.f, mz}});
                }
            }
        }
        long long wyn = 1e18;
        for(auto x : dp[n])
            wyn = min(x.s.f, wyn);
        if(wyn == (long long)1e18)
            cout << "-1\n";
        else
            cout << wyn << "\n";
    }
}