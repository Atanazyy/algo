#include <bits/stdc++.h>

using namespace std;

bool tab[20][20];

int main()
{
    int n;
    cin >> n;
    for(int i = 1; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        tab[a][b] = 1;
        tab[b][a] = 1;
    }
    
}