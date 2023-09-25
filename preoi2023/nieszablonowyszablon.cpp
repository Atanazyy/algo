#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9, p = 1e9 + 7;
int P[r];
long long dp[r];
vector<int> prz;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    for(int i = 1; i < n; i++)
    {
        int j = P[i - 1];
        while(j > 0 && s[j] != s[i])
            j = P[j - 1];
        if(s[i] == s[j])
            j++;
        P[i] = j;
    }
    int j = n;
    while(j > 0)
    {
        j = P[j - 1];
        prz.push_back(n - j);
        //cout << n - j << " ";
    }
    dp[n] = 1;
    for(int i = n; i <= k; i++)
    {
        //cout << i << " " << dp[i] << "\n";
        for(auto x : prz)
        {
            if(i + x > k)
                break;
            dp[i + x] = (dp[i + x] + dp[i]) % p;
        }
    }
    cout << dp[k];
}
