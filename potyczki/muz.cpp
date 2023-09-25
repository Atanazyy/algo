#include <bits/stdc++.h>

using namespace std;

int popcnt(int x)
{
    int w = 0;
    while(x > 0)
    {
        w += x % 2;
        x /= 2;
    }
    return w;
}

int main()
{
    int n;
    cin >> n;
    int s = 0;
    int l = 0;
    while(s <= n)
    {
        l ++;
        s += popcnt(l);
    }
    cout << l - 1 << '\n';
    bool f = 0;
    while(l > 0)
    {
        if(s - popcnt(l) != n)
            cout << l << " ";
        else if(f)
            cout << l << " ";
        else
            f = 1;
        l--;
    }

}