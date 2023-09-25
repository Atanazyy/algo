#include <bits/stdc++.h>
#define f first
#define s second
#define ll long long

using namespace std;

vector<pair<ll, ll> > v;
unordered_set <pair<ll, ll> > s;

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for(auto x : v)
        for(auto y : v)
            for(auto z : v)
            {

            }
}
