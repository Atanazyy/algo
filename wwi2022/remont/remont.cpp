#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 2e5 + 10;
vector <int> G[r];
bool wie[r];
pair <int, int> usu;
int ile[r], pre[r], siz[r], dis[r];
int nr = 1, n;

void szu(int v, int o)
{
    wie[v] = 1;
    siz[v] = 1;
    pre[v] = nr;
    nr++;
    for(auto u : G[v])
    {
        if(u == o)
            continue;
        if(wie[u] == 1)
        {
            usu = {v, u};
            continue;
        } 
        szu(u, v);
        ile[v] += ile[u];
        siz[v] += siz[u];
    }
    //cout << v << " " << ile[v] << " " << siz[v] << " " << pre[v] << "\n";
}


int odl(int p, int k)
{
    for(int i = 0; i <= n; i++)
        dis[i] = -1;
    queue <int> kol;
    kol.push(p);
    dis[p] = 0;
    while(!kol.empty())
    {
        int v = kol.front();
        kol.pop();
        for(auto x : G[v])
        {
            if(dis[x] == -1)
            {
                kol.push(x);
                dis[x] = dis[v] + 1;
            }
        }
    }
    return dis[k];
}

int pod (int wyz, int niz)
{
    return pre[wyz] <= pre[niz] && pre[wyz] + siz[wyz] > pre[niz];
}

bool czy(int B, int F, int z)
{
    cout << B << " " << F << " " << z << "\n";
    return 0;
}

int main()
{
    int B, F;
    cin >> n >> B >> F;
    for(int i = 0; i < n; i++)
    {
        int v, u;
        cin >> v >> u;
        G[v].push_back(u);
        G[u].push_back(v);
    }
    string c;
    cin >> c;
    for(int i = 0; i < n; i++)
        ile[i + 1] = c[i] - '0';
    szu(1, 0);
    int v, u;
    cin >> v >> u;
    cout << odl(v, u);
    //cout << usu.f << " " << usu.s;
    int df1 = odl(F, usu.f), df2 = odl(F, usu.s));
    int db1 = odl(B, usu.f), db2 = odl(B, usu.s));
    
    
}