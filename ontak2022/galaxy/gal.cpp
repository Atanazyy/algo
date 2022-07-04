#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const double inf = 1e10;
const int r = 1e6 + 9;
int n, m;

struct pkt
{
    int x, y;
    bool c;
};

pkt dzi[r];
pkt gwi[r];
vector <pkt> str;
vector <pair<pkt, int> > str2;

bool porx(pkt a, pkt b)
{
    return a.x < b.x;
}

bool pory(pkt a, pkt b)
{
    return a.y < b.y;
}

bool pory2(pair<pkt, int> a, pair<pkt, int>  b)
{
    return a.f.y < b.f.y;
}

double dist(pkt a, pkt b)
{
    return sqrt((long long)(a.x - b.x) * (long long)(a.x - b.x) + (long long)(a.y - b.y) * (long long)(a.y - b.y));
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

pair<double, int> brut2(int p, int k)
{
    double ans = inf;
    int co;
    for(int i = p; i <= k; i++)
        for(int j = i + 1; j <= k; j++)
        {
            double dis = dist(gwi[i], gwi[j]);
            if(gwi[i].c != gwi[j].c && dis < ans)
            {
                int g;
                if(gwi[i].c == 0)
                    g = i;
                else
                    g = j; 
                ans = dis;
                co = g;
            }
        }
    return {ans, co};
}

pair<double, int> best2(int p, int k)
{
    cout << p << " "<< k<<"\n";
    if((k - p + 1) < 4)
        return brut2(p, k);
    int mid = (p + k) / 2;
    double d = gwi[mid].x;
    auto L = best2(p, mid);
    double pos = L.f;
    int co = L.s;
    auto R = best2(mid + 1, k);
    if(pos > R.f)
    {
        pos = R.f;
        co = R.s;
    }
    str2.clear();
    for(int i = p; i <= k; i++)
        if(abs(d - gwi[i].x) < pos)
            str2.push_back({gwi[i], i});
    sort(str2.begin(), str2.end(), pory2);
    double posb = pos;
    for (int i = 0; i < (int)str2.size(); i++)
    {
        for (int j = i + 1; j < (int)str2.size(); j++)
        {
            if(abs(str2[j].f.y - str2[i].f.y) >= posb)
                break;
            double dis = dist(str2[i].f, str2[j].f);
            posb = min(posb, dis);
            if(str2[j].f.c != str2[i].f.c && dis < pos)
            {
                int g;
                pos = dis;
                if(str2[i].f.c == 0)
                    g = str2[i].s;
                else
                    g = str2[j].s; 
                co = g;
            }
        }
    }
    return {pos, co};
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
    for(int i = n + 1; i <= n + m; i++)
    {
        cin >> gwi[i].x >> gwi[i].y;
        dzi[i - n] = gwi[i];
        gwi[i].c = 1;
    }
    sort(gwi + 1, gwi + n + 1, porx);
    double ans = best(1, n);
    if(m == 0)
    {
        cout << fixed << setprecision(10) << ans/ 2;
        return 0;
    }
    /*if(m <= 100)
    {
        cout << fixed << setprecision(10) << min(ans, dodziu()) / 2;
        return 0;
    }*/
    sort(gwi + 1, gwi + n + m + 1, porx);
    auto ans2 = best2(1, n + m);
    swap(gwi[ans2.s], gwi[1]);
    sort(gwi + 2, gwi + n + m + 1, porx);
    ans2.f += best2(2, n + m).f;
    cout << fixed << setprecision(10) << min(ans, ans2.f) / 2;
}