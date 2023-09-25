#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 3e3 + 9;
pair<pair<int, int>, int> OX[r];
pair<pair<int, int>, int> OY[r];

int main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> OX[i].f.f >> OX[i].f.s >> OX[i].s;
    for(int i = 0; i < m; i++)
        cin >> OY[i].f.f >> OY[i].f.s >> OY[i].s;
    int rek = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(OY[j].f.f <= OX[i].s && OX[i].s <= OY[j].f.s && OX[i].f.f <= OY[j].s && OY[j].s <= OX[i].f.s)
                rek = max(rek, min(min(abs(OX[i].s - OY[j].f.f), abs(OX[i].s - OY[j].f.s)), min(abs(OY[j].s - OX[i].f.f), abs(OY[j].s - OX[i].f.s))));
        }
    }
    cout << rek;
}
