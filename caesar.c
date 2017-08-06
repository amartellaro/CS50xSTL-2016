#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Please give me a positive int!\n");
        return 1;
    }
    
    string p = GetString();
    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        int k = atoi(argv[1]);
        char c = p[i];
        if (isupper(c))
        {
            c = c - 65;
            c = (c + k) % 26;
            c = c + 65;
            printf("%c", c); 
        }
        else if (islower(c))
        {
            c = c - 97;
            c = (c + k) % 26;
            c = c + 97;
            printf("%c", c);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
}