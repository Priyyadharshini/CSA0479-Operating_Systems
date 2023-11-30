#include <stdio.h>
#include <stdlib.h>
#define MAX_BLOCKS 100
int main()
{
    int file[MAX_BLOCKS];
    int nextBlock[MAX_BLOCKS];
    int firstBlock,lastBlock,currentBlock,numBlocks, i;
    for(i=1;i<=MAX_BLOCKS;++i)
	{
        file[i]=-1;
        nextBlock[i] = -1;
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
    }
    firstBlock=0; 
    lastBlock=numBlocks-1; 
    for(i=1;i<=numBlocks-1;++i)
	{
        nextBlock[i]=i+1;
    }
    printf("\nFile Content:\n");
    currentBlock=firstBlock;
    while(currentBlock!=-1)
	{
        printf("%d ",file[currentBlock]);
        currentBlock=nextBlock[currentBlock];
    }
    printf("\n");
    return 0;
}

