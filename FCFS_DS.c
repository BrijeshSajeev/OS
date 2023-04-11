#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n, i, head, prev, curr, total_distance = 0;
    bool direction; // true for right, false for left

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
