// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>

int n,max_eaters,no_eat;
char status[20],p_name[20][20],han[10];

// Functions
void print_status();
void putdown(int j);
void pickup(int i);
void test(int i);

int main() {
    int c,round,k,pos;
    printf("\nEnter no of philoshopers >>  ");scanf("%d",&n);
    max_eaters=n/2;
    printf("\nOnly %d philoshopres can eat now \n",max_eaters);
    printf("\nEnter the phil name >> ");
    for(int i=0;i<n;i++){
        scanf("%s",p_name[i]);
    }
    printf("\nPOSITION\tNAME");
    for(int i=0;i<n;i++){
        printf("\n%d\t\t\t%s",i,p_name[i]);
        status[i]='t';
    }
    
    
    // part 2
    while(1){
        printf("\nROUND %d\t",round);
        print_status();
        no_eat=0;
        
        for(int j=0;j<n;j++){
            if(status[j]=='h'){
                pickup(j);
                if(status[j]=='e'){
                    no_eat++;
                }
            }    
        }
        
        // part 3
        
        printf("\nEnter %d no of phil to eat .",(max_eaters-no_eat));
        for(int i=0;i<(max_eaters-no_eat);i++){
            lab:
                printf("\nEnter hungery phil %d ",i+1);
                scanf("%s",han);
                for(int j=0;j<n;j++){
                    k=strcmp(p_name[j],han);
                    if(k==0)
                    {
                        pos=j;
                        break;
                    }
                }
                pickup(pos);
                if(status[pos]=='h')
                    goto lab;
        }
        
        // part 4 (printing current status)
        print_status();
        for(int i=0;i<n;i++){
            if(status[i]=='e'){
                putdown(i);
            }
        }
        printf("\nEnter 1 to continue for next round >> ");
        scanf("%d",&c);
        if(c!=1){
            break;
        }
        round++;
    }
    
    return 0;
}
void pickup(int i){
    status[i]='h';
    test(i);
}
void putdown(int j){
    status[j]='t';
}
void test(int i){
    // i+(n-1)%n = if i=0,n=4,=> 0+(3)%4=3 =>left side
    // (i+1)%n  = 0+1%4 = 1 => right side

    if(status[(i+(n-1))%n]!='e' && status[(i+1)%n]!='e' && status[i]!='e'){
        status[i]='e';
    }
    if(status[i]!='e')
        printf("\n%s must wait since her neighbour is eating",p_name[i]);
    else if(status[i]=='e')
        printf("\nHungry philosopher %s is granted to eat",p_name[i]);
    
}



void print_status(){
    printf("\nCURRENT STATUS\nPHILNAME\tSTATUS");
    for(int i=0;i<n;i++){
        printf("\n%s\t\t\t%c",p_name[i],status[i]);
        
    }
}

