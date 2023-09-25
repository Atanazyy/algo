#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        string s;
        cin >> n >> s;
        int p = 0, k = n - 1;
        vector <int> z;
        while(p < k)
        {
            if(s[p] != s[k])
                z.push_back(p);
            p++;
            k--;
        }
        sort(z.begin(), z.end());
        bool f = 1;
        for(int i = 1; i < z.size(); i++)
            if(z[i] != z[i - 1] + 1)
                f = 0;
        if(f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}