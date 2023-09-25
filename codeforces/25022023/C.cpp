#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector <int> v;
        map<int, int> cnt;
        map<int, int> kie;
        for(int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
            kie[a] = 0;
        }
        long long wyn = 0;
        long long dod = 0;
        int dos;
        int gdz;
        for(int i = 1; i <= m; i++)
        {
            int p, w;
            cin >> p >> w;
            p--;
            cnt[v[p]] += i - kie[v[p]];
            //cout << v[p] << " " << cnt[v[p]] <<"\n";
            kie[w] = i;
            v[p] = w;
        }
        //cout << wyn << "\n";
    }
}