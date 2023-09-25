#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long

using namespace std;

const ll p1 = 313, p2 = 997, m1 = 1e9 + 7, m2 = 1e9 + 9;

set <pair<pair <ll, ll> , pair<ll, ll> > > pre;
set <pair<ll, ll> > suf;
set<pair<ll, ll> > wyn;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ll h1 = 0, h2 = 0;
        ll d1 = 1, d2 = 1;
        for(auto x : s)
        {
            h1 = (h1 + x * d1) % m1;
            h2 = (h2 + x * d2) % m2;
            d1 = (d1 * p1) % m1;
            d2 = (d2 * p2) % m2;
            //cout << h1 << " " << h2 << "\n";
            pre.insert({{d1, d2}, {h1, h2}});
        }
        wyn.insert({h1, h2});
        reverse(s.begin(), s.end());
        h1 = h2 = 0;
        d1 = d2 = 1;
        for(auto x : s)
        {
            h1 = (h1 * p1 + x) % m1;
            h2 = (h2 * p2 + x) % m2;
            suf.insert({h1, h2});
            //cout << h1 << " " << h2 << "\n";
        }
    }
    for(auto x : pre)
        for(auto y : suf)
        {
            //cout << x.s.f << " " << x.s.s << " " << y.f << " " << y.s << "\n";
            wyn.insert({(x.s.f + y.f * x.f.f) % m1, (x.s.s + y.s * x.f.s) % m2});
        }
    cout << wyn.size();
}
