#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
long long tab[r];
int N, K;
long long dp[r][4];
deque <long long> s[3];

void rem(int i, int j)
{
    if(i < 0)
        return;
    if (!s[j].empty() && s[j].front() == dp[i][j])
        s[j].pop_front();
}

void add(int i, int j)
{
    while (!s[j].empty() && s[j].back() > dp[i][j])
        s[j].pop_back();
    s[j].push_back(dp[i][j]);
}

bool czy(int d)
{
    for(int j = 0; j < 3; j++)
        s[j].clear();
    for(int j = 0; j < 3; j++)
        s[j].push_front(0);
    for(int i = 1; i <= N + 1; i++)
    {
        for(int j = 0; j <= 3; j++)
            dp[i][j] = dp[i - 1][j] + tab[i];
        for(int j = 1; j <= 3; j++)
            dp[i][j] = min(dp[i][j], s[j - 1].front() + tab[i]);
        for(int j = 0; j < 3; j++)
        {
            rem(i - d, j);
            add(i, j);
        }
        /*for(int j = 0; j <= 3; j++)
            cout << dp[i][j] << " ";
        cout << "\n";*/
    }
    for(int j = 0; j <= 3; j++)
        if(dp[N + 1][j] <= K)
            return 1;
    return 0;
}

int main()
{
    cin >> N >> K;
    for(int i = 1; i <= N; i++)
        cin >> tab[i];
    //czy(2);
    int p = 0, k = N + 3;
    while(p < k)
    {
        int sr = (p + k) / 2;
        if(!czy(sr))
            p = sr + 1;
        else
            k = sr;
    }
    cout << p;
}