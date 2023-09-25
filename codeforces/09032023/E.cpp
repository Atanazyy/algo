#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;

const int r = 2e5 + 9, roz = 1e6;
vector<pair<int, int> > G[roz];
vector<pair<int, int> > OG[roz];
int co[roz];
int wyn[roz];
bool odw[roz];


void dfs(int v)
{
    odw[v] = 1;
    for(auto x : OG[v])
    {
        if(!odw[x.f])
            dfs(x.f);
        wyn[v] = max(wyn[v], wyn[x.f] + x.s);
    }
    //cout << v << " " << wyn[v] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<vector<int> > wej;
        set<int> poc;
        for(int i = 0; i < n; i++)
        {
            vector<int> xd;
            int k;
            cin >> k;
            while(k--)
            {
                int x;
                cin >> x;
                xd.push_back(x);
                poc.insert(x);
                poc.insert(x + 1);
            }
            wej.push_back(xd);
        }
        int m = -1;
        poc.insert(r);
        poc.insert(0);
        for(auto x : poc)
        {
            m++;
            co[x] = m;
            if(m != 0)
                G[m - 1].push_back({m, 0});
            wyn[m] = odw[m] = 0;
            G[m].clear();
            OG[m].clear();
        }
        for(int i = 0; i < n; i++)
        {
            int k = wej[i].size();
            int l = 0;
            for(int j = 0; j < k; j++)
            {
                int x = wej[i][j];
                m++;
                G[m].clear();
                OG[m].clear();
                wyn[m] = odw[m] = 0;
                if(x < l)
                    G[m - 1].push_back({m, 0});
                else
                {
                    G[co[x]].push_back({m, 1});
                    if(j != 0) 
                        G[m - 1].push_back({m, 1});
                    l = x + 1;
                }
                if(j == k - 1)
                {
                    G[m].push_back({co[l], 0});
                }
            }
        }
        for(int v = 0; v <= m; v++)
            for(auto x : G[v])
                {
                    //cout << v << " " << x.f << " " << x.s << "\n";
                    OG[x.f].push_back({v, x.s});
                }
        dfs(co[r]);
        cout << wyn[co[r]] << "\n";
    }
}