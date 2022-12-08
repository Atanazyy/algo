#include <bits/stdc++.h>
using namespace std;

const int r = 5e5, mod = 1e9 + 7;
long long sil[r + 9], odw[r + 9];

long long kom(int n, int m)
{
    long long wyn = (sil[n] * odw[m]) % mod;
    return (wyn * odw[n - m]) % mod;
}

long long pot(long long a, long long b)
{
    if(b == 0)
        return 1;
    if(b % 2 == 0)
    {
        long long xd = pot(a, b / 2);
        return (xd * xd) % mod;
    }
    return (a * pot(a, b - 1)) % mod;
}

int main()
{
    int n, d, k;
    cin >> n >> d >> k;
    sil[0] = 1;
    for(int i = 1; i <= r; i++)
        sil[i] = (i * sil[i - 1]) % mod;
    odw[r] = pot(sil[r], mod - 2);
    for(int i = r - 1; i >= 0; i--)
        odw[i] = (odw[i + 1] * (i + 1)) % mod;
    long long wyn = (pot(n, d) - pot(k, d) + mod) % mod;
    cout << (wyn * pot(pot(n, d), mod - 2)) % mod << "\n";
    for(int i = d + 1; i <= n; i++)
    {
        long long odj = (kom(i - 1, d - 1) * pot(k, d)) % mod;
        odj = (odj * pot(n - k, i - d)) % mod;
        long long dru = pot(pot(n, i), mod - 2);
        wyn = (n * wyn) % mod;
        wyn = (wyn + mod - odj) % mod;
        cout << (wyn * dru) % mod << "\n";
    }
}