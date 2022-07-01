#include <bits/stdc++.h>

using namespace std;

struct kom
{
    int wp, wn, mp, mn;
};

const int inf = 1e9, r = 1e5;
int a[r], w[r];
kom dp[21][21];

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= 20; i++)
        for(int j = 1; j <= 20; j++)
            dp[i][j] = {-inf, -inf, -inf, -inf};
    int wyn = -inf;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < n; i++)
        cin >> w[i];
    for(int i = 0; i < n; i++)
    {
        for(int s = 1; s <= 20; s++)
        {
            for(int e = 1; e <= 20; e++)
            {
                if(a[i] < e) 
                    dp[s][a[i]].mn = max(dp[s][a[i]].mn, dp[s][e].wp + w[i]);
                if(a[i] < e)
                {
                    if(a[i] < s) wyn = max(wyn, dp[s][e].wn + w[i]);
                    dp[s][a[i]].mp = max(dp[s][a[i]].mp, dp[s][e].wn + w[i]);
                }
                if(a[i] > e) 
                    dp[s][a[i]].wn = max(dp[s][a[i]].wn, dp[s][e].mp + w[i]);
                if(a[i] > e) 
                {
                    if(a[i] > s) wyn = max(wyn, dp[s][e].mn + w[i]);
                    dp[s][a[i]].wp = max(dp[s][a[i]].wp, dp[s][e].mn + w[i]);
                }
            }
        }
        dp[a[i]][a[i]].mn = max(dp[a[i]][a[i]].mn, w[i]);
        dp[a[i]][a[i]].wn = max(dp[a[i]][a[i]].wn, w[i]);
        /*for(int s = 1; s <= 20; s++)
            for(int e = 1; e <= 20; e++)
            {
                if(dp[s][e].mn > -inf + r) cout << s << " " << e << " " << " " << "mn " << dp[s][e].mn << "\n";
                if(dp[s][e].mp > -inf + r) cout << s << " " << e << " " << " " << "mp " << dp[s][e].mp << "\n";
                if(dp[s][e].wp > -inf + r) cout << s << " " << e << " " << " " << "wp " << dp[s][e].wp << "\n";
                if(dp[s][e].wn > -inf + r) cout << s << " " << e << " " << " " << "wn " << dp[s][e].wn << "\n";
            } 
        cout << "\n###########\n";*/
    }
    if(wyn > -(int)1e8) 
        cout << wyn;
    else
        cout << "NO";
}