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
        vector <string> c;
        for(int i = 0; i < 2 * n - 2; i++)
        {
            string s;
            cin >> s;
            if((int)s.size() == n - 1)
            {
                c.push_back(s);
            }
        }
        //cout << c.size();
        //cout << c[0] << " " << c[1] <<"\n";
        reverse(c[0].begin(), c[0].end());
        bool f = 1;
        for(int i = 0; i < n - 1; i++)
            if(c[0][i] != c[1][i])
                f = 0;
        if(f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}