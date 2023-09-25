#include <bits/stdc++.h>

using namespace std;

mt19937_64 r;

long long rr(long long a, long long b)
{
    return a + (r() % (b - a + 1));
}

int main()
{
    int s;
    cin >> s;
    r.seed(s);
    int n = rr(1, 10);
    cout << n << "\n";
    while(n--)
        cout << rr(2, 1e13) << "\n";
}
