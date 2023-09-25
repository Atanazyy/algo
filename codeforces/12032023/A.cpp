#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        a = abs(a);
        b = abs(b);
        if(a == b)
        {
            cout << a + b << "\n";
            continue;
        }
        int na = max(a, b);
        int nb = min(a, b);
        int wyn = 2 * nb;
        na -= nb;
        wyn += 2 * na - 1;
        cout << wyn << "\n";
    }
}