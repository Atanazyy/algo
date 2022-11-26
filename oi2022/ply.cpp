#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int otw = 0, wyn = 0;
    int n, h;
    cin >> n >> h;
    string s;
    cin >> s;
    if(h == 1)
    {
        char o = '(';
        for(int i = 0; i < n; i++)
        {
            char x = s[i];
            if(o != x)
                wyn ++;
            if(o == '(')
                o = ')';
            else
                o = '(';
        }
        cout << wyn;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        char x = s[i];
        if(x == '(')
        {
            if(otw == h)
            {
                otw --;
                wyn += 2;
            }
            else
                otw ++;
        }
        else
        {
            if(otw == 0)
                otw = 1;
            else
                otw --;
        }
    }
    cout << wyn;
}
