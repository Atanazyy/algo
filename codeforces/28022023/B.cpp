#include <bits/stdc++.h>

using namespace std; 

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        if(a[0] == b[0])
        {
            cout << "YES\n" << a[0] << "*\n";
            continue;
        }
        if(a[n - 1] == b[m - 1])
        {
            cout << "YES\n*" << a[n - 1] << "\n";
            continue;
        }
        bool z = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(z)
                break;
            for(int j = 0; j < m - 1; j++)
            {
                if(a[i] == b[j] && a[i + 1] == b[j + 1])
                {
                    cout << "YES\n*" << a[i] << a[i + 1] << "*\n";
                    z = 1;
                    break;
                }
            }
        }
        if(!z)
        {
            cout << "NO\n";
        }
    }
}