#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool validate(int argc, string argv[], int dimension);
void printGrid(int argc, string argv[], int dimension);
void printStretch(int argc, string argv[], int stretch);

int main(int argc, string argv[])
{
    int dimension = argc - 1;
    
    if(!validate(argc, argv, dimension))
        return 1;
    
    printf("Your word grid currently looks like this:\n");
    printGrid(argc, argv, dimension);
    printf("Now I will stretch it out. How much should I stretch it by?\n");
    int stretch = GetInt();
    printStretch(argc, argv, stretch);
}

bool validate(int argc, string argv[], int dimension)
{
    if (argc != 4)
    {
        printf("Please give me 3 words of the same length!\n");
        return false;
    }
    
    for (int i = 1; i < argc-1; i++)
    {
        if (strlen(argv[i]) != strlen(argv[i+1]))
        {
            printf("Please give me 3 words of the same length!\n");
            return false;
        }
    }
    return true;
}

void printGrid(int argc, string argv[], int dimension)
{
    for (int i = 1; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }
}

void printStretch(int argc, string argv[], int stretch)
{
   // iterate over each word
   for (int i = 1; i < argc; i++)
   {
        // horizontal
        for(int h = 0; h < stretch; h++)
        {
            // iterate over each letter
            for (int j = 0; j < argc; j++)
            {
                // vertical
                for (int k = 0; k < stretch; k++)
                {
                    printf("%c", argv[i][j]);
                }
                printf("%c", argv[i][j]);
            }
            printf("\n");
        }
   }
}