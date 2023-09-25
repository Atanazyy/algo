#include <bits/stdc++.h>

using namespace std;

const long long r = 2e5 + 9, p1 = 997, p2 = 313, m1 = 1e9 + 7, m2 = 1e9 + 9;
long long h1[r], h2[r], hk1[r], hk2[r];

long long szy(long long pod, long long wyk, long long mod)
{
    if(wyk == 0)
        return 1;
    if(wyk % 2 == 0)
    {
        long long xd = szy(pod, wyk / 2, mod);
        return (xd * xd) % mod;
    }
    return (szy(pod, wyk - 1, mod) * pod) % mod;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        set <long long> st;
        int n;
        string s;
        cin >> n;
        cin >> s;
        h1[0] = h2[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            h1[i] = (h1[i - 1] * p1 + s[i - 1]) % m1;
            h2[i] = (h2[i - 1] * p2 + s[i - 1]) % m2;
        }
        hk1[n + 1] = hk2[n + 1] = 0;
        for(int i = n; i >= 1; i--)
        {
            hk1[i] = (hk1[i + 1] * p1 + s[i - 1]) % m1;
            hk2[i] = (hk2[i + 1] * p2 + s[i - 1]) % m2;
        }
        int siz = n - 2;
        for(int i = 1; i <= n - 1; i++)
        {
            long long t1 = (h1[i - 1] * szy(p1, siz, m1) + hk1[i + 2]) % m1;
            long long t2 = (m2 + h2[n] - ((szy(p2, n - i - 1, m2) * h2[i + 1]) % m2) + h2[i - 1] * szy(p2, n - i + 1, m2)) % m2;
            siz--;
            cout << t1 << " ";
            st.insert(t1);
        }
        cout << st.size() << "X\n";
    }
}