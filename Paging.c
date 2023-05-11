#include<stdio.h>
#include<math.h> 
#include<string.h>
void main()
{
    int page_size,
    log_size,
    phy_size,
    no_pages_log,
    no_frames_phy; 
    
    int i,j,check,x,frame_no,frame_alloc[50];
    
    int check_pow_2(int);
    
    char log_content[50][10],phy_content[50][10];;


    do{
        printf("------------------------------------------");
        printf("\n\n\nEnter the page size(power of 2): "); 
        scanf("%d",&page_size);
        
        printf("\n\nEnter the logical memory size(power of 2): "); 
        scanf("%d",&log_size);
        
         printf("\n\nEnter the physical memory size(power of 2): "); 
         scanf("%d",&phy_size);
        printf("------------------------------------------");
        }while((page_size%2!=0) || (log_size%2!=0) ||(phy_size<log_size) ||(phy_size%2!=0));
    
        no_pages_log=log_size/page_size;
        printf("\nNo. of pages in logical memory: %d",no_pages_log);
        no_frames_phy = phy_size/page_size;
        printf("\nNo. of frames in physical memory: %d",no_frames_phy); 
    
    printf("\n\nEnter the contents of logical memory: ");
    x=0;
    for(i=0;i< no_pages_log;i++)
    {
        for(j=0;j<page_size;j++)
        {
            scanf("%s",&log_content[x]); 
            x++;
        }
    
    }

x=0;
printf("\nLOGICAL MEMORY: ");
for(i=0;i<no_pages_log;i++)
{
    printf("\nPAGE%d: ",i);
    j=0;
    for(j=0;j<page_size;j++)
    {
        printf("\n\tLogical address %d: %s",x,log_content[x]);
        x++;
    }
}


for(i=0;i<no_frames_phy;i++)
{
    frame_alloc[i]=0;
}
x=0; 
for(i=0;i<no_pages_log;i++) {
lab3:
    printf("\nEnter frame no for page %d(0-%d): ",i,no_frames_phy); 
    scanf("%d",&frame_no);
    if(frame_no >= no_frames_phy)
    {
        printf("\n%d frame is not available.Enter another frame no.",frame_no); 
        goto lab3;
    }
    if(frame_alloc[frame_no]==0) {
        for(j=0;j<page_size;j++)
    {
     strcpy(phy_content[(frame_no*page_size)+j],log_content[(i*page_size)+j]); 
    x++;
    }
    frame_alloc[frame_no]=1;
}
else
{
    printf("\n%d frame is already allocated. Enter another frame.",frame_no); 
    goto lab3;
}
    
} 
for(i=0;i<no_frames_phy;i++)
{
    if(frame_alloc[i]==0)
{
    for(j=0;j<page_size;j++) {
    strcpy(phy_content[(i*page_size)+j],"-"); }}}
    x=0;
    printf("\nPHYSICAL MEMORY."); 
    for(i=0;i<no_frames_phy;i++)
    {
    printf("\nFRAME%d: ",i); 
    for(j=0;j<page_size;j++)
    {   
    printf("\n\tPhysical Address%d: %s",x,phy_content[(i*page_size)+j]); x++;
    }
    printf("\nPress any key.");
    }
}
