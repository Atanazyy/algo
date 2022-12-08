#define f first 
#define s second
#include <bits/stdc++.h>

using namespace std;

long double dist(pair<long double, long double> a, pair<long double, long double> b)
{
    return sqrt((a.f - b.f) * (a.f - b.f) + (a.s - b.s) * (a.s - b.s));
}

const long double eps = 1e-15;

bool tacySami (const vector<pair<double, double>> &a, const vector<pair<double, double>> &b)
{
    vector <int> xd;
    int n = a.size();
    for(int i = 0; i < n; i++)
        xd.push_back(i);
    if(n <= 1)
        return 1;
    do
    {
        long double p1 = dist(a[0], a[1]);
        long double d1 = dist(b[xd[0]], b[xd[1]]);
        bool f = 1;
        for(int i = 0; i < n; i++)
        {
            if(f == 0)
                break;
            for(int j = 0; j < n; j++)
            {
                long double p2 = dist(a[i], a[j]);
                long double d2 = dist(b[xd[i]], b[xd[j]]);
                if(abs(p1 * d2 - p2 * d1) > eps)
                {
                    //cout << p1 * d2 << " " << p2 * d1 << "\n";
                    f = 0;
                }
            }
        }
        if(f) return f; 
    } while(next_permutation(xd.begin(), xd.end()));
    return 0;
}
