#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *file;
    char fileName[50];
    char content[100];
    printf("Enter the file name to create: ");
    scanf("%s",&fileName);
    file =fopen(fileName,"w");
    if (file == NULL)
	{
        printf("Error creating file.\n");
        return 1;
    }
    printf("Enter content to write to the file : ");
    scanf("%s", content);
    fprintf(file,"%s",content);
    fclose(file);
    printf("File created and content written successfully.\n");
    file = fopen(fileName,"r");
    if(file == NULL)
	{
        printf("Error opening file for reading.\n");
        return 1;
    }
    printf("\nContent read from the file: ");
    char ch;
    while((ch=fgetc(file))!=EOF)
	{
        putchar(ch);
    }
    fclose(file);
    file = fopen(fileName,"a");
    if(file == NULL)
	{
        printf("Error opening file for appending.\n");
        return 1;
    }
    printf("\nEnter additional content to append to the file: ");
    scanf("%s",&content);
    fprintf(file, "\n%s", content);
    fclose(file);
    printf("Content appended to the file successfully.\n");
    if (remove(fileName) == 0)
	{
        printf("\nFile deleted successfully.\n");
    } 
	else
	{
        printf("\nError deleting file.\n");
    }
}
