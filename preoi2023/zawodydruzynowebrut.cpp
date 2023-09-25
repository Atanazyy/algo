
#include <bits/stdc++.h>

using namespace std;

struct zaw
{
    int x, y, z;
};

int main()
{
    int n;
    cin >> n;
    vector<zaw> v;
    for(int i = 0; i < n; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z});
    }
    int wyn = -1;
    for(auto x : v)
        for(auto y : v)
            for(auto z : v)
            {
                if(x.x > max(y.x, z.x) && y.y > max(x.y, z.y) && z.z > max(x.z, y.z))
                    wyn = max(wyn, x.x + y.y + z.z);
            }
    cout << wyn;
}
