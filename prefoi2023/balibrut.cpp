#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector <int> Y;
    for(int i = 0; i < n; i++)
    {
        int y;
        cin >> y;
        Y.push_back(y);
    }
    long long rek = 1e18;
    for(int i = 0; i < (1 << n); i++)
    {
        int x = i, cnt = 0;
        vector <bool> B;
        for(int j = 0; j < n; j++)
        {
            cnt += x % 2;
            B.push_back(x % 2);
            x /= 2;
        }
        if(cnt > b || cnt < a || B[n - 1] == 0)
            continue;
        long long wyn = 0, sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum += Y[i];
            if(B[i])
            {
                wyn = wyn | sum;
                sum = 0;
            }
        }
        rek = min(rek, wyn);
    }
    cout << rek;
}
