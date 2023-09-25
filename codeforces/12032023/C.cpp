#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, x, p;
        cin >> n >> x >> p;
        bool c = 0;
        for(long long i = 1; i <= min(2 * n, p); i++)
        {
            long long s = i * (i + 1);
            s = s / 2;
            s = s + x;
            if(s % n == 0)
                c = 1;
        }
        if(c)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}