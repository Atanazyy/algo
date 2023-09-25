#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> t1;
        vector <pair<int, int> > t2;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            t1.push_back(x);
            t2.push_back({abs(x), x / abs(x)});
        }
        sort(t1.begin(), t1.end());
        reverse(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        reverse(t2.begin(), t2.end());
        int w = 0;
        for(auto x : t1)
        {
            if(x > 0)
                w++;
            else
                w--;
            cout << w << " ";
        }
        cout << "\n";
        w = 0;
        for(int i = 0; i < n - 1; i++)
        {
            if(t2[i].first == t2[i + 1].first)
                t2[i].first = t2[i + 1].first = n + 1 + i;
        }
        sort(t2.begin(), t2.end());
        reverse(t2.begin(), t2.end());
        for(auto x : t2)
        {
            //cout << x.first;
            w += x.second;
            cout << w << " ";
        }
        cout << "\n";
    }
}