#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;

struct cie
{
    __int128 x, d;
    pair <__int128, __int128> v;
};

struct kom
{
    pair <__int128, __int128> kie;
    __int128 dlu;
    int kto;
};

const int r = 1e5 + 9;
const __int128 inf = 1e16;

cie T[r];
stack <kom> kol;

pair<__int128, __int128> dod(pair<__int128, __int128> a, pair<__int128, __int128> b)
{
    return {a.f * b.s + b.f * a.s, b.s * a.s};
}

pair<__int128, __int128> odj(pair<__int128, __int128> a, pair<__int128, __int128> b)
{
    return {a.f * b.s - b.f * a.s, b.s * a.s};
}

bool wie(pair<__int128, __int128> a, pair<__int128, __int128> b)
{
    return a.f * b.s > b.f * a.s;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    __int128 n = a, D = b;
    pair <__int128, __int128> V = {c, d};
    for(int i = 1; i <= n; i++)
    {
        cin >> a >> b >> c >> d;
        T[i].x = a; T[i].d = b; T[i].v = {c, d};
    }
    int wyn = 0;
    for(int i = n; i >= 1; i--)
    {
        __int128 dlukol = 0;
        int stan = 0;
        pair <__int128, __int128> tzam = {-1, 1};
        pair <__int128, __int128> totw = {inf, 1};
        if(i == n)
        {
            stan = 1;
            totw = {0, 1};
        } 
        else if(T[i + 1].x - T[i].x - T[i + 1].d >= D)
        {
            stan = 1;
            totw = {0, 1};
        }
        while(!kol.empty())
        {
            auto ost = kol.top();
            dlukol += ost.dlu;
            __int128 doprz = T[ost.kto].x - T[i].x - dlukol;
            __int128 dozam = doprz - D;
            __int128 dootw = D - doprz;
            auto vwz = odj(T[i].v, T[ost.kto].v);  
            pair <__int128, __int128> tzd = {doprz * vwz.s, vwz.f};
            pair <__int128, __int128> tza = {dozam * vwz.s, vwz.f};
            pair <__int128, __int128> tot = {-dootw * vwz.s, vwz.f};
            if(tot.f < 0)
                tot = {-tot.f, -tot.s};
            if(vwz.f * vwz.s < 0 && !wie(tot, ost.kie) && stan == 0)
            {
                stan = 1;
                totw = tot;
            }
            if(vwz.f * vwz.s > 0 && !wie(tza, ost.kie) && stan == 1)
            {
                stan = 2;
                tzam = tza;
            }
            if(vwz.f * vwz.s <= 0 || wie(tzd, ost.kie))
            {
                kol.pop();
                continue;
            }
            kol.top().dlu = dlukol;
            kol.push({tzd, T[i].d, i});
            break;
        }
        if(kol.empty())
            kol.push({{inf, 1}, T[i].d, i});
        if(tzam.f == -1)
            tzam = {inf, 1};
        if(V.f * totw.f * T[i].v.s <= (D + T[i].x) * totw.s * V.s * T[i].v.s + T[i].v.f * totw.f * V.s)
            if(V.f * tzam.f * T[i].v.s >= (D + T[i].x) * tzam.s * V.s * T[i].v.s + T[i].v.f * tzam.f * V.s)
                wyn++;
        cout << (long long)kol.top().kto << ": " << (long long)totw.f << " / " << (long long)totw.s << ", " << (long long)tzam.f << " / " << (long long)tzam.s << ", " << (long long)kol.top().kie.f << " / " << (long long)kol.top().kie.s << "\n";
    }
    cout << wyn;
}
