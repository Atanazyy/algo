#include <bits/stdc++.h>

using namespace std;

const int r = 1e5, inf = 1e9;
int tab[r];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    int a = tab[1];
    int w1 = 0;
    for(int i = 2; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            if(tab[i] >= a)
            {
                w1 ++;
                a = -inf;
            }
            else
                a = tab[i];
        }
        else
        {
            if(tab[i] <= a)
            {
                w1 ++;
                a = inf;
            }
            else
                a = tab[i];
        }
    }
    int w2 = 0;
    a = tab[1];
    for(int i = 2; i <= n; i++)
    {
        if(i % 2 == 1)
        {
            if(tab[i] >= a)
            {
                w2 ++;
                a = -inf;
            }
            else
                a = tab[i];
        }
        else
        {
            if(tab[i] <= a)
            {
                w2 ++;
                a = inf;
            }
            else
                a = tab[i];
        }
    }
    cout << min(w1, w2);
}