#include <bits/stdc++.h>

using namespace std;

const int r = 1e6 + 9, m = 1e6, mod = 998244353;
int tab[r];
bool pie[r];
long long sil[r];
long long odw[r];
long long nowa[5000];  //ile jest ziomkow na dole
long long stara[5000];

long long szy(long long a, long long w)
{
    if(w == 0)
        return 1;
    if(w % 2 == 0)
    {
        long long b = szy(a, w / 2); 
        return (b * b) % mod;
    }
    return (a * szy(a, w - 1)) % mod;
}

void pre()
{
    pie[1] = 1;
    sil[1] = sil[0] = 1;
    for(int i = 2; i <= m; i++)
    {
        sil[i] = (sil[i - 1] * i) % mod;
        if(pie[i])
            continue;
        for(int j = 2 * i; j <= m; j += i)
        {
            pie[j] = 1;
        }
    }
    odw[m] = szy(sil[m], mod - 2);
    for(int i = m - 1; i >= 0; i --)
        odw[i] = (odw[i + 1] * (i + 1)) % mod;
}

int main()
{
    pre();
    int n, lp = 0;
    cin >> n;
    for(int i = 1; i <= 2 * n; i++)
    {
        int x;
        cin >> x;
        tab[x] ++;
        if(!pie[x])
            lp++;
    }
    if(lp < n)
    {
        cout << "0\n";
        return 0;
    }
    long long wyn = sil[n];
    for(int i = 1; i <= m; i++)
    {
        if(!pie[i] || tab[i] == 0)
            continue;
        wyn = (wyn * odw[tab[i]]) % mod;
    }
    stara[0] = 1;
    for(int i = 1; i <= m; i++)
    {
        if(pie[i] || tab[i] == 0)
            continue;
        nowa[0] = (stara[0] * odw[tab[i]]) % mod;
        for(int j = 1; j <= n; j++)
        {
            nowa[j] = (stara[j] * odw[tab[i]]) % mod;
            nowa[j] = (nowa[j] + stara[j - 1] * odw[tab[i] - 1]) % mod;
        }
        swap(nowa, stara);
    }
    cout << (stara[n] * wyn) % mod;
}