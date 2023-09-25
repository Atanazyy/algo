#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const long long p = 997, q = 313, m = 1e9 + 7, o = 1e9 + 9;
map <pair<long long , long long> , pair<int, int> > wie;
queue <pair<long long, long long> > kol;

long long szyp(int w)
{
    if(w == 0)
        return 1;
    if(w % 2 == 0)
    {
        long long x = szyp(w / 2);
        return (x * x) % m;
    }
    return (szyp(w - 1) * p) % m;
}

long long szyo(int w)
{
    if(w == 0)
        return 1;
    if(w % 2 == 0)
    {
        long long x = szyo(w / 2);
        return (x * x) % o;
    }
    return (szyo(w - 1) * q) % o;
}

long long hasz1(string s)
{
    long long wyn = 0;
    long long mp = 1;
    for(int i = 0; i < (int)s.size(); i++)
    {
        wyn = (wyn + s[i] * mp) % m;
        mp = (mp * p) % m;
    }
    return wyn;
}

long long hasz2(string s)
{
    long long wyn = 0;
    long long mp = 1;
    for(int i = 0; i < (int)s.size(); i++)
    {
        wyn = (wyn + s[i] * mp) % o;
        mp = (mp * q) % o;
    }
    return wyn;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int rek = 0;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        pair<long long, long long> h = {hasz1(s), hasz2(s)};
        //cout << h << "\n";
        wie[h].f = s.size();
        wie[h].s ++;
        if(wie[h].s >= 2)
            kol.push(h);
        rek = max(rek, (int)s.size());
    }
    while(!kol.empty())
    {
        pair<long long, long long> sh = kol.front();
        kol.pop();
        if(wie[sh].s < 2)
            continue;
        pair<long long, long long> nh = {(sh.f + szyp(wie[sh].f) * sh.f) % m, (sh.s + szyo(wie[sh].f) * sh.s) % o};
        //cout << sh << " " << nh << "\n";
        wie[nh].s += wie[sh].s / 2;
        wie[sh].s = wie[sh].s % 2;
        wie[nh].f = wie[sh].f * 2;
        rek = max(rek, wie[nh].f);
        if(wie[nh].s >= 2)
            kol.push(nh);
    }
    cout << rek;
}