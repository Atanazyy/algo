#include <bits/stdc++.h>

using namespace std; 

int main()
{
    string w = "FBFFBFFBFBFFBFFBFBFFBFFBFBFFBFFB";
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool gf = 1;
        for(int i = 0; i < 10; i++)
        {
            bool f = 1;
            for(int j = 0; j < n; j++)
            {
                if(s[j] != w[j + i])
                    f = 0;
            }
            if(f)
            {
                cout << "YES\n";
                gf = 0;
                break;
            }
        }
        if(gf)
            cout << "NO\n";
    }
}