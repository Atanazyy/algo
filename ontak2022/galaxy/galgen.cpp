#include <bits/stdc++.h>

using namespace std;

mt19937 r;


int rr(int a, int b)
{
    return a + r() % (b - a + 1);
}


int main()
{
    int seed;
    cin >> seed;
    r.seed(seed);
    int n = rr(2, 5);
    int m = rr(0, 5);
    cout << n << " " << m << "\n";
    while(n--)
        cout << rr(1, 10) << " " << rr(1, 10)<<"\n";
    while(m--)
        cout << rr(1, 10) << " " << rr(1, 10)<<"\n";
}