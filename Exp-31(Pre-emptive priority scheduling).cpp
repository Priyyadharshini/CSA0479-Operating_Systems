#include <stdio.h>
#define MAX_PROCESSES 10
int main()
{
    int n,i;
    int burst_time[MAX_PROCESSES];
    int priority[MAX_PROCESSES];
    int remaining_time[MAX_PROCESSES];
    int turnaround_time[MAX_PROCESSES];
    int waiting_time[MAX_PROCESSES];
    int total_waiting_time = 0, total_turnaround_time = 0;
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    printf("Enter burst times and priorities for each process:\n");
    for (i=1;i<=n;i++)
	{
        printf("Process %d:\n",i);
        printf("Burst Time: ");
        scanf("%d",&burst_time[i]);
        printf("Priority: ");
        scanf("%d",&priority[i]);
        remaining_time[i]=burst_time[i];
    }
    int time=0;
    while(1)
	{
        int selected_process=-1;
        int highest_priority=-1;
        for(i=1;i<=n;i++)
		{
            if(remaining_time[i]>0&&priority[i]>highest_priority&&time>=waiting_time[i])
			{
                highest_priority=priority[i];
                selected_process=i;
            }
        }
        if(selected_process==-1)
		{
            break;
        }
        remaining_time[selected_process]--;
        time++;
        for(i=1;i<=n;i++)
		{
            if(remaining_time[i]>0&&i!=selected_process)
			{
                waiting_time[i]++;
            }
        }
        if(remaining_time[selected_process]==0)
		{
            turnaround_time[selected_process]=time;
            total_waiting_time+=waiting_time[selected_process];
            total_turnaround_time+=turnaround_time[selected_process];
        }
    }
    float average_waiting_time=(float)total_waiting_time/n;
    float average_turnaround_time=(float)total_turnaround_time/n;
    printf("\nProcess\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");
    for(i=1;i<=n;i++)
	{
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n",i,burst_time[i],priority[i],waiting_time[i],turnaround_time[i]);
    }
    printf("\nAverage Waiting Time: %.2f\n", average_waiting_time);
    printf("Average Turnaround Time: %.2f\n", average_turnaround_time);
}

