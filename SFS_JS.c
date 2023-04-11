
#include<stdio.h>
#include<stdlib.h>

struct process{
    int id;
    int burst_time;
};

void swap(struct process *p1,struct process *p2){
    struct process temp = *p1;
    *p1=*p2;
    *p2=temp;
}
void main(){
    int n;
    int total =0;
    printf("\nEnter no of process >> ");
    scanf("%d",&n);
    int waiting_time[n];
    struct process p[n];
    printf("\nEnter the brust time Below .\n");
    for(int i=0;i<n;i++){
        printf("\nP%d > ",i+1);
        scanf("%d",&p[i].burst_time);
        p[i].id=i+1;
    }
   
   for(int i=0;i<n-1;i++){
       for(int j=0;j<n-i-1;j++){
           if(p[j].burst_time > p[j+1].burst_time){
               swap(&p[j],&p[j+1]);
           }
       }
   }
   
    
   waiting_time[0]=0;
   for(int i=1;i<n;i++){
        waiting_time[i] = p[i-1].burst_time+waiting_time[i-1];
    }
    
    
    
    printf("\nProcess\tBurstTime\tWaitingTime");
    for(int i=0;i<n;i++){
        printf("\nP%d\t\t\t%d\t\t\t%d",p[i].id,p[i].burst_time,waiting_time[i]);
        total +=waiting_time[i];
    }
    
    printf("\nAverage waiting time is %d ", total) ;   
    printf("\nAverage waiting time is %d ", total/n) ;  
    
    
}
