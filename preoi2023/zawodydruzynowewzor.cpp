#include <bits/stdc++.h>

using namespace std;

struct zaw
{
    int x, y, z, u;
};
vector<zaw> v;
vector<int> xy, xz, yz, vz;

bool cxy(int a, int b)
{
    if(v[a].x == v[b].x)
        return v[a].y > v[b].y;
    return v[a].x > v[b].x;
}

bool cxz(int a, int b)
{
    if(v[a].x == v[b].x)
        return v[a].z > v[b].z;
    return v[a].x > v[b].x;
}

bool cyz(int a, int b)
{
    if(v[a].y == v[b].y)
        return v[a].z > v[b].z;
    return v[a].y > v[b].y;
}

bool cz(int a, int b)
{
    return v[a].z > v[b].z;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n;
    cin >> n;
    int mx = 0, my = 0, mz = 0;
    int wxy = 0, wxz = 0, wyz = 0, wz = 0;
    for(int i = 0; i < n; i++)
    {
        xy.push_back(i);
        xz.push_back(i);
        yz.push_back(i);
        vz.push_back(i);
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z, 1});
        mx = max(mx, x);
        my = max(my, y);
        mz = max(mz, z);
    }
    sort(xy.begin(), xy.end(), cxy);
    sort(xz.begin(), xz.end(), cxz);
    sort(yz.begin(), yz.end(), cyz);
    sort(vz.begin(), vz.end(), cz);
    int ile = n;
    while(ile >= 3)
    {
        //cout << wxy << " " << wxz << " " << wyz << " " << wz << ", " << mx << " " << my << " " << mz << "\n";
        if(v[xy[wxy]].u == 0)
        {
            wxy++;
            mx = v[xy[wxy]].x;
            continue;
        }
        if(v[xz[wxz]].u == 0)
        {
            wxz++;
            mx = v[xz[wxz]].x;
            continue;
        }
        if(v[yz[wyz]].u == 0)
        {
            wyz++;
            my = v[yz[wyz]].y;
            continue;
        }
        if(v[vz[wz]].u == 0)
        {
            wz++;
            mz = v[vz[wz]].z;
            continue;
        }
        if(v[xy[wxy]].y == my)
        {
            v[xy[wxy]].u = 0;
            ile --;
            continue;
        }
        if(v[xz[wxz]].z == mz)
        {
            v[xz[wxz]].u = 0;
            ile --;
            continue;
        }
        if(v[yz[wyz]].z == mz)
        {
            v[yz[wyz]].u = 0;
            ile --;
            continue;
        }
        break;
    }
    if(ile < 3)
    {
        cout << -1;
        return 0;
    }
    cout << mx + my + mz;
}
