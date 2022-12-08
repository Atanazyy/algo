#include <bits/stdc++.h>

using namespace std;

const long long p = 997, m = 1e9 + 7;
map <long long, pair<int, int> > wie;

long long szy(int w)
{
    if(w == 0)
        return 1;
    if(w % 2 == 0)
    {
        long long x = szy(w / 2);
        return (x * x) % m
    }
    return (szy(w - 1) * p) % m;
}

long long hasz(string s)
{
    long long wyn = 0;
    long long mp = 1;
    for(int i = 0; i < s.size(); i++)
    {
        wyn = (wyn + s[i] * mp) % m;
        mp = (mp * p) % m;
    }
    return wyn;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        string s;
        cin >> s;

    }
}