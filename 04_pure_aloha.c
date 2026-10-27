/* Experiment 4: Simple Pure ALOHA collision simulation.
   Each frame has duration 1 time unit. Enter each station's start time.
   A collision occurs if any two frame intervals overlap.
   For simplicity, frames are not retransmitted in this simulation.
*/
#include <stdio.h>

#define MAX 20
#define FRAME_TIME 1.0

int main(void) {
    int n, i, j, collision;
    double start[MAX], end[MAX];

    printf("Enter number of stations (1-%d): ", MAX);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX) {
        printf("Invalid number of stations.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        printf("Enter start time for station %d: ", i + 1);
        if (scanf("%lf", &start[i]) != 1 || start[i] < 0) {
            printf("Invalid start time.\n");
            return 1;
        }
        end[i] = start[i] + FRAME_TIME;
    }

    for (i = 0; i < n; i++) {
        collision = 0;
        for (j = 0; j < n; j++) {
            if (i != j && start[i] < end[j] && start[j] < end[i]) {
                collision = 1;
                break;
            }
        }

        if (collision)
            printf("Station %d: COLLISION (frame %.2f to %.2f)\n",
                   i + 1, start[i], end[i]);
        else
            printf("Station %d: SUCCESS (frame %.2f to %.2f)\n",
                   i + 1, start[i], end[i]);
    }

    return 0;
}
