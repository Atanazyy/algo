#include <bits/stdc++.h>

using namespace std;

struct rze
{
    int x1, y1, x2, y2;
};

int xp, yp, xk, yk, p;
int syt[1009][1009];
vector <rze> wsz;

bool czy(int r)
{
    for(int i = 0; i <= 1001; i++)
        for(int j = 0; j <= 1001; j++)
            syt[i][j] = 0;
    for(auto x : wsz)
    {
        rze xd = x;
        xd.x1 -= r;
        xd.x2 += r;
        xd.y1 -= r;
        xd.y2 += r;
        for(int i = max(xd.x1, xp); i < min(xd.x2, xk); i++)
        {
            syt[i][max(xd.y1, yp)] ++;
            syt[i][min(xd.y2, yk)] --;
        }
    }
    int akt = 0, wyn = 0;
    for(int i = 0; i <= 1001; i++)
    {
        for(int j = 0; j <= 1001; j++)
        {
            //cout << syt[i][j];
            akt += syt[i][j];
            if(akt > 0)
                wyn ++;
        }
        //cout << "\n";
    }
    //cout << wyn;
    long long cal = (long long)p * (long long)(xk - xp) * (long long)(yk - yp);
    //cout << cal;
    return cal <= (long long)100 * (long long)wyn;
}

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        rze xd;
        cin >> xd.x1 >> xd.y1 >> xd.x2 >> xd.y2;
        wsz.push_back(xd);
    }
    cin >> p >> xp >> yp >> xk >> yk;
    //cout << czy(1);
    int poc = 0, kon = 10000;
    while(poc < kon)
    {
        int sr = (poc + kon) / 2;
        if(czy(sr))
            kon = sr;
        else
            poc = sr + 1;
    }
    cout << poc;
}