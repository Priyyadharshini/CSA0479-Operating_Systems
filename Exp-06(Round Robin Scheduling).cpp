#include<stdio.h>
int main()
{
	int n,timeslice,i,time=0;
	int bursttime[n],remainingtime[n],waitingtime[n],turnaroundtime[n];
	float awt,atat;
	printf("Enter the number of process:");
	scanf("%d",&n);
	printf("Enter burst time for each process:\n");
	for(i=1;i<=n;i++)
	{
		printf("P%d:",i);
		scanf("%d",&bursttime[i]);
		remainingtime[i]=bursttime[i];
	}
	printf("Enter the Time slice:");
	scanf("%d",&timeslice);
	while(1)
	{
		int processesdone=1;
		
		for(i=1;i<=n;i++)
		{
			if(remainingtime[i]>0)
			{
				processesdone=0;
				if(remainingtime[i]>timeslice)
				{
					time=time+timeslice;
					remainingtime[i]-=timeslice;
				}
				else
				{
					time=time+remainingtime[i];
					waitingtime[i]=time-bursttime[i];
					awt=awt+waitingtime[i];
					remainingtime[i]=0;
				}
			}
		}
		if(processesdone)
		break;
	}
	for(i=1;i<=n;i++)
	{
		turnaroundtime[i]=bursttime[i]+waitingtime[i];
		atat=atat+turnaroundtime[i];
	}
	awt=awt/n;
	atat=atat/n;
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i=1;i<=n;i++)
	{
		printf("%d\t%d\t\t%d\t\t%d\n",i,bursttime[i],waitingtime[i],turnaroundtime[i]);
	}
	printf("Average waiting time:%d",awt);
	printf("Average turnaround time:%d",atat);
}
