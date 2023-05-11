#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
    int waiting_time[n],c_time[n],t_time[n];
    struct process p[n];
    printf("\nEnter the Arrival time and Burst time Below .\n");
    for(int i=0;i<n;i++){
        printf("\nP%d > ",i+1);
        scanf("%d%d",&p[i].arr_time,&p[i].burst_time);
        p[i].id=i+1;

    }
   struct process temp;
    // Sort
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(p[j].arr_time >p[j+1].arr_time){
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
            }
            
        }
        
    }
    c_time[0] = p[0].arr_time +p[0].burst_time ;
    for(int i=1;i<n;i++){
        c_time[i] = c_time[i-1]+p[i].burst_time;
    }
            
    
    
    // Turn around time:
    for(int i=0;i<n;i++){
        t_time[i] = abs(c_time[i]-p[i].arr_time);
    }
    // waiting time
    for(int i=0;i<n;i++){
        waiting_time[i] = abs(t_time[i]-p[i].burst_time);
    }
    
    printf("\nProcess\tArrivalTime\tBurstTime\tTurnaround\tWaitingTime");
    for(int i=0;i<n;i++){
        printf("\nP%d\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",p[i].id, p[i].arr_time ,p[i].burst_time,t_time[i],waiting_time[i]);
        total +=waiting_time[i];
    }
    
    printf("\nTotal waiting time is %d ", total) ;  
 printf("\nAverage waiting time is %d ", total/n) ;  
    
    
}
/*

/tmp/YXlJCACCaU.o
Enter no of process >> 4
Enter the Arrival time and Burst time Below .

P1 > 45 25
P2 > 35 10
3P3 > 35 20
P4 > 30 40
Process	ArrivalTime	BurstTime	Turnaround	WaitingTime
P4			30			40			40			0
P2			35			10			45			35
P3			35			20			65			45
P1			45			25			80			55
Total waiting time is 135 
Average waiting time is 33 
*/