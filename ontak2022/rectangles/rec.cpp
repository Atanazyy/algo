#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 3e5 + 9;
const int mw  = 250 * 1000;
const int roz = 262144 - 1;


vector <pair <int, int> > poc[r], kon[r], pkt[r];
int drz[4 * r];
int wyn[r];

void dod(int p, int k, int x)
{
    p += roz;
    k += roz;
    if(p == k)
    {
        drz[k] += x;
        return;
    }
    drz[k] += x;
    drz[p] += x;
    while(p / 2 != k / 2)
    {
        if(p % 2 == 0) drz[p + 1] += x;
        if(k % 2 == 1) drz[k - 1] += x;
        p /= 2;
        k /= 2;
    }
}
int sum(int x)
{
    x += roz;
    int s = 0;
    while(x > 0)
    {
        s += drz[x];
        x /= 2;
    }
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        poc[x1].push_back({y1, y2});
        kon[x2].push_back({y1, y2});
    }
    for(int i = 1; i <= q; i++)
    {
        int x, y;
        cin >> x >> y;
        pkt[x].push_back({i, y});
    }
    for(int i = 1; i <= mw; i++)
    {
        for(auto w : poc[i])
            dod(w.f, w.s, 1);
        for(auto w : pkt[i])
            wyn[w.f] = sum(w.s);
        for(auto w : kon[i])
            dod(w.f, w.s, -1);
    }
    for(int i = 1; i <= q; i++)
        cout << wyn[i] << "\n";
}