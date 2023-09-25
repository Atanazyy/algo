#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

struct poz
{
    int z, y, x;
};

const int r = 130;
int wyn[r][r][r];
vector<poz> G[r][r][r];
bool tab[r][r][r], win[r][r][r];
pair<int, int> kto[r][r];
pair<int, int> roz[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, y, z;
    cin >> x >> y >> z;
    for(int i = 1; i <= z; i++)
    {
        for(int j = y; j >= 1 ; j--)
        {
            string s;
            cin >> s;
            for(int k = 1; k <= x; k++)
            {
                wyn[i][j][k] = -1;
                if(s[k - 1] == 'X')
                    tab[i][j][k] = 1;
                else
                    tab[i][j][k] = 0;
            }
        }
    }
    for(int i = 1; i <= x; i++)
        for(int j = 1; j <= y; j++)
            wyn[0][j][i] = -1;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        kto[a][b] = {c, d};
        for(int j = c; j <= d; j++)
        {
            win[j][b][a] = 1;
        }
    }
    deque <poz> kol;
    int a, b, c;
    cin >> a >> b >> c;
    kol.push_front({c, b, a});
    wyn[c][b][a] = 0;
    while(!kol.empty())
    {
        auto akt = kol.front();
        int wakt = wyn[akt.z][akt.y][akt.x];
        //cout << akt.z << " " << akt.y << " " << akt.x << ": " << wakt << "\n";
        kol.pop_front();
        auto nas = akt;
        if(akt.z == 0)
        {
            //cout << kto[akt.x][akt.y].f << " " << kto[akt.x][akt.y].s << "\n";
            for(int z = kto[akt.x][akt.y].f; z <= kto[akt.x][akt.y].s; z++)
            {
                if(tab[z][nas.y][nas.x] == 1 || wyn[z][nas.y][nas.x] != -1)
                    continue;
                wyn[z][nas.y][nas.x] = wakt + 1;
                kol.push_back({z, nas.y, nas. x});
            }
            continue;
        }
        for(int i = 0; i < 4; i++)
        {
            nas = akt;
            nas.x += roz[i].f;
            nas.y += roz[i].s;
            if(tab[nas.z][nas.y][nas.x] == 1 || wyn[nas.z][nas.y][nas.x] != -1)
                continue;
            wyn[nas.z][nas.y][nas.x] = wakt + 1;
            kol.push_back({nas.z, nas.y, nas. x});
        }
        nas = akt;
        if(tab[0][nas.y][nas.x] == 1 || wyn[0][nas.y][nas.x] != -1 || !win[akt.z][akt.y][akt.x])
            continue;
        wyn[0][nas.y][nas.x] = wakt - 1;
        kol.push_front({0, nas.y, nas. x});
    }
    cin >> a >> b >> c;
    cout << wyn[c][b][a];
}
