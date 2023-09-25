#include <bits/stdc++.h>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while(q--)
    {
        long long n;
        cin >> n;
        long long r = n % 6;
        if(r == 0 || r == 1)
            cout << "Bajtomir\n";
        if(r == 2 || r == 5)
            cout << "Remis\n";
        if(r == 3 || r == 4)
            cout << "Bajtosz\n";
    }
}