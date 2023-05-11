#include<stdio.h>

int blocks[20],process[20],b,n,arr[20],l;
void best_fit(int item);
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
    
    // best fit
    for(int i=0;i<n;i++){
        best_fit(process[i]);
    }

}

void best_fit(int item){
    int k=0;
    int min=10000,s;
    
    for(int i=0;i<n;i++){
        if((blocks[i]-item) >= 0){
            s = blocks[i]-item;
            if(s<min){
                min=s;
                k = i+1;
            }
        }
        
    }

    if(k!=0){
        blocks[k-1] -= item;
        arr[k-1] += item;       
        for(l=0;l<k-1;l++);
        printf("\nMemory allocated in block : %d ",k-1);
        printf("\nMemory allocated for process %d ", arr[l]);
        
        }
    else{
        printf("\nNo memory block for process %d ",item);
    }
    
    
}
