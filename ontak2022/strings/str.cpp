#include <bits/stdc++.h>

using namespace std;

const int r = 1e7;
int n, m;
vector <bool> c1, c2;
bool cz1[200];
bool cz2[200];
int wyn[r];

void spr()
{
    /*for(auto x : c1)
        cout << x << " ";
    cout << " # ";
    for(auto x : c2)
        cout << x << " ";
    cout << "\n";*/
    for(int i = 0; i < n - m + 1; i++)
    {
        bool f = 1;
        for(int j = i; j < i + m; j++)
        {
            if(c1[j] != c2[j - i])
            {
                f = 0;
                break;
            }
        }
        if(f)
            wyn[i]++;
    }
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    n = s1.size(), m = s2.size();
    if(n < m)
    {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cz1[s1[i]] = 1;
    for(int i = 0; i < m; i++)
        cz2[s2[i]] = 1;
    int ile;
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(!cz1[i]) 
            continue;
        c1.clear();
        for(auto x : s1)
            if(x == i)
                c1.push_back(1);
            else
                c1.push_back(0);
        ile = 0;
        for(int j = 'a'; j <= 'z'; j++)
        {
            if(!cz2[j]) 
                continue;
            ile ++;
            c2.clear();
            for(auto x : s2)
                if(x == j)
                    c2.push_back(1);
                else
                    c2.push_back(0);
            spr();
        }
    }
    int ost = 0;
    for(int i = 0; i < n; i++)
    {
        if(wyn[i] == ile)
            ost++;
    }
    cout << ost;
}