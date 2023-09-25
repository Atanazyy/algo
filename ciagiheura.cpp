#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long wyn = 0;
    int ost = -1;
    int ile = 0;
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if(a > b)
        {
            if(ile == 2 && ost == 0)
            {
                wyn += b;
                ile = 1;
                ost = 1;
            }
            else
            {
                wyn += a;
                if(ost == 0)
                    ile++;
                else
                    ile = 1;
                ost = 0;
            }
        }
        else
        {
            if(ile == 2 && ost == 1)
            {
                wyn += a;
                ile = 1;
                ost = 0;
            }
            else
            {
                wyn += b;
                if(ost == 1)
                    ile ++;
                else
                    ile = 1;
                ost = 1;
            }
        }
    }
    cout << wyn;
}