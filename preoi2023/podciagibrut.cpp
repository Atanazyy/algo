#include <bits/stdc++.h>

using namespace std;

const int r = 5e5 + 9;
int tab[r];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> tab[i];
    set <vector<int> > cnt;
    for(int i = 0; i < (1 << n); i++)
    {
        vector<int> cur;
        int x = i;
        for(int j = 1; j <= n; j++)
        {
            if(x % 2)
                cur.push_back(tab[j]);
            x /= 2;
        }
        cnt.insert(cur);
    }
    cout << cnt.size();
}
