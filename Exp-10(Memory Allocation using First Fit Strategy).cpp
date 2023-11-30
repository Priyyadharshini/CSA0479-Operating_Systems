#include<stdio.h>
#define MEMORY_SIZE 100
void allocatefirstfit(int processsize,int memory[],int n)
{
	int i,j,allocated;
	for(i=0;i<n;i++)
	{
		allocated=0;
		for(j=0;j<MEMORY_SIZE;j++)
		{
			if(memory[j]==0)
			{
				int blocksize=0;
				int start=j;
				while(j<MEMORY_SIZE && memory[j]==0)
				{
					blocksize++;
					j++;
				}
				if(blocksize>=processsize)
				{
					printf("Process %d allocated memory from %d to %d.\n",i+1,start,j-1);
					for(int k=start;k<start+processsize;k++)
					{
						memory[k]=1;
					}
					allocated=1;
					break;
				}
			}
		}
		if(!allocated)
		{
			printf("Process %d cannot be allocated in memory.\n",i+1);
		}
	}
}
int main()
{
	int numprocesses,processsize;
	int i,memory[MEMORY_SIZE]={0};
	printf("Enter the number of processes:");
	scanf("%d",&numprocesses);
	for(i=0;i<numprocesses;i++)
	{
		printf("Enter size of process %d:",i+1);
		scanf("%d",&processsize);
	}
	allocatefirstfit(processsize,memory,numprocesses);	
}
