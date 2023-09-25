#include <bits/stdc++.h>

using namespace std;

mt19937 r;

int rr(int a, int b)
{
    return a + (r() % (b - a + 1));
}

int main()
{
    int s;
    cin >> s;
    r.seed(s);
    cout << rr(1, 10) << " " << rr(1, 10) << "\n";
}
