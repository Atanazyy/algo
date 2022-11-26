#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
int ojc[r];
vector<int> syn[r];
int who[r];

void dfs(int v)
{
    who[v] = 0;
    if(syn[v].size() == 1)
    {
        dfs(syn[v][0]);
        if(who[syn[v][0]] == 0)
            who[v] = 1;
        if(who[syn[v][0]] == 1)
            who[v] = 0;
        if(who[syn[v][0]] == 2)
            who[v] = 2;
        //cout << v << " " << who[v] << "\n";
        return;
    }
    for(auto x : syn[v])
    {
        dfs(x);
        if(who[x] == 2 || who[x] == 0)
        {
            who[v] = 2;
            //cout << v << " " << who[v] << "\n";
            return;
        }
    }
    //cout << v << " " << who[v] << "\n";
}

int main()
{
    int n;
    cin >> n;
    for(int i = 2; i <= n; i++)
    {
        cin >> ojc[i];
        syn[ojc[i]].push_back(i);
    }
    for(int i = 2; i <= n; i++)
    {
        if(syn[ojc[i]].size() > 1 && syn[i].size() == 0)
        {
            cout << "Ja\n";
            return 0;
        }
    }
    dfs(1);
    if(who[1] == 2 || who[1] == 1)
    {
        cout << "Ja\n";
        return 0;
    }
    cout << "Kadra\n";
}