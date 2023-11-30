#include <stdio.h>
#include <stdlib.h>
#define MAX_REQUESTS 100
int main()
{
    int requests[MAX_REQUESTS];
    int numRequests,head,totalSeekTime;
    printf("Enter the number of disk requests: ");
    scanf("%d",&numRequests);
    if(numRequests>MAX_REQUESTS)
	{
        printf("Exceeded maximum number of requests.\n");
        return 1;
    }
    printf("Enter the disk requests:\n");
    for(int i=0;i<numRequests;++i)
	{
        scanf("%d",&requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d",&head);
    for(int i=1;i<=numRequests-1;++i)
	{
        for (int j=1;j<=numRequests-i-1;++j)
		{
            if (requests[j]>requests[j+1])
			{
                int temp=requests[j];
                requests[j]=requests[j + 1];
                requests[j + 1]=temp;
            }
        }
    }
    totalSeekTime = 0;
    int currentIndex = 0;
    while(currentIndex<numRequests&&requests[currentIndex]<head)
	{
        totalSeekTime+=abs(head-requests[currentIndex]);
        head=requests[currentIndex];
        currentIndex++;
    }
    totalSeekTime+=abs(head-199); 
    head=0;

    while(currentIndex<numRequests)
	{
        totalSeekTime+=abs(head-requests[currentIndex]);
        head=requests[currentIndex];
        currentIndex++;
    }
    printf("\nTotal seek time using C-SCAN: %d\n",totalSeekTime);
    return 0;
}
