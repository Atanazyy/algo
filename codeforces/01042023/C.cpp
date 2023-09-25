#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        int n;
        if(i % 2 == 0)
            n = 3;
        else
            n = 2;
        int w = 1;
        while(n--)
        {
            int a;
            cin >> a;
            w *= a;
        }
        cout << w << "\n";
    }
}