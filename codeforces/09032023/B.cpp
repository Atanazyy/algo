#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        double x = 0, y = 0;
        int w = 0;
        while(n--)
        {
            int a;
            cin >> a;
            if(a == 1)
            {
                x++;
            }
            else
            {
                y += x;
                x = 0;
            }
            int ty = y;
            if(ty == 0)
                w = max(w, (int)x);
            else
                w = max(w, (int)((floor(ty / 2) + 1) + x));
        }
        cout << w << "\n";
    }
}