#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

void solve(int n)
{
    long long wyn = 0;
    vector <pair<int, int> > v;
    vector <int> kan;
    for(int i = 0; i < n; i++)
    {
        int x1, x2;
        char c1, c2;
        cin >> c1 >> x1 >> c2 >> x2;
        if(c1 == c2)
            wyn += abs(x1 - x2);
        else
        {
            wyn ++;
            v.push_back({x1, x2});
            kan.push_back(x1);
            kan.push_back(x2);
        }
    }
    long long rek = 1e18;
    for(auto m1 : kan)
    {
        for(auto m2 : kan)
        {
            long long akt = 0;
            for(auto x : v)
            {
                akt += min(abs(x.f - m1) + abs(x.s - m1), abs(x.f - m2) + abs(x.s - m2));
            }
            rek = min(rek, akt + wyn);
        }
    }
    if(v.size() >= 1)
        cout << rek;
    else
        cout << wyn;
}

int main()
{
    int k, n;
    cin >> k >> n;
    if(k == 2)
    {
        solve(n);
        return 0;
    }
    long long wyn = 0;
    vector <int> v;
    for(int i = 0; i < n; i++)
    {
        int x1, x2;
        char c1, c2;
        cin >> c1 >> x1 >> c2 >> x2;
        if(c1 == c2)
            wyn += abs(x1 - x2);
        else
        {
            v.push_back(x1);
            v.push_back(x2);
            wyn ++;
        }
    }
    sort(v.begin(), v.end());
    long long akt = 0;
    for(int i = 0; i < (int)v.size(); i++)
        akt += abs(v[0] - v[i]);
    long long cntl = 0;
    long long rek = akt;
    for(int i = 1; i < (int)v.size(); i++)
    {
        cntl ++;
        akt += cntl * (v[i] - v[i - 1]);
        akt -= (v.size() - cntl) * (v[i] - v[i - 1]);
        rek = min(rek, akt);
    }
    cout << rek + wyn;
}
