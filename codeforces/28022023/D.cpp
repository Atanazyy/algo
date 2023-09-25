#include <bits/stdc++.h>

using namespace std;

long long stara[25], nowa[25];
const long long inf = 1e18;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        long long x;
        cin >> n >> k >> x;
        vector <long long> tab;
            for(int i = 1; i <= k; i++)
                stara[i] = -inf;
            stara[0] = 0;
            for(int i = 0; i < n; i++)
            {
                int a;
                cin >> a;
                tab.push_back(a);
            }
            long long wyn = 0;
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j <= k; j++)
                    nowa[j] = -inf;
                for(int j = 0; j <= min(i, k); j++)
                    stara[j] = max(stara[j], (long long)0);
                for(int j = 0; j <= k; j++)
                {
                    nowa[j] = max(nowa[j], stara[j] + tab[i] - x);
                    nowa[j + 1] = max(nowa[j + 1], stara[j] + tab[i] + x);
                }
                for(int j = 0; j + i < n; j++)
                {
                    if(k - j < 0)
                        break;
                    wyn = max(wyn, nowa[k - j]);
                }
                swap(nowa, stara);
                /*for(int j = 0; j <= k; j++)
                    cout << stara[j] << " ";
                cout << '\n';*/
            }
            cout <<wyn << "\n";
        
    }
}