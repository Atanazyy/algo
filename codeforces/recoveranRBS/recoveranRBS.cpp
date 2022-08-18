#include <bits/stdc++.h>

using namespace std;

struct str
{
    int que;
    int ope;
    int end;
};

const int r = 1e6 + 9;
str tab[r];

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    tab[n] = {0, 0, 0};
    for(int i = n - 1; i >= 0; i--)
    {
        tab[i] = tab[i + 1];
        if(s[i] == '(')
            tab[i].ope++;
        else if(s[i] == ')')
            tab[i].end++;
        else    
            tab[i].que++;
    }
    int cur = 0;
    for(int i = 0; i < n; i++)
    {
        if(s[i] == '(')
            cur++;
        else if(s[i] == ')')
            cur--;
        else    
        {
            if(cur == 0)
            {
                cur++;
                continue;
            }
            int ncur = cur - tab[i].end + tab[i].ope;
            if(abs(ncur) != tab[i].que)
            {
                cout << "NO\n";
                return;
            }
            if(ncur > 0)
                cur--;
            else
                cur++;
        }
    }
    cout << "YES\n";
}

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        solve();
    }
}