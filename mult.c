#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include "mult.h"

bool multhelp(int x, int y);

int main(void)
{
    int x = GetInt();
    int y = GetInt();
    int answer = mult(x, y);
    
    bool product = multhelp(x, y);
    
    if (product == false)
    {
        printf("%i\n", -answer);
    }
    else if (product == true)
    {
        printf("%i\n", answer);
    }
    return 0;
}

bool multhelp(int x, int y)
{
    if (x<0 && y<0)
        return true;
    else if (x>0 && y>0)
        return true;
    else
        return false;
}

int mult(int x, int y)
{
   if (y == 1)
   {
       int answer = abs(x);
       return answer;
    }
    else
    {
        x = abs(x);
        y = abs(y);
        int answer = (x + mult(x, y-1));
        return answer;
    }
}