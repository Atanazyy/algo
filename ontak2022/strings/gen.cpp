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
    int m = rr(1, 1000000);
    //int n = rr(m, 1000);
    string s = "";
    for(int i = 0; i < m; i++)
       s += (char)(rr('a', 'z'));
    cout << s << "\n" << s;
}