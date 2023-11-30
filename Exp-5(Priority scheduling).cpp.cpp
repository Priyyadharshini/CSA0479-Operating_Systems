#include<stdio.h>
struct priority_scheduling{
	char process_name;
	int burst_time, waiting_time,turn_around_time,priority;
};
int main(){
	int no_of_process ,total=0,position,ASCII_number=65;
	struct priority_scheduling temp_process;
	float avg_waiting_time, avg_turnaround_time;
	printf("Enter the total number of Process: ");
	scanf("%d",&no_of_process);
	struct priority_scheduling process[no_of_process];
	printf("\nPlease Enter the Burst Time and Priority: ");
	for(int i=0;i<no_of_process;i++){
		process[i].process_name=(char)ASCII_number;
		printf("\nEnter the details of the process %c\n",process[i].process_name);
		printf("Enter the Burst Time: ");
		scanf("%d",&process[i].burst_time);
		printf("Enter the Priority: ");
		scanf("%d",&process[i].priority);
		ASCII_number++;
	}
	for(int i=0;i<no_of_process;i++){
		position=i;
		for(int j=i+1;j<no_of_process;j++){
			if(process[j].priority>process[position].priority){
				position=j;
			}	
		}
		temp_process=process[i];
		process[i]=process[position];
		process[position]=temp_process;
	}
	process[0].waiting_time=0;
	for(int i=1;i<no_of_process;i++){
		process[i].waiting_time=0;
		for(int j=0;j<no_of_process;j++){
			process[i].waiting_time+=process[j].burst_time;
		}
		total+=process[i].waiting_time;
	}
	avg_waiting_time=(float) total/(float) no_of_process;
	total=0;
	printf("\n\nProcess Name \t Burst Time \t Waiting Time \t TurnAround Time\n");
	for(int i=0;i<no_of_process;i++){
		process[i].turn_around_time=process[i].burst_time+process[i].waiting_time;
		total+=process[i].turn_around_time;
		printf("\t %c \t\t %d \t\t %d \t\t %d",process[i].process_name,process[i].burst_time,process[i].waiting_time,process[i].turn_around_time);
	}
	avg_turnaround_time=(float) total/(float)no_of_process;
	printf("\n\nAverage Waiting Time: %f",avg_waiting_time);
	printf("\nAverage TurnAround Time: %f",avg_turnaround_time);
	return 0;
}
