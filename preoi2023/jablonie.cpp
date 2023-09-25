#include <bits/stdc++.h>

using namespace std;

const int r = 4e6 + 9, inf = 2e9;
int roz;
int tree[r];
int gw[r];

void zep(int v)
{
    tree[v] += gw[v];
    gw[v * 2] += gw[v];
    gw[v * 2 + 1] += gw[v];
    gw[v] = 0;
}

void akt(int lp, int pp, int v, int lz, int pz)
{
    zep(v);
    if(lp > pz || pp < lz)
        return;
    if(lp >= lz && pp <= pz)
    {
        gw[v]++;
        zep(v);
        return;
    }
    int sr = (lp + pp) / 2;
    akt(lp, sr, v * 2, lz, pz);
    akt(sr + 1, pp, v * 2 + 1, lz, pz);
    tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

int szu(int v, int x)
{
    zep(v);
    zep(v * 2);
    zep(v * 2 + 1);
    if(v >= roz)
    {
        if(tree[v] >= x)
            return v - roz;
        else
            return v - roz + 1;
    }
    if(tree[v * 2] >= x)
        return szu(v * 2, x);
    else
        return szu(v * 2 + 1, x);
}

void upd(int v)
{
    vector<int> vec;
    while(v > 0)
    {
        vec.push_back(v);
        v /= 2;
    }
    reverse(vec.begin(), vec.end());
    for(auto x : vec)
        zep(x);
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    roz = ceil(log2(n) + 1);
    roz = 1 << roz;
    for(int i = 0; i < n; i++)
        cin >> tree[roz + i];
    sort(tree + roz, tree + roz + n);
    for(int i = n; i < roz; i++)
        tree[roz + i] = inf;
    for(int i = roz - 1; i > 0; i--)
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
    while(m --)
    {
        string z;
        cin >> z;
        if(z[0] == 'p')
        {
            int x;
            cin >> x;
            if(x == 0)
                continue;
            upd(x + roz - 1);
            int naj = tree[x + roz - 1];
            int gdz = szu(1, naj);
            int gdzp = szu(1, naj + 1);
            //cout << 1 << " " << gdz << ", " << gdzp - (x - gdz) + 1 << " " << gdzp << "\n";
            if(gdz >= 1)
                akt(1, roz, 1, 1, gdz);
            akt(1, roz, 1, gdzp - (x - gdz) + 1,gdzp);
            /*for (int i = 1; i < 2 * roz; i++)
                cout << tree[i] << " " << gw[i] << ", ";*/
        }
        else
        {
            int a, b;
            cin >> a >> b;
            cout << szu(1, b + 1) - szu(1, a) << "\n";
        }
    }
}
