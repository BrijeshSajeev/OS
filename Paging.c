// Online C compiler to run C program online
#include <stdio.h>
#include<string.h>
int main() {
  int page_size,
      logical_mem_size,
      physical_mem_size;
   int no_pages_log,
        no_frames_phy;
    int frame_no,frame_alloc[50],x,i,j;
    char log_mem_content[50][10],
        phy_mem_content[50][10];
    
    // Part 1
        
    do{
        printf("\n\nEnter Page Size (in pow 2) >> ");
        scanf("%d",&page_size);
        
        printf("\n\nEnter Logical memory Size (in pow 2) >> ");
        scanf("%d",&logical_mem_size);
        
        printf("\n\nEnter Physical memory Size (in pow 2) >> ");
        scanf("%d",&physical_mem_size);
    }while((page_size%2!=0) || (logical_mem_size%2!=0) || (physical_mem_size < logical_mem_size) || (physical_mem_size%2!=0));        
    no_pages_log = logical_mem_size/page_size;
    printf("\nNo of pages in logical memoery is %d ",no_pages_log);
    no_frames_phy=physical_mem_size/page_size;
    printf("\nNo of frames in physical memoery is %d ",no_frames_phy);
    
    // part 2
    printf("\nEnter the page Content ;) \n");
    x=0;
    for(i=0;i<no_pages_log;i++){
        for(j=0;j<page_size;j++){
            printf("\nPage content[%d] > ",x);
            scanf("%s",&log_mem_content[x]); 
            x++;
        }
    }
    
    x=0;
    printf("PAGE CONTENT");
    for(i=0;i<page_size;i++){
        printf("\nPage %d : ",i);
        for(j=0;j<no_pages_log;j++){
            printf("\n\tLogical address %d: %s",x,log_mem_content[x]);
            x++;
            
        }
    }
    // part 3
    for(i=0;i<no_frames_phy;i++){
        frame_alloc[i] =0;
    }
    
    
    for(i=0;i<no_pages_log;i++){
        lab:
            printf("\nEnter frame no for page %d(0-%d): ",i,no_frames_phy);
            scanf("%d",&frame_no);
            if(frame_no >= no_frames_phy){
                printf("\nEnter proper frame no .");
                goto lab;
            }
            if(frame_alloc[frame_no]==0){
                for(j=0;j<page_size;j++){
                strcpy(phy_mem_content[(frame_no*page_size)+j],log_mem_content[(i*page_size)+j]);
                }
                frame_alloc[frame_no]=1;
            }
            else{
                printf("\nframe no already ocupied");
                goto lab;
            }
        
    }
    
    
    
for(i=0;i<no_frames_phy;i++)
{
    if(frame_alloc[i]==0)
    {
        for(j=0;j<page_size;j++)
        {
            strcpy(phy_mem_content[(i*page_size)+j],"-");
        }
    }
}

    
    printf("\n\nPHYSICAL ADDRESS");
    x=0;
    for(i=0;i<no_frames_phy;i++){
        printf("\nFRAME %d : ",i);
        for(j=0;j<page_size;j++){
            printf("\nFrame Content %d : %s ",x,phy_mem_content[x]);
            x++;
        }
    }
    
    
    return 0;
}