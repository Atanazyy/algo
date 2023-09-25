#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool f = 1;
        if(s.size() < 4)
            f = 0;
        if(s[0] != 'm' && s[0] != 'M')
            f = 0;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == 'm' || s[i] == 'M')
            {
                if(s[i - 1] != 'm' && s[i - 1] != 'M')
                    f = 0;
            }
            else if(s[i] == 'e' || s[i] == 'E')
            {
                if(s[i - 1] != 'm' && s[i - 1] != 'M' && s[i - 1] != 'E' && s[i - 1] != 'e')
                    f = 0;
            }
            else if(s[i] == 'o' || s[i] == 'O')
            {
                if(s[i - 1] != 'o' && s[i - 1] != 'O' && s[i - 1] != 'E' && s[i - 1] != 'e')
                    f = 0;
            }
            else if(s[i] == 'w' || s[i] == 'W')
            {
                if(s[i - 1] != 'o' && s[i - 1] != 'O' && s[i - 1] != 'W' && s[i - 1] != 'w')
                    f = 0;
            }
            else
                f = 0;
        }
        if(f && (s[n - 1] == 'w' || s[n - 1] == 'W'))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}