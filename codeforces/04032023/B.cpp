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
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if(x == 1)
                x++;
            v.push_back(x);
        }
        for(int i = 0; i < n - 1; i++)
        {
            if(v[i + 1] % v[i] == 0)
                v[i + 1] ++;
        }
        for(int i = 0; i < n; i++)
            cout << v[i] << " ";
        cout <<"\n"; 
    }
}