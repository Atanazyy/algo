#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        vector <int> v;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        bool f = 0;
        for(auto x : v)
            for(auto y : v)
                if(__gcd(x, y) <= 2)
                    f = 1;
        if(f)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}