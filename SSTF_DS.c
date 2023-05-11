

#include <stdlib.h>

int find_nearest_request(int queue[], int n, int head_pos) {
    int i, nearest = -1, min_distance = 999999;

    // Find the request with the minimum seek time
    for(i = 0; i < n; i++) {
        if(queue[i] != -1) {
            int distance = abs(head_pos - queue[i]);
            if(distance < min_distance) {
                min_distance = distance;
                nearest = i;
            }
        }
    }

    return nearest;
}

int main() {
    int n, i, j, head_pos, total_movement = 0;
    int queue[100], distance[100];

    printf("Enter the number of disk requests: ");
    scanf("%d", &n);

    printf("Enter the disk request queue:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    printf("Enter the initial head position: ");
    scanf("%d", &head_pos);

    // Initialize the seek time and distance arrays
    for(i = 0; i < n; i++) {
        distance[i] = 0;
    }

    // Calculate the seek time and distance for each request
    for(i = 0; i < n; i++) {
        int nearest = find_nearest_request(queue, n, head_pos);
        distance[i] = abs(head_pos - queue[nearest]);
        head_pos = queue[nearest];
        queue[nearest] = -1;
    }

    // Calculate the total distance moved by the head
    for(i = 0; i < n; i++) {
        total_movement += distance[i];
    }

    // Print the results
    printf("\nSSTF Disk Scheduling:\n");
   
    printf("Total head movement: %d\n", total_movement);

    return 0;
}


/*
Enter the number of disk requests: 8
Enter the disk request queue:
98
183
37
122
14
124
65
67
Enter the initial head position: 53
SSTF Disk Scheduling:
Total head movement: 236

*/