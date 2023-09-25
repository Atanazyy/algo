#include <bits/sdtc++.h>
#define f first
#define s second

using namespace std;

const int mod = 1e9 + 7, r = 509;

set <int> pot;
vector <int> wej;
map <int, long long> sta;
map <int, long long> now;

int main()
{
    int n;
    cin >> n;
    sta[0] = 1;
    pot.insert(0);
    for(int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        wej.push_back({a, b});
        pot.insert(a);
        pot.insert(b);
    }
    for(auto w : wej)
    {
        for(auto s : sta)
        {
            for(auto k : pot)
            {
                if(k <= )
            }
        }
    }
}
