#include <bits/stdc++.h>
 
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    int minw = 0;
    int maxw = 0;
    while(n--)
    {
        string s;
        cin >> s;
        int zap = 0;
        for(int i = 0; i < m; i++)
            zap += s[i] - '0';
        int opc = 0;
        for(int i = 0; i < m - 1; i++)
        {
            if(s[i] == '1' && s[i + 1] == '1')
            {
                opc++;
                i++;
            }
        }
        opc = min(opc, m / 4);
        minw += zap - opc;
        opc = 0;
        for(int i = 0; i < m - 1; i++)
        {
            if(s[i] == '0' || s[i + 1] == '0')
            {
                opc++;
                i++;
            }
        }
        opc = min(opc, m / 4);
        maxw += zap - (m / 4 - opc);
    }
    cout << minw << " " << maxw;
}