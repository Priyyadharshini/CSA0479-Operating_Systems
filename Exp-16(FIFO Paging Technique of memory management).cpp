#include <stdio.h>
#define FRAME_SIZE 3
#define PAGE_SIZE 10
int main()
{
    int frames[FRAME_SIZE];
    int pages[PAGE_SIZE] = {0, 1, 2, 3, 2, 4, 3, 4, 5, 4};
    int i,j,pagefaults = 0,currentindex=0,pageexists=0;

    printf("Page Reference String: ");
    for(i=1;i<=PAGE_SIZE;i++)
	{
        printf("%d",pages[i]);
    }
    printf("\n");
    for(i=1;i<=FRAME_SIZE;i++)
	{
        frames[i]=-1;
    }
    printf("\nFIFO Page Replacement:\n");
    for(i=1;i<PAGE_SIZE;i++)
	{
        printf("\nPage %d:",pages[i]);
        for(j=1;j<=FRAME_SIZE;j++)
		{
            if(frames[j]==pages[i])
			{
                pageexists=1;
                break;
            }
        }
        if(!pageexists)
		{
            printf("Page Fault!");
            frames[currentindex]=pages[i];
            currentindex=(currentindex+1)%FRAME_SIZE;
            pagefaults++;
        }
		else
		{
            printf("Page Hit!");
        }
        printf("\tFrames:");
        for(int j=1;j<=FRAME_SIZE;j++)
		{
            printf("%d ",frames[j]);
        }
    }
    printf("\n\nTotal Page Faults: %d\n",pagefaults);
    return 0;
}
