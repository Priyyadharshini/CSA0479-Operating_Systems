#include <stdio.h>
#define MAX_RECORDS 100
int main()
{
    int file[MAX_RECORDS];
    int numRecords, i;
    for(i=1;i<=MAX_RECORDS;++i)
	{
        file[i]=-1;
    }
    printf("Enter the number of records: ");
    scanf("%d",&numRecords);
    if (numRecords>MAX_RECORDS)
	{
        printf("Error: Exceeded maximum number of records.\n");
        return 1;
    }
    printf("Enter the records:\n");
    for(i=1;i<numRecords;++i)
	{
        scanf("%d",&file[i]);
    }
    printf("\nFile Content:\n");
    for (i=1;i<numRecords;++i)
	{
        printf("%d ",file[i]);
    }
    printf("\n");
    return 0;
}

