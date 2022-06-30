#pragma GCC optimize("Ofast,inline") // Ofast = O3,fast-math,allow-store-data-races,no-protect-parens                                                                                                                                           
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")                      // bit manipulation                                                                            
#pragma GCC target("movbe")                                      // byte swap   
#pragma GCC target("aes,pclmul,rdrnd")                           // encryption  
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2") // SIMD
#include <bits/stdc++.h>

using namespace std;

const int r = 1e7;
int n, m;
int kmp[r];
bool cz1[200];
bool cz2[200];
int wyn[r];
int P[r];

void spr()
{
     /*for (int i = 0; i < n + m + 1; i++) 
        cout << kmp[i] << " ";*/
    for (int i = 1; i < n + m + 1; i++) 
    {
        int j = P[i - 1];
        while (j > 0 && kmp[i] != kmp[j])
        {
            //obl++;
            j = P[j - 1];
        }
        if (kmp[i] == kmp[j])
            j++;
        P[i] = j;
        if(j == m)
            wyn[i - m - m]++;
    }
    //cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
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
    int ile = 0;
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(!cz2[i]) 
            continue;
        int nu = 0;
        for(auto x : s2)
        {
            if(x == i)
                kmp[nu] = 1;
            else
                kmp[nu] = 0;
            nu++;
        }
        ile ++;
        kmp[m] = 2;
        for(int j = 'a'; j <= 'z'; j++)
        {
            if(!cz1[j]) 
                continue;
            int nr = m + 1;
            for(auto x : s1)
            {
                if(x == j)
                    kmp[nr] = 1;
                else
                    kmp[nr] = 0;
                nr++;
            }
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