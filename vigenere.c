#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    string k = argv[1];
    if (argc != 2)
    {
        printf("Please give me a keyword!\n");
        return 1;
    }
    
    for (int i = 0; i < strlen(k); i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Please give me keyword!\n");
            return 1;
        }
    }   
    
    string p = GetString();
    
    for (int i = 0, y = 0, n = strlen(p); i < n; i++)
    {
        char c = p[i];
        char j = k[y%strlen(k)];
        
        if (isupper(j))
        {
            j = j - 65;
        }
        if (islower(j))
        {
            j = j - 97;
        }

        if (isupper(c))
        {
            c = c - 65;
            c = (c + j) % 26;
            c = c + 65;
            printf("%c", c); 
        }
        else if (islower(c))
        {
            c = c - 97;
            c = (c + j) % 26;
            c = c + 97;
            printf("%c", c); 
        }
        else
        {
            printf("%c", c);
        }
        if (isalpha(c))
        {
            y++;
        }
    }
    printf("\n");
}