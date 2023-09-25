#include <bits/stdc++.h>
#include "spolib.h"

using namespace std;

int tab[10];
set <vector<int> > s;

int main()
{
    int n = 2 * init();
    for(int i = 0; i < (1 << n); i++)
    {
        int l = i;
        vector<int> v;
        vector<int> w;
        for(int j = 1; j <= n; j++)
        {
            if(l % 2)
                v.push_back(j);
            else
                w.push_back(j);
            l /= 2;
        }
        if((v.size() == n / 2) && s.find(v) == s.end() && s.find(w) == s.end())
        {
            s.insert(v);
            s.insert(w);
            char c;
            c = ask(v);
            for(auto x : v)
                if(c == 'H')
                    tab[x] ++;
                else
                    tab[x] --;
            for(auto x : w)
                if(c == 'P')
                    tab[x] ++;
                else
                    tab[x] --;
        }
    }
    string s = "";
    for(int i = 1; i <= n; i++)
        if(tab[i] > 0)
            s += "H";
        else
            s += "P";
    answer(s);
}
