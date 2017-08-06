#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int h;
    do
    {
        printf("Height: ");
        h = GetInt();
    }
    while(h<0 || h>23);

for(int r=0; r<h; r++)
    {
     for(int s=0; s<(h-r-1); s++)
     {
        printf(" ");
     }
        for(int p=0; p<(r+2); p++)
            {
                printf("#");
            }
    printf("\n");
    }
}


