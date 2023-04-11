#include<stdio.h>
#include<stdlib.h>

struct process{
    int id;
    int burst_time;
    int arr_time;
    
};

void main(){
    int n;
    int total =0;
    printf("\nEnter no of process >> ");
    scanf("%d",&n);
    int waiting_time[n],n_time[n];
    struct process p[n];
    printf("\nEnter the brust time and arrival time Below .\n");
    for(int i=0;i<n;i++){
        printf("\nP%d > ",i+1);
        scanf("%d%d",&p[i].burst_time,&p[i].arr_time);
        p[i].id=i+1;

    }
   

   n_time[0]=p[0].burst_time;
   for(int i=1;i<n;i++){
        n_time[i] = p[i].burst_time + n_time[i-1];
    }
    waiting_time[0]=0;
    for(int i=1;i<n;i++){
        waiting_time[i] = n_time[i-1] - p[i].arr_time;
    }
    
    
    
    
    printf("\nProcess\tArrivalTime\tBurstTime\tWaitingTime");
    for(int i=0;i<n;i++){
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d",p[i].id, p[i].arr_time ,p[i].burst_time,waiting_time[i]);
        total +=waiting_time[i];
    }
    
    printf("\nAverage waiting time is %d ", total) ;  
 printf("\nAverage waiting time is %d ", total/n) ;  
    
    
}
