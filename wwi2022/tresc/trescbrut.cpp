#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
int ojc[r];
vector <int> syn[r];
map <set<int>, bool> mapa;

bool cal(set <int> wie)
{
    if(mapa.find(wie) != mapa.end())
        return mapa[wie];
    vector <int> lis;
    set <int> nie;
    for(auto x : wie)
    {
        bool f = 0;
        for(auto y : syn[x])
            if(wie.find(y) != wie.end())
            {
                f = 1;
                break;
            }
        if(!f)
            lis.push_back(x);
        else
            nie.insert(x);
    }
    mapa[wie] = 0;
    for(int i = 0; i < ((1 << lis.size()) - 1); i++)
    {
        set <int> akt;
        for(auto x : nie)
            akt.insert(x);
        int v = i;
        int id = 0;
        while(v > 0)
        {
            if(v % 2 == 1)
                akt.insert(lis[id]);
            v /= 2;
            id ++;
        }
        if(cal(akt) == 0)
            mapa[wie] = 1;
    }
    for(auto x : wie)
        cout << x << " ";
    cout << " :: ";
    cout << ":: " << mapa[wie] << "\n";
    return mapa[wie];
}

int main()
{
    int n;
    cin >> n;
    set <int> start = {1};
    for(int i = 2; i <= n; i++)
    {
        start.insert(i);
        cin >> ojc[i];
        syn[ojc[i]].push_back(i);
    }
    mapa[{1}] = 0;
    if(cal(start))
        cout << "Ja\n";
    else
        cout << "Kadra\n";

}