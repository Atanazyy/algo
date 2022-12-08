#include <bits/stdc++.h>

using namespace std;

struct sme
{
    int l, w, h;
};

const int maxw = 1e8 + 10;
vector <sme> wsz;
int dp[maxw + 10];

bool por(sme x, sme y)
{
    return x.w > y.w;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, d;
    cin >> n >> d;
    for(int i = 0; i < n; i++)
    {
        sme xd;
        cin >> xd.l >> xd.w >> xd.h;
        wsz.push_back(xd);
    }
    sort(wsz.begin(), wsz.end(), por);
    int wyn = 0;
    int supermax = 0;
    int kiedy = maxw;
    for(auto x : wsz)
    {
        for(int i = x.w - 1; i >= 0; i--)
            dp[i] = max(dp[i], x.h);
        for(int i = x.w + 1; i <= min(2 * x.w, maxw); i++)
        {
            dp[min(x.w - 1, i - x.w)] = max(dp[min(x.w - 1, i - x.w)], x.h + dp[i]);
            dp[min(x.w - 1, i - x.w)] = min(dp[min(x.w - 1, i - x.w)], maxw);
        }
        for(int i = x.w * 2; i <= kiedy; i++)
        {
            supermax = max(supermax, dp[i] + x.h);
            supermax = min(supermax, maxw);
        }
        dp[x.w - 1] = max(dp[x.w - 1], supermax);
        kiedy = min(2 * x.w, maxw);
        if(d < dp[x.w] + x.l)
            wyn++;
    }
    cout << n - wyn;
}