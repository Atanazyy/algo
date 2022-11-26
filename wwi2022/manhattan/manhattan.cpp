#include <bits/stdc++.h>

#define f first 
#define s second

using namespace std;

int roz;
const int r = 1e6 + 9, nie = 2e9 + 10;
const long long inf = 1e18;
vector <pair <int, int> > tab;
long long wyn[r];
int drz[4 * r];
map <pair<int, int>, int> czy;

bool C1(int x, int y)
{
    return tab[x].s < tab[y].s;
}

bool C2(int x, int y)
{
    if(tab[x].f == tab[y].f)
        return tab[x].s < tab[y].s;
    return tab[x].f < tab[y].f;
}

void ubdat(int v, int x)
{
    v += roz;
    drz[v] = max(x, drz[v]);
    v /= 2;
    while(v > 0)
    {
        drz[v] = max(drz[v * 2], drz[v * 2 + 1]);
        v /= 2;
    }
}

int kuery(int p, int k)
{
    p += roz;
    k += roz;
    if(p == k)
        return drz[p];
    int res = max(drz[p], drz[k]);
    while(p / 2 != k / 2)
    {
        if(p % 2 == 0)
            res = max(res, drz[p + 1]);
        if(k % 2 == 1)
            res = max(res, drz[k - 1]);
        p /= 2;
        k /= 2;
    }
    return res;
}

void solve(int n)
{
    roz = ceil(log2(n));
    roz = 1 << roz;
    for(int i = 0; i <= 2 * roz; i++)
        drz[i] = -nie;
    map <int, int> ska;
    vector <int> pkt;
    for(int i = 0; i < n; i++)
        pkt.push_back(i);
    sort(pkt.begin(), pkt.end(), C1);
    for(int i = 0; i < n; i++)
    {
        //cout << pkt[i] << "\n";
        ska[tab[pkt[i]].s] = i;
    }
    sort(pkt.begin(), pkt.end(), C2);
    for(auto x : pkt)
    {
        long long rek = kuery(0, ska[tab[x].s]);
        if(rek != -nie)
            wyn[x] = min(wyn[x], tab[x].f + tab[x].s - rek);
        ubdat(ska[tab[x].s], tab[x].s + tab[x].f);
        /*cout << x << " " << ska[tab[x].s] << "\n";
        for(int i = 1; i < 2 * roz; i ++)
            cout << drz[i] << " ";
        cout << "\n";*/
    }
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        tab.push_back({x, y});
        wyn[i] = inf;
        if(czy.find({x, y}) == czy.end())
            czy[{x, y}] = 0;
        czy[{x, y}] ++;
    }
    solve(n);
    for(int i = 0; i < n; i++)
        tab[i].f *= -1;
    solve(n);
    for(int i = 0; i < n; i++)
        tab[i].s *= -1;
    solve(n);
    for(int i = 0; i < n; i++)
        tab[i].f *= -1;
    solve(n);
    for(int i = 0; i < n; i++)
        tab[i].s *= -1;
    for(int i = 0; i < n; i++)
        if(czy[{tab[i].f, tab[i].s}] > 1)
            cout << "0\n";
        else
            cout << wyn[i] << "\n";
}