#include <cs50.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    int* hashLocations;
    int length;
} csvLine;

csvLine extractNumbers(char* line);

int main(void)
{
    //Prompt the user for an input file
    printf("What is the name of the file I should read from?\n");
    string readfile = GetString();

    //Prompt the user for an output file
    printf("What is the name of the file I should write to?\n");
    string writefile = GetString();

    //Open the file to read from
    FILE* ascii = fopen(readfile, "r");

    //Open the file you're writing to
    FILE* art = fopen(writefile, "w");

    //Check that file open was successful
    if (ascii == NULL)
    {
        printf("%s does not exist!\n", readfile);
        return 1;
    }
    
    //For each line being read in from the input file:
    
    while (!feof(ascii))
        //Pass the line into the given extractNumbers function
       {
        extractNumbers(readfile);
        csvLine currentLine;
        
        //For each value in the int array returned by extractNumbers:
            for(int i = 0; i < currentLine.length; i++)
            {
                //put spaces in the file until the value is reached
                if (currentLine.hashLocations[i] != i)
                    fputc(' ', art);
                //put a hash in the file
                else  
                    fputc('#', art);
            }
        }
    //Close both files
    fclose(ascii);
    fclose(art);
    
    //Insert the name of the output file in the print statement below
    printf("Done! If you open up %s you should now see a cool image!\n", writefile);
}

csvLine extractNumbers(char* line)
{
    int count = 0;
    for(int i = 0; i < strlen(line); i++)
    {
        if(line[i] == ',')
        {
            count++;
        }
    }

    char* token;
    int* hV = malloc(sizeof(int) * (count+1));
    int i = 0;
    token = strtok(line, ",");
    hV[i] = atoi(token);
    i++;
    while ((token = strtok(NULL, ",")) != NULL)
    {
        hV[i] = atoi(token);
        i++;
    }
    csvLine result;
    result.hashLocations = hV;
    result.length = count + 1;
    return result;
}