#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, k, d, w;
        cin >> n >> k >> d >> w;
        int zos = 0;
        int waz = -1;
        int wyn = 0;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if(waz >= x && zos > 0)
                zos--;
            else
            {
                wyn ++;
                zos = k - 1;
                waz = x + w + d;
            }
        }
        cout << wyn << '\n';
    }
}