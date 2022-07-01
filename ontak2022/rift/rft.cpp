#include <bits/stdc++.h>

using namespace std;

const int r = 1e6;
vector <int> tab[r];
long long ile[r];
int sto[r];

int main()
{
    int n, m;
    cin >> n >> m;
    long long wyn = 0;
    for(int i = 1; i < n; i++)
    {
        int k;
        cin >> k;
        for(int j = 0; j < k; j++)
        {
            int v;
            cin >> v;
            tab[i].push_back(v);
            sto[v]++;
        }
    }
    queue <int> kol;
    for(int i = 1; i <= n; i++)
        if(sto[i] == 0)
            kol.push(i);
    ile[1] = m;
    while(!kol.empty())
    {
        int v = kol.front();
        kol.pop();
        if(v == n)
            break;
        int mal = ile[v] % tab[v].size(), duz = ile[v] / tab[v].size();
        wyn += ile[v];
        int i = 0;
        //cout << v << " " << mal << " " << duz << "\n";
        for(auto u : tab[v])
        {
            if(i < mal)
                ile[u] ++;
            i++;
            sto[u]--;
            ile[u] += duz;
            if(sto[u] == 0)
                kol.push(u);
        }
    }
    cout << wyn;
}