#include "pos.h"
using namespace std;
int main()
{
    init();
    char result = naprzod();
    if (result == 'b')
        szukaj();
    else
    {
        prawo();
        prawo();
        result = naprzod();
        result = naprzod();
        szukaj();
    }
}
