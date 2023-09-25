#include <bits/stdc++.h>
 
using namespace std;

mt19937 r;
bool indexes[500000 + 10];

int mystralia(string cur)
{
    int m = cur.size();
    int occupied = 0;
    int lights = 0;
    for(int i = 0; i < m; i++)
    {
        indexes[i] = 0;
    }
    int large = m/4;
    if(cur[0] == '1')
    {
        lights++;
    }
    for(int i = 1; i < m; i++)
    {
        if(cur[i] == '1')
        {
            lights++;
        }
        if(((cur[i] == '0' && cur[i - 1] == '1') || (cur[i] == '1' && cur[i - 1] == '0')) && !indexes[i - 1] && large > 0)
        {
            indexes[i] = true;
            indexes[i - 1] = true;
            large--;
            lights-=1;
            occupied++;
        }
        if(cur[i] == '0' && cur[i - 1] == '0' && !indexes[i - 1] && large > 0)
        {
            indexes[i] = true;
            indexes[i - 1] = true;
            large--;
        }
    }
    occupied += lights;
    occupied -= large;
    return occupied;
}

int xd = 0;

string gen(int m)
{
    string s = "";
    int a = xd;
    for(int i = 0; i < m; i++)
    {
        s += '0' + (a % 2);
        a /= 2;
    }
    xd++;
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int m = 12;
    r.seed(m);
    while(true)
    {
        string s;
        s = gen(m);
        //cout << s << "\n";
        int n11 = 0;
        int maxw = 0, minw = 0;
        for(int i = 0; i < m; i++)
        {
            if(i == m - 1)
            {
                if(s[i] == '1')
                    minw++;
                continue;
            }
            if(s[i] == '1' && s[i + 1] == '1' && n11 * 4 < m)
            {
                n11 ++;
                i++;
                minw ++;
            }
            else if(s[i] == '1')
                minw++;
        }
        int n01 = 0;
        int n1 = 0;
        for(int i = 0; i < m; i++)
        {
            if(i == m - 1)
            {
                if(s[i] == '1')
                    maxw++;
                continue;
            }
            if(((s[i] == '0' || s[i + 1] == '0') && (n01 * 4 < m)) || n1 * 2 >= m)
            {
                if(s[i] == '1' || s[i + 1] == '1')
                    maxw ++;
                n01 ++;
                i++;
            }
            else 
            {
                n1++;
                if(s[i] == '1')
                {
                    maxw++;
                }
            }
        }
        cout << mystralia(s) << " " << maxw << " " << s << "\n";
        if(mystralia(s) != maxw)
        {
            
            return 0;
        }
    }
}