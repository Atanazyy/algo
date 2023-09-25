#include <bits/stdc++.h>

using namespace std;

const int r = 5e5 + 9;
int tab[r];
int ma[r];
int mi[r];
bool zap[r];

void check(int n, int k)
{
    cout << "TAK\n";
    int l = 0;
    for(int i = 1; i <= n; i++)
        if(zap[i])
            l++;
    if(l != k - 1)
        cout << "XD";
    int mip = 0;
    int mid = tab[1];
    bool f = 1;
    bool mf = 1;
    for(int i = 1; i <= n; i++)
    {
        if(tab[i] > mip)
            mf = 0;
        if(tab[i] > mip && tab[i] < mid)
            mid = mip;
        if(zap[i] || i == n)
        {
            f = f & mf;
            mid = zap[i + 1];
            mf = 1;
        }
    }
    if(f == 1)
    {
        for(int i = 1; i <= n; i++)
            if(zap[i])
                cout << i << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    if(k == 2)
    {
        mi[1] = tab[1];
        ma[n] = tab[n];
        for(int i = 2; i <= n; i++)
            mi[i] = min(mi[i - 1], tab[i]);
        for(int i = n - 1; i >= 1; i--)
            ma[i] = max(ma[i + 1], tab[i]);
        for(int i = 1; i <= n - 1; i++)
            if(mi[i] >= ma[i + 1])
            {
                //cout << "TAK\n" << i;
                zap[i] = 1;
                check(n, k);
                return 0;
            }
        cout << "NIE\n";
        return 0;
    }
    if(k == 3)
    {
        int minw = tab[1], maxw = tab[1], minp = 1, maxp = 1;
        for(int i = 2; i <= n; i++)
        {
            if(tab[i] <= minw)
            {
                minw = tab[i];
                minp = i;
            }
            if(tab[i] > maxw)
            {
                maxw = tab[i];
                maxp = i;
            }
        }
        if(minp != 1)
        {
            if(minp != n) cout << "TAK\n" << minp - 1 << " " << minp;
            else cout << "TAK\n" << 1 << " " << minp - 1;
            zap[minp - 1] = 1;
            zap[minp] = 1;
        }
        else if(maxp != n)
        {
            //cout << "TAK\n" << maxp - 1 << " " << maxp;
            zap[maxp - 1] = 1;
            zap[maxp] = 1;
        }
        else
        {
            cout << "NIE\n";
            return 0;
        }
        check(n, k);
        return 0;
    }
    int poz = -1;
    for(int i = 1; i <= n - 1; i++)
        if(tab[i] >= tab[i + 1])
            poz = i;
    if(poz == -1)
    {
        cout << "NIE\n";
        return 0;
    }
    int cnt = 3;
    poz--;
    zap[poz - 1] = zap[poz] = zap[poz + 1] = 1;
    if(poz + 1 == n)
    {
        cnt --;
        zap[n] = 0;
    }
    int w = 1;
    while(cnt < k - 1)
    {
        if(!zap[w])
        {
            cnt ++;
            zap[w] = 1;
        }
        w ++;
    }
    //cout << "TAK\n";
    /*for(int i = 1; i <= n; i++)
    {
        if(zap[i])
            cout << i << " ";
    }*/
    check(n, k);
}