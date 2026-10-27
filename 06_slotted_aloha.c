/* Experiment 6: Slotted ALOHA simulation.
   Enter how many stations attempt transmission in each slot.
   0 = idle slot, 1 = successful transmission, >1 = collision.
*/
#include <stdio.h>

#define MAX 100

int main(void) {
    int slots, attempts[MAX], i;
    int idle = 0, success = 0, collision = 0;

    printf("Enter number of time slots (1-%d): ", MAX);
    if (scanf("%d", &slots) != 1 || slots < 1 || slots > MAX) {
        printf("Invalid number of slots.\n");
        return 1;
    }

    printf("For each slot, enter number of stations attempting to send:\n");
    for (i = 0; i < slots; i++) {
        printf("Slot %d: ", i + 1);
        if (scanf("%d", &attempts[i]) != 1 || attempts[i] < 0) {
            printf("Invalid number of attempts.\n");
            return 1;
        }
    }

    for (i = 0; i < slots; i++) {
        if (attempts[i] == 0) {
            printf("Slot %d: IDLE\n", i + 1);
            idle++;
        } else if (attempts[i] == 1) {
            printf("Slot %d: SUCCESS\n", i + 1);
            success++;
        } else {
            printf("Slot %d: COLLISION (%d stations)\n",
                   i + 1, attempts[i]);
            collision++;
        }
    }

    printf("\nSummary:\n");
    printf("Successful slots: %d\n", success);
    printf("Idle slots: %d\n", idle);
    printf("Collision slots: %d\n", collision);

    return 0;
}
