#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float t;
    do
    {
        printf("How much do I owe ya? ");
        t = GetFloat();
    }
    while(t<0);
    
    t=t*100;
    t = round(t);
    int m;
    m=t;
    
    int c=0;
    while(m>=25)
    {
        m=(m-25);
        c=(c+1);
    }
    while(m>=10)
    {
        m=(m-10);
        c=(c+1);
    }
    if(m>=5)
    {
        m=(m-5);
        c=(c+1);
    }
    while(m>=1)
    {
        m=(m-1);
        c=(c+1);
    }
    
    printf("%i\n", c);
}