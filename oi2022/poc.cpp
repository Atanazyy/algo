#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

const int r = 3e5 + 9;
int T1[r];
int T2[r];
int pre[r], post[r];
vector <pair<int, int> > tab;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++)
        cin >> T1[i];
    for(int i = 1; i <= m; i++)
    {
        cin >> T2[i];
        tab.push_back({T2[i], i});
    }
    sort(tab.begin(), tab.end());
    int j = 1;
    for(int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1];
        if(T1[i] == T2[j])
        {
            j++;
            pre[i]++;
        }
    }
    j = m;
    for(int i = n; i >= 1; i--)
    {
        post[i] = post[i + 1];
        if(T1[i] == T2[j])
        {
            j--;
            post[i]++;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        int poc = m - post[i] + 1;
        int kon =pre[i];
        int low = lower_bound(tab.begin(), tab.end(), pair<int, int>{T1[i], poc}) - tab.begin();
        // cout << poc << " " << kon << " " << tab[low].s <<"\n";
        if(poc <= tab[low].s && tab[low].s <= kon && tab[low].f == T1[i])
            cout << "1 ";
        else
            cout << "0 ";
    }
}
