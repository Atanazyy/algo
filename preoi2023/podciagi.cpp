#include <bits/stdc++.h>

using namespace std;

const long long r = 1e6 + 9, p = 1e9 + 7;
long long odj[r];

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    long long sum = 1;
    for(int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;
        long long w = (sum - odj[a] + p)% p;
        odj[a] = (odj[a] + w) % p;
        sum = (sum + w) % p;
    }
    cout << sum;
}
