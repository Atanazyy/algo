#include <bits/stdc++.h>

using namespace std;

int chk(int l, int r, int x, int rek)
{
    if(x > r)
        return 2;
    int akt = 0;
    int ax = x;
    while(ax <= r)
    {
        akt ++;
        ax *= 2;
    }
    if(akt < rek)
        return 2;
    ax /= 2;
    if(ax == x)
        return 1;
    ax /= 2;
    if(ax * 3 <= r)
        return 0;
    else
       return 1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int l, r;
        cin >> l >> r;
        long long wyn = 0;
        long long rek = 0;
        int x = l;
        while(x <= r)
        {
            rek ++;
            x *= 2;
        }
        int p = l, k = r + 1;
        while(p < k)
        {
            int s = (p + k) / 2;
            int xd = chk(l, r, s, rek);
            if(xd == 0)
                p = s + 1;
            else
                k = s;
        }
        wyn = rek * (k - l);
        int sk = k;
        p = k;
        k = r + 1;
        while(p < k)
        {
            int s = (p + k) / 2;
            int xd = chk(l, r, s, rek);
            if(xd == 1)
                p = s + 1;
            else
                k = s;
        }
        //cout << sk;
        wyn += k - sk;
        cout << rek << " " << wyn % 998244353 << "\n";
    }
}