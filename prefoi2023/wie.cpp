#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int inf = 1e9, r = 1e6;
int tab[r];
vector <int> wej[r];
vector <int> G[r];
map <pair<int, int>, int> mapa;
set<pair<int, int> > byl;

int main()
{
    int n, m;
    cin >> n >> m;
    deque <pair<int, int> > q;
    int s, k;
    int nr = n;
    for(int i = 0; i < m; i++)
    {
        int b, p;
        cin >> b >> p;
        wej[b].push_back(p);
        if(i == 0)
            s = b;
        if(i == 1)
            k = b;
        if(byl.find({b, p}) != byl.end())
            continue;
        if(mapa.find({b, p}) != mapa.end())
            G[b].push_back(mapa[{b, p}]);
        else
        {
            mapa[{b, p}] = nr;
            G[nr].push_back(b);
            G[b].push_back(nr);
            int pop = nr;
            nr++;
            for(int i = b + p; i < n; i += p)
            {
                mapa[{i, p}] = nr;
                G[nr].push_back(pop);
                G[pop].push_back(nr);
                G[nr].push_back(i);
                pop = nr;
                nr++;
            }
            pop = mapa[{b, p}];
            for(int i = b - p; i >= 0; i -= p)
            {
                mapa[{i, p}] = nr;
                G[nr].push_back(pop);
                G[pop].push_back(nr);
                G[nr].push_back(i);
                pop = nr;
                nr++;
            }
        }
        byl.insert({b, p});
    }
    for(int i = 0; i < nr; i++)
        tab[i] = inf;
    /*for(int i = 0; i < nr; i++)
    {
        for(auto x : G[i])
            cout << i << " " << x << "\n";
    }*/
    q.push_front({0, s});
    while(!q.empty())
    {
        auto t = q.front();
        q.pop_front();
        if(tab[t.s] != inf)
            continue;
        tab[t.s] = t.f;
        for(auto x : G[t.s])
        {
            if(x < n || t.s < n)
                q.push_front({t.f, x});
            else
                q.push_back({t.f + 1, x});
        }
    }
    if(tab[k] == inf)
        cout << -1;
    else
        cout << tab[k];
}
