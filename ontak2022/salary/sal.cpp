#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
long long maxw = 2e18 + 9;
int tab[r];
int n;

long long ile(long long x, long long k)
{
    long long wyn = 0;
    int s;
    if(n % 2)
        s = (n + 1) / 2;
    else
        s = (n + 2) / 2;
    //cout << s;
    for(int i = s; i <= n; i++)
    {
        wyn += max((long long)0, x - tab[i]);
        if(wyn > k)
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    long long k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    long long poc = 0;
    long long kon = maxw;
    sort(tab + 1, tab + n + 1);
    /*for(int i = 1; i <= 10; i++)
    {
        cout << i << " " << ile(i, k) << "\n";
    }*/
    while(poc < kon)
    {
        //cout << poc << " " << kon << "\n";
        long long sr = (poc + kon) / 2;
        if(ile(sr, k))
            poc = sr + 1;
        else
            kon = sr;
    }
    cout << kon - 1;
}