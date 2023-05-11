#!/bin/sh


Sorting(){
    v=$1

    awk 'BEGIN{
        printf("\nEnter no of elements >> ");
        getline n;
        printf("\nEnter the elements below\n");
        for(i=0;i<n;i++){
            getline s[i];
        }
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(s[j] '$v' s[j+1] ){
                    t=s[j];
                    s[j]=s[j+1];
                    s[j+1] =t;
                }
            }
        }

        printf("\nThe Sorted Elements are \n");
        for(i=0;i<n;i++){
            printf(" %d ",s[i]);
        }
        printf("\n");

    }'
}

ch=1
while [ $ch -ne 0 ]
do
    echo "1 . Ascending oreder"
    echo "2 . Descending Order"
    echo "3 . Exit "
    read -p "Enter your choice >> " ch
    case $ch in
    1) Sorting ">";;
    2) Sorting "<";;
    3) echo "You are on exit"
    esac
done
