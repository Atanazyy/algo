#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 250 * 1000 + 50;
const int rp = 510;
int pn, ppn, id;
vector<int> G[r];
int tra[r];
int wej[r];
int tab[r];
int ile[rp][r];
bool mark[r];
int lid[r];
int gdz[r];
pair<int, int> zli[r];
pair<int, int> zll[r];
pair<int, int> zln[r];

inline void dfs(int v)
{
    for(auto x : G[v])
    {
        if(tra[x] != 0)
            continue;
        tra[x] = tra[v] + 1;
        dfs(x);
    }
}

inline void zwi(int x)
{
    if(zli[x].f != id)
    {
        zli[x].f = id;
        zli[x].s = 1;
    }
    else
        zli[x].s ++;
}

inline int cyt(int x)
{
    if(zli[x].f != id)
        return 0;
    else
        return zli[x].s;
}

inline void zwil(int x)
{
    if(zll[x].f != id)
    {
        zll[x].f = id;
        zll[x].s = 1;
    }
    else
        zll[x].s ++;
}

inline int cytl(int x)
{
    if(zll[x].f != id)
        return 0;
    else
        return zll[x].s;
}

inline void zwin(int x)
{
    if(zln[x].f != id)
    {
        zln[x].f = id;
        zln[x].s = 1;
    }
    else
        zln[x].s ++;
}

inline int cytn(int x)
{
    if(zln[x].f != id)
        return 0;
    else
        return zln[x].s;
}

inline int zap(int np, int nk)
{
    int p = min(tra[np], tra[nk]), k = max(tra[np], tra[nk]);
    int co = 0;
    int col = 0;
    int cnt = 0;
    int con = 0;
    int sta = -1;
    int i;
    for(i = p; i <= k && !mark[i]; i++)
    {
        cnt ++;
        if(cnt <= pn)
        {
            zwi(tab[i]);
            if(cyt(tab[i]) >= cyt(co))
                co = tab[i];
        }
        else
        {
            zwin(tab[i]);
            if(cytn(tab[i]) >= cytn(con))
                con = tab[i];
        }
    }
    sta = i;
    for(; i + pn - 1 <= k; i += pn)
    {
        if(lid[i] == 0)
            continue;
        zwil(lid[i]);
        if(cytl(lid[i]) >= cytl(col))
            col = lid[i];
    }
    for(; i <= k; i++)
    {
        cnt ++;
        if(cnt <= pn)
        {
            zwi(tab[i]);
            if(cyt(tab[i]) >= cyt(co))
                co = tab[i];
        }
        else
        {
            zwin(tab[i]);
            if(cytn(tab[i]) >= cytn(con))
                con = tab[i];
        }
    }
    int wyn1 = 0, wyn2 = 0, wyn3 = 0;
    for(i = sta; i + pn - 1 <= k; i += pn)
    {
        int x = gdz[i];
        wyn1 += ile[x][con];
        wyn2 += ile[x][col];
        wyn3 += ile[x][co];
    }
    wyn1 += cytn(con) + cyt(con);
    if(wyn1 * 2 > k - p + 1 && con != 0)
    {
        id ++;
        return con;
    }
    wyn2 += cyt(col) + cytn(col);  
    if(wyn2 * 2 > k - p + 1 && col != 0)
    {
        id ++;
        return col;
    }
    wyn3 += cyt(co) + cytn(co);
    if(wyn3 * 2 > k - p + 1 && co != 0)
    {
        id ++;
        return co;
    }
    id++;
    return -1;
}

int main()
{
    //ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, q;
    scanf("%d", &n);
    scanf("%d", &q);
    pn = sqrt(n);
    ppn = pn / 2;
    string t;
    getline(cin, t);
    cout << t;
    int ai = 1;
    int l = 0;
    for(auto x : t)
    {
        if(x == ' ' || x == '\n')
        {
            wej[ai] = l;
            ai ++;
            l = 0;
        }
        else
        {
            l *= 10;
            l += x - '0';
        }
    }
    for(int i = 0; i < n - 1; i++)
    {
        int v, u;
        scanf("%d", &u);
        scanf("%d", &v);
        G[v].push_back(u);
        G[u].push_back(v);
    }
    int a;
    for(int i = 1; i <= n; i++)
        if(G[i].size() == 1)
        {
            a = i;
            break;
        }
    tra[a] = 1;
    dfs(a);
    for(int i = 1; i <= n; i++)
        tab[tra[i]] = wej[i];
    int cnt = 0;
    for(int i = 1; i + pn - 1 <= n; i += pn)
    {
        cnt ++;
        mark[i] = 1;
        gdz[i] = cnt;
        for(int j = i; j < i + pn; j++)
        {
            ile[cnt][tab[j]]++;
            if(ile[cnt][tab[j]] > ppn)
                lid[i] = tab[j];
        }
        //cout << i << " " << lid[i] << "\n";
    }
    while(q--)
    {
        int p, k;
        scanf("%d", &p);
        scanf("%d", &k);
        printf("%d\n", zap(p, k));
    }
}