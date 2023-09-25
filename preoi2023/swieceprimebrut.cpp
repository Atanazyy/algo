#include <bits/stdc++.h>

using namespace std;

bool isprime(int x)
{
    for(int i = 2; i < x; i++)
        if(x % i == 0)
            return 0;
    return 1;
}

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int x;
        cin >> x;
        while(true)
        {
            bool c = 1;
            int zx = x;
            while(zx > 0)
            {
                if(zx % 10 == 0)
                    c = 0;
                zx /= 10;
            }
            if(c)
                if(isprime(x))
                    break;
            x--;
        }
        cout << x << "\n";
    }
}
