#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        long long n, m;
        cin >> n>> m;
        cout << n * m << "\n";
        for(long long i = 1; i <= n; i ++)
        {
            for(long long j = 1; j <= m; j ++)
                cout << ((i << 30) + j) << " ";
            cout << "\n";
        }
    }
}