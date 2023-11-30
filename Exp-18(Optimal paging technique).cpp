#include <stdio.h>
#include <limits.h>
#define FRAME_SIZE 3
#define PAGE_SIZE 10
int main()
{
    int frames[FRAME_SIZE];
    int pages[PAGE_SIZE]={0, 1, 2, 3, 2, 4, 3, 4, 5, 4};
    int i,pageFaults=0,currentIndex=0,pageExists = 0;;
    int nextUse[FRAME_SIZE];
    printf("Page Reference String: ");
    for(i=1;i<=PAGE_SIZE;++i)
	{
        printf("%d ",pages[i]);
    }
    printf("\n");
    for(i=1;i<=FRAME_SIZE;++i)
	{
        frames[i]=-1;
        nextUse[i]=INT_MAX; 
    }
    printf("\nOptimal Page Replacement:\n");
    for(i=1;i<PAGE_SIZE;++i)
	{
    	printf("\nPage %d: ",pages[i]);
        for(int j = 1;j<=FRAME_SIZE;++j)
		{
            if (frames[j] == pages[i])
			{
                pageExists = 1;
                break;
            }
        }
        if (!pageExists)
		{
            printf("Page Fault!");
            int farthestIndex = -1;
            int farthestUse = -1;
            for(int j=1;j<=FRAME_SIZE;++j)
			{
                int found=0;
                for(int k=i+1;k<PAGE_SIZE;++k)
				{
                    if(frames[j]==pages[k])
					{
                        found=1;
                        if(k>farthestUse)
						{
                            farthestUse=k;
                            farthestIndex=j;
                        }
                        break;
                    }
                }
                if (!found)
				{
                    farthestIndex = j;
                    break;
                }
            }
            frames[farthestIndex]=pages[i];
            nextUse[farthestIndex]=farthestUse;
            pageFaults++;
        }
		else
		{
            printf("Page Hit!");
        }
        printf("\tFrames: ");
        for (int j=1;j<=FRAME_SIZE;++j)
		{
            printf("%d ",frames[j]);
        }
    }
    printf("\n\nTotal Page Faults: %d\n",pageFaults);
    return 0;
}

