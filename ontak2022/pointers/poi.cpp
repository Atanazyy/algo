#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int r = 5e5 + 9; 
map <pair<int, int>, long long> dp;
vector <pair<int, int> > poi;
int ta[r], tb[r];
long long nx[r], ny[r];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> ta[i];
    for(int i = 1; i <= n; i++)
        cin >> tb[i];
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        poi.push_back({x, y});
    }
    sort(poi.begin(), poi.end());
    reverse(poi.begin(), poi.end());
    long long wyn = 0;
    for(auto w : poi)
    {
        dp[{w.f, w.s}] = 0;

        dp[{w.f, w.s}] = max (dp[{w.f, w.s}], nx[w.f] + max(0, tb[w.s]));
        dp[{w.f, w.s}] = max(dp[{w.f, w.s}], ny[w.s] + max(0, ta[w.f]));

        dp[{w.f, w.s}] = max((long long)dp[{w.f, w.s}], (long long) (max(0, tb[w.s]) + max(0, ta[w.f])));

        nx[w.f] = dp[{w.f, w.s}];
        ny[w.s] = dp[{w.f, w.s}];
        wyn = max(wyn, dp[{w.f, w.s}]);
        //cout << w.f << " " << w.s << " " << dp[{w.f, w.s}] << "\n";
    }
    cout << wyn;
}