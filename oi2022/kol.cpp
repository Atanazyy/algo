#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int r = 2009;
int wej[r][r];
int tab[r][r];
vector <int> kol;
vector<pair<int, int> > waz;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int m, p, n;
    cin >> m >> p >> n;
    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= m; j++)
            wej[i][j] = tab[i][j] = -1;
    while(p--)
    {
        int w, k, c;
        cin >> w >> k >> c;
        wej[w][k] = c;
    }
    int x = 1, y = 1;
    int start = 0;
    waz.push_back({1,1});
    kol.push_back(0);
    int t = 0;
    tab[1][1] = 0;
    while(n--)
    {
        char c;
        cin >> c;
        int zx = 0, zy = 0;
        if(c == 'Z')
        {
            int a, b;
            cin >> a >> b;
            if(tab[a][b] == -1)
                cout << "-1\n";
            else
                cout << kol[kol.size() - (t - tab[a][b] + 1)] << "\n";
            continue;
        }
        if(c == 'G')
            zx = -1;
        if(c == 'D')
            zx = 1;
        if(c == 'L')
            zy = -1;
        if(c == 'P')
            zy = 1;
        x += zx;
        y += zy;
        if(wej[x][y] == -1)
        {
            t++;
            tab[waz[start].f][waz[start].s] = -1;
            waz.push_back({x, y});
            start++;
            tab[x][y] = t;
        }
        else
        {
            t++;
            tab[x][y] = t;
            kol.push_back(wej[x][y]);
            waz.push_back({x, y});
            wej[x][y] = -1;
        }
        /*for(int i = start; i < waz.size(); i++)
        {
            auto v = waz[i];
            cout << v.f << " " << v.s << ", ";
        }
        cout << "\n";*/
    }
}
