#include <bits/stdc++.h>

using namespace std;

struct zaw
{
    int x, y, z, u;
};

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    vector<zaw> v;
    for(int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z, 1});
    }
    while(1)
    {
        int mx = 0, my = 0, mz = 0;
        int ile = 0;
        for(auto x : v)
            ile += x.u;
        if(ile < 3)
        {
            cout << -1;
            return 0;
        }
        for(auto x : v)
        {
            if(x.u == 0)
                continue;
            mx = max(mx, x.x);
            my = max(my, x.y);
            mz = max(mz, x.z);
        }
        bool f = 1;
        for(int i = 0; i < n; i++)
        {
            auto x = v[i];
            if(x.u == 0)
                continue;
            if(((x.x == mx) + (x.y == my) + (x.z == mz)) >= 2)
            {
                v[i].u = 0;
                f = 0;
                continue;
            }
        }
        if(f)
            break;
    }
    int mx = 0, my = 0, mz = 0;
    for(auto x : v)
    {
        if(x.u == 0)
            continue;
        mx = max(mx, x.x);
        my = max(my, x.y);
        mz = max(mz, x.z);
    }
    cout << mx + my + mz;
}
