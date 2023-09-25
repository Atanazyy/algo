#include <bits/stdc++.h>

using namespace std;

const int r = 2e5 + 9;
long long tab[r];

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        priority_queue <long long> kol; 
        int n;
        cin >> n;
        long long wyn = 0;
        for(int i = 0; i < n; i++)
            cin >> tab[i];
        for(int i = n - 1; i >= 0; i--)
        {
            long long x = tab[i];
            if(x == 0)
                kol.push(x);
            else
            {
                if(kol.size() == 0)
                    continue;
                if(x > -kol.top())
                {
                    kol.pop();
                    kol.push(-x);
                }
            }
        }
        while(kol.size() > 0)
        {
            wyn -= kol.top();
            kol.pop();
        }
        cout << wyn << "\n";
    }
}