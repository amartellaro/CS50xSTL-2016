#include <cs50.h>
#include <stdio.h>
#include <string.h>

bool validate(int argc, string argv[], int dimension);
void printGrid(int argc, string argv[], int dimension);

int main(int argc, string argv[])
{
    int dimension = argc - 1;
    
    if(!validate(argc, argv, dimension))
        return 1;
    
    printGrid(argc, argv, dimension);
}

bool validate(int argc, string argv[], int dimension)
{
    for (int i = 1; i < argc; i++)
    {
        if (strlen(argv[i]) != dimension)
        {
            printf("Please give me same number of words and letters!\n");
            return false;
        }
    }
    return true;
}

void printGrid(int argc, string argv[], int dimension)
{
    for (int y = 0; y < dimension; y++)
    {
        for (int i = 1; i < argc; i++)
        {
            printf("%c", argv[i][y]);
        }
        printf("\n");
    }
}