#include <bits/stdc++.h>

using namespace std;

mt19937 r;

int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}

int main()
{
    int s;
    cin >> s;
    r.seed(s);
    int n = rr(1, 20), m = rr(1, 20);
    cout << n << " " << m << "\n";
    for(int i = 0; i < n; i++)
        cout << rr(0, 5) << " ";
    cout << "\n";
    while(m--)
    {
        bool c = rr(0, 1);
        if(c)
            cout << "podlej " << rr(0, n) << "\n";
        else
        {
            int p = rr(0, 5);
            int k = rr(p , 5);
            cout << "zbieraj " << p << " " << k << "\n";
        }
    }
}
