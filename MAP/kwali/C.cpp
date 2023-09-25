#include <bits/stdc++.h>
using namespace std;
vector<string> area;
int h, l;
int ans = 0;
bool boundscheck(int hv, int lv)
{
    if(hv < 0 || hv >= h)
    {
        return false;
    }
    if(lv < 0 || lv >= l)
    {
        return false;
    }
    return true;
}
void shrub(int hv, int lv)
{
    if(!boundscheck(hv, lv))
    {
        return;
    }
    if(area[hv][lv] != 'O')
    {
        area[hv][lv] = '#';
        return;
    }
}
bool danger(int hv, int lv)
{
    if(!boundscheck(hv, lv))
    {
        return false;
    }
    if(area[hv][lv] == 'O')
    {
        return true;
    }
    return false;
}
void examine(int hv, int lv)
{
    if(area[hv][lv] == '#')
    {
        return;
    }
    if(area[hv][lv] == 'O')
    {
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i == j && i == 0 && j == 0)
                {
                    continue;
                }
                shrub(hv + i, lv + j);
            }
        }
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i == j && i == 0 && j == 0)
                {
                    continue;
                }
                if(danger(hv + i, lv + j))
                {
                    return;
                }
            }
        }
        ans++;
    }
    if(area[hv][lv] == '?')
    {
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i == j && i == 0 && j == 0)
                {
                    continue;
                }
                if(danger(hv + i, lv + j))
                {
                    shrub(hv, lv);
                    return;
                }
            }
        }
        area[hv][lv] = 'O';
        ans++;
        for(int i = -1; i <= 1; i++)
        {
            for(int j = -1; j <= 1; j++)
            {
                if(i == j && i == 0 && j == 0)
                {
                    continue;
                }
                shrub(hv + i, lv + j);
            }
        }

    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>h>>l;
    for(int i = 0; i < h; i++)
    {
        string instr;
        cin>>instr;
        area.push_back(instr);
    }
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < l; j++)
        {
            examine(i, j);
        }
    }
    cout<<ans<<"\n";
}