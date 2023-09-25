#include <bits/stdc++.h>

using namespace std;

const int r = 4e6 + 9, mod = 1e9 + 7;
long long n2[r], n3[r], sil[r], odw[r];

long long pot(long long pod, long long wyk)
{
    if(wyk == 0)
        return 1;
    if(wyk % 2 == 0)
    {
        long long pol = pot(pod, wyk / 2);
        return (pol * pol) % mod;
    }
    return (pod * pot(pod, wyk - 1)) % mod;
}

long long sym(int a, int b)
{
    return (sil[a] * ((odw[b] * odw[a - b]) % mod) ) % mod;
}

int main()
{
    int n;
    cin >> n;
    n2[0] = n3[0] = sil[0] = odw[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        n2[i] = (n2[i - 1] * 2) % mod;
        n3[i] = (n3[i - 1] * 3) % mod;
        sil[i] = (sil[i - 1] * i) % mod;
    }
    odw[n] = pot(sil[n], mod - 2);
    for(int i = n - 1; i >= 1; i--)
        odw[i] = (odw[i + 1] * (i + 1)) % mod;
    if(n % 2 == 1)
    {
        cout << n3[n];
        return 0;
    }
    long long wyn = 0;
    for(int i = 0; i < n / 2; i++)
        wyn = (wyn + ((n2[n - i] * sym(n, i)) % mod)) % mod;
    cout << wyn;
}