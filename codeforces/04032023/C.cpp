#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> tab;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            tab.push_back(x);
        }
        int p = 0;
        for(int i = 0; i < n; i++)
        {
            while(p < i)
            {
                if(tab[p] < i - p + 1)
                    p++;
                else
                    break;
            }
            cout << i - p + 1 << " ";
        }
        cout << "\n";
    }
}