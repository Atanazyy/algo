#include <bits/stdc++.h>

using namespace std;

const int r = 1e5 + 9;
int dpA[r];
int dpB[r];

int main()
{
    int n;
    cin >> n;
    dpA[0] = 1;
    dpB[0] = 0;
    for(int i = 1; i < n; i++)
    {
        dpA[i] = dpA[i - 1];
        dpB[i] = dpB[i - 1];
        if(i >= 2)
        {
            dpA[i] += dpB[i - 2];
            dpB[i] += dpA[i - 2];
        }
        cout << i << " " << dpA[i] << " " << dpB[i];
        if(dpA[i] == dpB[i])
            cout << "=\n";
        else if(dpA[i] > dpB[i])
            cout << ">\n";
        else
            cout << "<\n";
    }
}