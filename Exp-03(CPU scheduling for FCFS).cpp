#include<stdio.h>
int main(){
	int n,i;
	printf("Enter the number of process: ");
	scanf("%d",&n);
	int bt[n],wt[n],tat[n];
	printf("Enter the Burst Time:\n");
	for(i=0;i<n;i++){
		printf("P%d: ",i+1);
		scanf("%d",&bt[i]);
	}
	wt[0]=0;
	tat[0]=bt[0];
	for(i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
		tat[i]=wt[i]+bt[i];
	}
	float avg_wt=0,avg_tat=0;
	for(i=0;i<n;i++){
		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	avg_wt/=n;
	avg_tat/=n;
	printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<n;i++){
		printf("%d\t%d\t\t%d\t\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}
	printf("\nAverage Waiting Time: %f", avg_wt);
    printf("\nAverage Turnaround Time: %f", avg_tat);
    return 0;
}
