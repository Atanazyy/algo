#include <bits/stdc++.h>

using namespace std;

const int r = 5e5 + 9;
int tab[r];
bool czy1[r], czy2[r];

int main()
{
    int n, k;
    cin >> n >> k;
    int dk = 1 << k;
    dk--;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    int rek = 1000 * 1000 * 1000;
    int gdz;
    for(int i = 1; i <= n; i++)
    {
        int akt = tab[i] ^ dk;
        akt = abs(akt - tab[i]);
        if(rek > akt)
        {
            rek = akt;
            gdz = i;
        }
    }

    bool c1 = 1;
    int ost = tab[gdz];
    for(int i = gdz - 1; i >= 1; i--)
    {
        int a = tab[i];
        if(ost < a)
        {
            czy1[i] = 1;
            a = a ^ dk;
        }
        if(ost < a)
        {
            c1 = 0;
            break;
        }
        ost = a;
    }
    ost = tab[gdz];
    for(int i = gdz + 1; i <= n; i++)
    {
        int a = tab[i];
        if(ost > a)
        {
            czy1[i] = 1;
            a = a ^ dk;
        }
        if(ost > a)
        {
            c1 = 0;
            break;
        }
        ost = a;
    }
    //for(int i = 1; i <= n; i++)
    //    cout << czy1[i] << " ";

    bool c2 = 1;
    ost = tab[gdz] ^ dk;
    czy2[gdz] = 1;
    for(int i = gdz - 1; i >= 1; i--)
    {
        int a = tab[i];
        if(ost < a)
        {
            czy2[i] = 1;
            a = a ^ dk;
        }
        if(ost < a)
        {
            c2 = 0;
            break;
        }
        ost = a;
    }
    ost = tab[gdz];
    for(int i = gdz + 1; i <= n; i++)
    {
        int a = tab[i];
        if(ost > a)
        {
            czy2[i] = 1;
            a = a ^ dk;
        }
        if(ost > a)
        {
            c2 = 0;
            break;
        }
        ost = a;
    }

    /*cout << "\n";
    for(int i = 1; i <= n; i++)
        cout << czy2[i] << " ";*/

    int w1 = 0, w2 = 0;
    for(int i = 1; i <= n; i++)
    {
        if(czy1[i] == 1 && czy1[i - 1] != 1)
            w1 ++;
        if(czy2[i] == 1 && czy2[i - 1] != 1)
            w2++;
    }
    int wyn = 1000 * 1000 * 1000;
    if(c1)
        wyn = min(wyn, w1);
    if(c2)
        wyn = min(wyn, w2);
    if(wyn == 1000 * 1000 * 1000)
        cout << -1;
    else
        cout << wyn;
}