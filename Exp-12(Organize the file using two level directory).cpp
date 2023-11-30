#include<stdio.h>
#include<string.h>
#define MAX_DIRECTORIES 5
#define MAX_FILES_PER_DIRECTORY 10
#define MAX_NAME_LENGTH 20
int main()
{
	char directories[MAX_DIRECTORIES][MAX_NAME_LENGTH];
	char files[MAX_DIRECTORIES][MAX_FILES_PER_DIRECTORY][MAX_NAME_LENGTH];
	int filesizes[MAX_DIRECTORIES][MAX_FILES_PER_DIRECTORY];
	int n,i,j,numfiles;
    printf("Enter the number of directories: ");
    scanf("%d",&n);
    if(n>MAX_DIRECTORIES)
	{
        printf("Exceeded maximum number of directories.\n");
    }
    for(i=1;i<=n;i++)
	{
        printf("Enter name for directory %d:",i);
        scanf("%s",directories[i]);
        printf("Enter the number of files for directory %d:",i);
        scanf("%d",&numfiles);
        if(numfiles>MAX_FILES_PER_DIRECTORY)
		{
            printf("Exceeded maximum number of files per directory.\n");
        }
        for(j=1;j<=numfiles;j++)
		{
            printf("Enter name for file %d in directory %d:",j,i);
            scanf("%s",files[i][j]);
            printf("Enter size for file %d in directory %d:",j,i);
            scanf("%d",&filesizes[i][j]);
        }
    }
    printf("\nDirectory Structure:\n");
    for(i=1;i<=n;i++)
	{
        printf("|-- %s\n",directories[i]);
        for(j=1;j<=numfiles;j++)
		{
            printf("    |-- %s (%d KB)\n",files[i][j],filesizes[i][j]);
        }
    }
    return 0;
}
