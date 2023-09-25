#include <bits/stdc++.h>

using namespace std;

int tab[300];

int main()
{
    int d = 'a' - 'A';
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        string s;
        cin >> n >> k >> s;
        for(int i = 0; i < 300; i++)
            tab[i] = 0;
        for(auto x : s)
            tab[x]++;
        int wyn = 0;
        for(int i = 'A'; i <= 'Z'; i++)
        {
            int bz = min(tab[i], tab[i + d]);
            wyn += bz;
            tab[i] -= bz;
            tab[i + d] -= bz;
            int zos = tab[i] + tab[i + d];
            int now = zos / 2;
            wyn += min(now, k);
            k -= min(now, k);
        }
        cout << wyn << "\n";
    }
}