#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, i, head, prev, curr, total_distance = 0;


    printf("Enter the number of requests: ");
    scanf("%d", &n);

    int requests[n];
    printf("Enter the requests: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head);

    // Process the requests in the order of arrival
    prev = head;
    for(i = 0; i < n; i++) {
        curr = requests[i];
        total_distance += abs(curr - prev);
        prev = curr;
    }

    // Print the results
    printf("\nFCFS Disk Scheduling:\n");
    printf("Total Head Movement: %d\n", total_distance);

    return 0;
}
/*
Enter the number of requests: 8
Enter the requests: 98
183
37
122
14
124
65
67
Enter the initial head position: 53
    Head movements
        1:0
        2:45
        3:130
        4:276
        5:361
        6:469
        7:579
        8:638

FCFS Disk Scheduling:
Total Head Movement: 640

*/