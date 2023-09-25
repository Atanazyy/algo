#include <bits/stdc++.h>

using namespace std;

const int r = 2e5 + 9;
int tab[r];

int main()
{
    int n;
    cin >> n;
    long long wyn = 0;
    vector <long long> kos;
    vector <long long> koss;
    for(int i = 1; i <= n; i++)
    {
        cin >> tab[i];
        wyn += tab[i];
    }
    long long ost = max((long long)0, wyn);
    long long akt = tab[1] + tab[2] + tab[3];
    for(int i = 3; i <= n; i++)
    {
        ost = max(wyn - akt, ost);
        ost = max(wyn - akt - tab[i + 1], ost);
        ost = max(wyn - akt - tab[i + 1] - tab[i + 2], ost);
        kos.push_back(akt);
        koss.push_back(akt);
        akt -= tab[i - 2];
        akt += tab[i + 1];
    }
    sort(koss.begin(), koss.end());
    for(int i = 3; i <= n; i++)
    {
        vector <long long> ter;
        for(int j = max(3, i - 2); j <= min(n, i + 2); j++)
        {
            ter.push_back(kos[j - 3]);
        }
        ter.push_back(1000 * 1000 * 1000);
        sort(ter.begin(), ter.end());
        int j = 0;
        while(j < koss.size())
        {
            if(koss[j] != ter[j])
            {
                //cout << kos[i - 3] << " " << koss[j] << "\n";
                ost = max(ost, wyn - kos[i - 3] - koss[j]);
                break;
            }
            else
                j++;
        }
    }
    cout << ost;
}