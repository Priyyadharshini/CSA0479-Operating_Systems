#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_LENGTH 256
int main()
{
    FILE *file;
    char fileName[50], pattern[50], line[MAX_LINE_LENGTH];
    int lineNumber=0;
    printf("Enter the file name: ");
    scanf("%s",&fileName);
    printf("Enter the pattern to search: ");
    scanf("%s",&pattern);
    file = fopen(fileName,"r");
    if(file==NULL)
	{
        perror("Error opening file");
        return 1;
    }
    printf("Lines containing the pattern \"%s\" in file \"%s\":\n",pattern,fileName);
    while(fgets(line, MAX_LINE_LENGTH, file) != NULL)
	{
        lineNumber++;
        if(strstr(line, pattern) != NULL)
		{
            printf("Line %d: %s", lineNumber, line);
        }
    }
    fclose(file);
}

