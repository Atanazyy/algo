#include <bits/stdc++.h>

using namespace std;

int nasa[5009][200];
int nasb[5009][200];
int pref[5009][5009];
int suf[5009][5009];
int ost[200];

int main()
{
    string a, b, s;
    cin >> a >> b >> s;
    a = " " + a;
    b = " " + b;
    for(int j = 'a'; j <= 'z'; j++)
        ost[j] = -1;
    for(int i = a.size(); i > 0; i--)
    {
        for(int j = 'a'; j <= 'z'; j++)
            nasa[i][j] = ost[j];
        ost[a[i]] = i;
    }
    for(int j = 'a'; j <= 'z'; j++)
        ost[j] = -1;
    for(int i = b.size(); i > 0; i--)
    {
        for(int j = 'a'; j <= 'z'; j++)
            nasb[i][j] = ost[j];
        ost[b[i]] = i;
    }
    for(int i = 1; i < a.size(); i++)
    {
        for(int j = 1; j < b.size(); j++)
        {
            if(b[j] == a[i]) pref[i][j] = pref[i - 1][j - 1] + 1;
            else pref[i][j] = max(pref[i - 1][j], pref[i][j - 1]);
        }
    }
    for(int i = a.size() - 1; i > 0; i--)
    {
        for(int j = b.size() - 1; j > 0; j--)
        {
            if(b[j] == a[i]) suf[i][j] = pref[i + 1][j + 1] + 1;
            else suf[i][j] = max(suf[i + 1][j], suf[i][j + 1]);
        }
    }
    int rek = 0;
    for(int i = 1; i < a.size(); i++)
    {
        for(int j = 1; j < b.size(); j++)
        {
            
        }
    }
    cout << rek;
}