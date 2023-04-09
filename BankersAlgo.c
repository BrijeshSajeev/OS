#include<stdio.h>

int np,nr;
int allocation[10][10],max[10][10],avail[10],need[10][10];

void read_matrix(int mat[10][10]){

    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

void display_matrix(int mat[10][10]){
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }

}

void calc_need(){
    for(int i=0;i<np;i++){
        for(int j=0;j<nr;j++){
            need[i][j] = max[i][j]-allocation[i][j];
        }
    }

}

void bankers(){
    // Checks the process is finished or not (0 or 1)
    int finish[10];

    int safe_seq[10];
    int flag,k=0;
    for(int i=0;i < np; i++)
        finish[i]=0; //Initilally all the process are zero

    for(int i=0;i<np;i++){
        flag=0;

        if(finish[i]==0){
            for (int j = 0; j < nr; j++)
            {
                if(need[i][j] > avail[j]){
                    flag=1;
                    break;
                }
            }


            if(flag==0){
                finish[i]=1;
                safe_seq[k]=i;
                k++;
                // Add allocated resourses to available space

                for(int j=0;j<nr;j++)
                    avail[j] += allocation[i][j];
                
                // Start checking from the initial position or process
                i=-1;

            }
        }
    }

    // check all the proess are completed
    flag=0;
    for (int i = 0; i < np; i++)
    {
        if (finish[i]==0)
        {
            printf("\nThe System is in dead lock...");
            flag=1;
            break;
        }
        
    }

    if(flag==0){
        printf("\nThe Sysytem is in safe State \n The safe sequence is >> ");
        for (int i = 0; i < np; i++)
        {
            printf("P%d ",safe_seq[i]);
        }
        
    }

    



}



int main(){

    printf("\nNo of Process > ");
    scanf("%d",&np);
    printf("\nNo of Resources > ");
    scanf("%d",&nr);
    printf("\nEnter initial Allocation matrix :) \n");
    read_matrix(allocation);
    printf("\nEnter MAX requirment matrix :) \n");
    read_matrix(max);

    printf("\nEnter the available space :)  \n");
    for(int i=0;i<nr;i++){
        scanf("%d",&avail[i]);
    }

    // Display The Details
    printf("\n ALLOCATION MATRIX");
    display_matrix(allocation);
    printf("\n MAX MATRIX");
    display_matrix(max);

    

    // CALCUATE THE NEED
     calc_need();
     printf("\n NEED MATRIX");
     display_matrix(need);

    bankers();

    return 0;
}