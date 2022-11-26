#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int mod = 1e9 + 7, r = 1e6 + 9;
pair<long long, long long> dp[r];

int main()
{
    int n;
    cin >> n;
    if(n == 1)
    {
        cout << 2;
        return 0;
    }
    dp[0] = {0, 1};
    dp[1] = {0, 1};
    dp[2] = {4 , 2};
    for(int i = 3; i <= n; i++)
    {
        dp[i].f = ((dp[i - 1].f + dp[i - 1].s) * 2 + (dp[i - 2].f + dp[i - 2].s) * 4) % mod;
        dp[i].s = (dp[i - 2].s * 4) % mod; 
        cout << i << " " << dp[i].f << " " << dp[i].s << "\n";
    }
    long long wyn = (4 * (dp[n].f + dp[n].s)) % mod;
    for(int i = 2; i <= n - 1; i++)
    {
        long long add = ((dp[i - 1].f + dp[i - 1].s) * dp[n - i + 1].s + dp[i].s * (dp[n - i].f + dp[n - i].s)) % mod;
        cout << n - i + 1 << " " << i - 1 << "\n";
        cout << i << " " << n - i << "\n";
        //cout << add << "\n";
        wyn = (wyn + 4 * add) % mod;
    }
    cout << wyn;
}