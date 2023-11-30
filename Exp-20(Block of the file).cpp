#include <stdio.h>
#define MAX_BLOCKS 100
int main()
{
    int file[MAX_BLOCKS];
    int indexBlock[MAX_BLOCKS];
    int numBlocks, i;
    for(i=1;i<=MAX_BLOCKS;++i)
	{
        file[i]=-1;
    }
    for(i=1;i<=MAX_BLOCKS;++i)
	{
        indexBlock[i]=-1;
    }
    printf("Enter the number of blocks: ");
    scanf("%d",&numBlocks);
    if(numBlocks>MAX_BLOCKS)
    {
        printf("Exceeded maximum number of blocks.\n");
        return 1;
    }
    printf("Enter the blocks:\n");
    for(i=1;i<=numBlocks;++i)
	{
        scanf("%d",&file[i]);
        indexBlock[i]=i;
    }
    printf("\nFile Content:\n");
    for(i=1;i<=numBlocks;++i)
	{
        printf("%d ",file[i]);
    }
    printf("\n");
    printf("\nIndex Block Content:\n");
    for(i=1;i<=numBlocks;++i)
	{
        printf("%d ",indexBlock[i]);
    }
    printf("\n");
    return 0;
}

