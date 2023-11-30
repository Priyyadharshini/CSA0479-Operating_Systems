#include<stdio.h>
int main(){
	int a[100][4];
	int n,i,j,total=0,temp,index;
	float avg_wt, avg_tat;
	printf("Enter the number of Processes: ");
	scanf("%d",&n);
	printf("Enter the Burst Time:\n");
	for(i=0;i<n;i++){
		printf("P%d:",i+1);
		scanf("%d",&a[i][1]);
		a[i][0]=i+1;
	}
	for(i=0;i<n;i++){
		index=i;
		for(j=i+1;j<n;j++){
			if(a[j][1]<a[index][1]){
				index=j;
			}
		}
		temp=a[i][1];
		a[i][1]=a[index][1];
		a[index][1]=temp;
		
		temp=a[i][0];
		a[i][0]=a[index][0];
		a[index][0]=temp;
	}
	a[0][2]=0;
	for(i=1;i<n;i++){
		a[i][2]=0;
		for(j=0;j<i;j++){
			a[i][2]+=a[j][1];
		}
		total+=a[i][2];
	}
	avg_wt=(float) total/n;
	total=0;
	printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
	for(i=0;i<n;i++){
		a[i][3]=a[i][1]+a[i][2];
		total+=a[i][3];
		printf("P%d\t  %d\t\t%d\t\t%d\n",a[i][0],a[i][1],a[i][2],a[i][3]);
	}
	avg_tat=(float)total/n;
	printf("\nAverage Waiting Time: %f",avg_wt);
	printf("\nAverage Turnaround Time: %f",avg_tat);
	return 0;
}
