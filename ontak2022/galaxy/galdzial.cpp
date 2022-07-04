#include <bits/stdc++.h>

using namespace std;

const double inf = 2e9;
const int r = 1e6;
int n, m;

struct pkt
{
    long long x, y;
};

pkt gwi[r];
pkt dzi[r];
vector <pkt> str;

bool porx(pkt a, pkt b)
{
    return a.x < b.x;
}

bool pory(pkt a, pkt b)
{
    return a.y < b.y;
}

double dist(pkt a, pkt b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double brut(int p, int k)
{
    double ans = inf;
    for(int i = p; i <= k; i++)
        for(int j = i + 1; j <= k; j++)
            ans = min(ans, dist(gwi[i], gwi[j]));
    return ans;
}

double best(int p, int k)
{
    if((k - p + 1) < 4)
        return brut(p, k);
    int mid = (p + k) / 2;
    double d = gwi[mid].x;
    double pos = min(best(p, mid), best(mid + 1, k));
    str.clear();
    for(int i = p; i <= k; i++)
        if(abs(d - gwi[i].x) < pos)
            str.push_back(gwi[i]);
    sort(str.begin(), str.end(), pory);
    for (int i = 0; i < (int)str.size(); i++)
        for (int j = i + 1; j < (int)str.size(); j++)
        {
            if((str[j].y - str[i].y) >= pos)
                break;
            pos = min(pos, dist(str[i], str[j]));
        }
    return pos;
}

double dodziu()
{
    vector <double> wyn;
    for(int i = 1; i <= n; i++)
    {
        double naj = inf;
        for(int j = 1; j <= m; j++)
        {
            naj = min(naj, dist(gwi[i], dzi[j]));
        }
        wyn.push_back(naj);
    }
    sort(wyn.begin(), wyn.end());
    return wyn[0] + wyn[1];
}

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> gwi[i].x >> gwi[i].y;
    }
    for(int i = 1; i <= m; i++)
    {
        cin >> dzi[i].x >> dzi[i].y;
    }
    sort(gwi + 1, gwi + n + 1, porx);
    double ans = best(1, n);
    //cout << ans << " " << brut(1, n);
    cout << fixed << setprecision(10) << min(ans, dodziu()) / 2;
}