#include <bits/stdc++.h>
#include "pos.h"

using namespace std;

int main()
{
    init();
    char ost = 'd';
    while(1)
    {
        char x = naprzod();
        if(x == 'r')
            break;
        if(x == 'd' && ost == 'b')
        {
            lewo();
            lewo();
            naprzod();
            break;
        }
        ost = x;
    } 
    lewo();
    ost = 'd';
    while(1)
    {
        char x = naprzod();
        if(x == 'r')
            break;
        if(x == 'd' && ost == 'b')
        {
            lewo();
            lewo();
            naprzod();
            break;
        }
        ost = x;
    } 
    lewo();
    bool f = 1;
    if(naprzod() == 'b')
        f = 0;
    lewo();
    lewo();
    naprzod();
    if(naprzod() == 'b')
        f = 0;
    lewo();
    lewo();
    naprzod();
    lewo();
    if(f)
    {
        szukaj();
        return 0;
    }
    ost = 'd';
    while(1)
    {
        char x = naprzod();
        if(x == 'r')
            break;
        if(x == 'd' && ost == 'b')
        {
            lewo();
            lewo();
            naprzod();
            break;
        }
        ost = x;
    } 

    szukaj();
}