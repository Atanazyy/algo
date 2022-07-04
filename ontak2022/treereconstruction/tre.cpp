#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 1e3 + 9; 
bool tab[r][r];
int siz[r];
pair<int, int> kto[r];
map <set<int>, int> mapa;
vector <int> kra;
bool obr[r];
set <int> G;

void solve()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[a][b] = 1;
        tab[b][a] = 1;
    }
    int nr = 1;
    for(int i = 1; i <= n; i++)
    {
        set <int> kli1;
        set <int> kli2;
        kli1.insert(i);
        int iny = 0, ile = 1;
        for(int x = 1; x <= n; x++)
        {
            if(tab[i][x] == 0)
                continue;
            ile ++;
            bool f = 1;
            for(auto y : kli1)
                if(tab[x][y] == 0)
                {
                    if(x != i)
                        iny = x; 
                    f = 0;
                    break;
                }
            if(f)
            {
                kli1.insert(x);
            }
        }
        if(mapa.find(kli1) == mapa.end())
        {
            mapa[kli1] = nr;
            siz[nr] = kli1.size();
            kto[i].f = nr;
            nr++;
        }
        else
            kto[i].f = mapa[kli1];
        if(iny != 0)
        {
            kli2.insert(iny);
            kli2.insert(i);
            for(int x = 1; x <= n; x++)
            {
                if(tab[i][x] == 0)
                    continue;
                bool f = 1;
                for(auto y : kli2)
                    if(tab[x][y] == 0)
                    {
                        f = 0;
                        break;
                    }
                if(f)
                {
                    kli2.insert(x);
                }
            }
            if(mapa.find(kli2) == mapa.end())
            {
                mapa[kli2] = nr;
                kto[i].s = nr;
                siz[nr] = kli2.size();
                nr++;
            }
            else
                kto[i].s = mapa[kli2];
        }
        set <int> sum;
        for(auto x : kli1)
            sum.insert(x);
        for(auto x : kli2)
            if(sum.find(x) == sum.end() || x == i)
                sum.insert(x);
            else
            {
                cout << "NO\n";
                return;
            }
        if(ile != (int)sum.size())
        {
            cout << "NO\n";
            return;
        }
    }
    nr --;
    for(int i = 1; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            if(tab[i][j] == 1)
            {
                if(G[kto[i]].)
            }
        }
    }
    cout << "YES\n";
    /*for(auto x : mapa)
    {
        cout << x.s << ", " << siz[x.s] << ": ";
        for(auto y : x.f)
            cout << y << " ";
        cout << "\n";
    }
    for(int i = 1; i <= n; i++)
    {
        cout << i << ": " << kto[i].f << " " << kto[i].s << "\n";
    }*/
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }
}