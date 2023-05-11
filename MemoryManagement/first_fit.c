
#include<stdio.h>

int blocks[20],process[20],b,n,arr[20],l;
void first_fit(int item);

void main(){

    printf("\nEnter no of free blocks >> ");
    scanf("%d",&b);
    for(int i=0;i<b;i++){
        printf("Enter the size of block %d > ",i);
        scanf("%d",&blocks[i]);
        arr[i]=0;
    }
    
    printf("\nEnter no of process >> ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\nEnter the process %d > ",i);
        scanf("%d",&process[i]);
    }
    
    // First fit
    for(int i=0;i<n;i++){
        first_fit(process[i]);
    }

    
}

void first_fit(int item){
    int k=0;
    for(int i=0;i<n;i++){
        if(blocks[i] >= item){
            arr[i] += item;
            printf("\nMEMORY ALLOCATED IN BLOCK : %d",i);
            for(l=0;l<i;l++);
            
            printf("\nMemory allocated for process : %d ",arr[l]);
            blocks[i] -= item;
            k=1;
            break;
        }
        
    }
    
    if(k==0)
        printf("\nNo matching block for %d ",item);
    
    
    
}
