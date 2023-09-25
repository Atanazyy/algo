#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

struct pkt
{
    long long x, y, z;

    friend bool operator<(pkt a, pkt b) {
        if(a.x == b.x) {
            if(a.y == b.y)
                return a.z < b.z;
            return a.y < b.y;
        }
        return a.x < b.x;
    }
};

long long SUMa, SUMb, SUMax, SUMay, SUMaz, SUMakw;

map <pkt, pair<long long, long long> > mapa;

void dod(long long x, long long y, long long z)
{
    pkt p = {x, y, z};
    auto ab = mapa[p];
    SUMa += ab.f;
    SUMb += ab.s;
    SUMax += ab.f * x;
    SUMay += ab.f * y;
    SUMaz += ab.f * z;
    SUMakw += ab.f * (x * x + y * y + z * z);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long q;
    cin >> q;
    while(q--)
    {
        long long x, y, z;
        char zap;
        cin >> zap >> x >> y >> z;
        if(zap == 'U')
        {
            mapa[{x, y, z}].f *= -1;
            mapa[{x, y, z}].s *= -1;
            dod(x, y, z);
        }
        if(zap == 'Z')
        {
            cout << (x * x + y * y + z * z) * SUMa - 2 * x * SUMax - 2 * y * SUMay - 2 * z * SUMaz + SUMakw + SUMb << "\n"; 
        }
        if(zap == 'D')
        {
            long long a, b;
            cin >> a >> b;
            mapa[{x, y, z}].f = a;
            mapa[{x, y, z}].s = b;
            dod(x, y, z);
        }
    }
}