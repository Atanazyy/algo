#include <bits/stdc++.h>
#define f first 
#define s second
using namespace std;

const long long inf = 1e15;

int main()
{
    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector <pair<long long, long long> > v;
        multiset <long long> poc;
        multiset <long long> kon;
        poc.insert(inf);
        poc.insert(-inf);
        for(long long i = 0; i < n; i++)
        {
            long long a, b;
            cin >> a >> b;
            v.push_back({a, b});
            kon.insert(b);
        }
        sort(v.begin(), v.end());
        long long wyn = inf;  
        for(long long i = 0; i < n; i++)
        {
            //cout << " " << kon.size();
            kon.erase(kon.find(v[i].s));
            //cout << kon.size() << " ";
            if(i != 0)
                poc.insert(v[i - 1].s);
            long long mus = 0, w1 = inf, w2 = inf, w3 = inf;
            if(kon.size() > 0)
                mus = *prev(kon.end());
            //cout << " " << v[i].f << " " << mus << " " << *poc.lower_bound(v[i].f) << " " << *prev(poc.lower_bound(v[i].f)) << "\n";
            if(abs(*poc.lower_bound(v[i].f)) != inf) w1 = abs(v[i].f - max(mus, *poc.lower_bound(v[i].f)));
            if(abs(*prev(poc.lower_bound(v[i].f))) != inf) w2 = abs(v[i].f - max(mus, *prev(poc.lower_bound(v[i].f))));
            if(kon.size() > 0) w3 = abs(v[i].f - mus);
            wyn = min(min(w3, wyn), min(w1, w2));
            
        }
        cout << wyn << '\n';
    }
}