#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, w = 0;
    cin >> n;
    int p = n / 10;
    string s;
    cin >> s;
    for(int i = 0; i < 10; i++)
    {
        int f = 1;
        for(int j = i * p; j < (i + 1) * p; j++)
            if(s[j] == 'N')
                f = 0;
        w += f;
    }
    cout << w;
}