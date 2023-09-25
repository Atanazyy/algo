#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int inf = 1e9;
int tab[30009];
vector<int> wej[30009];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        tab[i] = inf;
    priority_queue <pair<int, int> > pq;
    int s, k;
    for(int i = 0; i < m; i++)
    {
        int b, p;
        cin >> b >> p;
        wej[b].push_back(p);
        if(i == 0)
            s = b;
        if(i == 1)
            k = b;
    }
    pq.push({0, s});
    while(!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        if(tab[t.s] != inf)
            continue;
        tab[t.s] = -t.f;
        for(auto x : wej[t.s])
        {
            int k = 0;
            for(int i = t.s + x; i < n; i += x)
            {
                k++;
                pq.push({t.f - k, i});
            }
            k = 0;
            for(int i = t.s - x; i >= 0; i -= x)
            {
                k++;
                pq.push({t.f - k, i});
            }
        }
    }
    if(tab[k] == inf)
        cout << -1;
    else
        cout << tab[k];
}
