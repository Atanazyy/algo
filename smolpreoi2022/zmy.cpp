#include <bits/stdc++.h>
#define LL long long
using namespace std;

const int r = 2e5 + 9;
int n;
LL k;
int tab[r];

bool czy(LL x)
{
    LL kos = 0;
    for(int i = ceil((double)(n + 1) / 2) - 1; i < n; i++)
    {
        kos += max((LL)0, x - tab[i]);
        if(kos > k)
            return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> tab[i];
    sort(tab, tab + n);
    LL poc = 0, kon = 2e18 + 9;
    while(poc < kon)
    {
        LL sr = (poc + kon) / 2;
        if(czy(sr))
            poc = sr + 1;
        else
            kon = sr;
    }
    cout << poc - 1 - tab[(int)ceil((double)(n + 1) / 2) - 1];
}