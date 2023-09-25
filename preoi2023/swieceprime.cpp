#include <bits/stdc++.h>

using namespace std;

long long prz(long long x)
{
    while(true)
    {
        long long zx = x;
        vector <int> l;
        int g = -1;
        while(zx > 0)
        {
            l.push_back(zx % 10);
            if(zx % 10 == 0)
                g = l.size();
            zx /= 10;
        }
        if(g == -1)
            return x;
        reverse(l.begin(), l.end());
        for(int j = l.size() - g; j < (int)l.size(); j++)
            l[j] = 0;
        long long mn = 1;
        x = 0;
        for(int j = l.size() - 1; j >= 0; j--)
        {
            x += mn * l[j];
            mn *= 10;
        }
        x--;
    }
}

bool isprime(long long x)
{
    if(x == 2 || x == 3)
        return 1;
    for(long long i = 2; i <= ceil(sqrt(x)); i++)
        if(x % i == 0)
            return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        while(true)
        {
            x = prz(x);
            if(isprime(x))
            {
                cout << x <<"\n";
                break;
            }
            x--;
        }
    }
}
