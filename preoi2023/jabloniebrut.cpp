#include <bits/stdc++.h>

using namespace std;

const int r = 5e5 + 9;
int tab[r];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    sort(tab + 1, tab + n + 1);
    while(m--)
    {
        string z;
        cin >> z;
        if(z[0] == 'p')
        {
            int x;
            cin >> x;
            for(int i = 1; i <= x; i++)
                tab[i]++;
            sort(tab + 1, tab + n + 1);
        }
        else
        {
            int a, b, wyn = 0;
            cin >> a >> b;
            for(int i = 1; i <= n; i++)
                if(tab[i] >= a && tab[i] <= b)
                    wyn ++;
            cout << wyn << "\n";
        }
    }
}
