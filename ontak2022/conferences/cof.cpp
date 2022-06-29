#include <bits/stdc++.h>
#define f first
#define s second

using namespace std;

const int r = 1e4;

struct kon
{
    int poc, kon, w, nr;
};

vector <kon> tab; 
long long wyn[r];

bool por(kon a, kon b)
{   
    return a.poc < b.poc;
}

int main()
{
    int n, k;
    cin >> n >> k;
    long long sum = 0;
    for(int i = 1; i <= n; i++)
    {
        int poc, kon, w;
        cin >> poc >> kon >> w;
        sum += w;
        tab.push_back({poc, kon, w, i});
    }
    sort(tab.begin(), tab.end(), por);
    long long rek = 0;
    for(auto x : tab)
    {
        wyn[x.nr] = 0;
        for(auto y : tab)
        {
            if(x.poc > y.kon)
                wyn[x.nr] = max(wyn[y.nr], wyn[x.nr]);
        }
        wyn[x.nr] += x.w;
        //cout << x.poc << " " << x.kon << ": " << wyn[x.nr] << "\n";
        rek = max(rek, wyn[x.nr]);
    }
    cout << sum - rek;
}