/* Experiment 1: Convert between 32-bit binary and dotted-decimal IPv4.
   Menu option 1: binary -> dotted decimal
   Menu option 2: dotted decimal -> binary
*/
#include <stdio.h>
#include <string.h>

int main(void) {
    int choice, i, j, value;
    char binary[33];
    int octet[4];

    printf("1. Binary to dotted-decimal\n");
    printf("2. Dotted-decimal to binary\n");
    printf("Enter choice: ");
    if (scanf("%d", &choice) != 1) return 1;

    if (choice == 1) {
        printf("Enter exactly 32 binary bits (no dots): ");
        scanf("%32s", binary);

        if (strlen(binary) != 32) {
            printf("Invalid input: enter exactly 32 bits.\n");
            return 1;
        }

        for (i = 0; i < 32; i++) {
            if (binary[i] != '0' && binary[i] != '1') {
                printf("Invalid binary digit.\n");
                return 1;
            }
        }

        for (i = 0; i < 4; i++) {
            value = 0;
            for (j = 0; j < 8; j++) {
                value = value * 2 + (binary[i * 8 + j] - '0');
            }
            octet[i] = value;
        }

        printf("Dotted-decimal: %d.%d.%d.%d\n",
               octet[0], octet[1], octet[2], octet[3]);
    } else if (choice == 2) {
        printf("Enter IPv4 address (example 192.168.1.10): ");
        if (scanf("%d.%d.%d.%d",
                  &octet[0], &octet[1], &octet[2], &octet[3]) != 4) {
            printf("Invalid format.\n");
            return 1;
        }

        for (i = 0; i < 4; i++) {
            if (octet[i] < 0 || octet[i] > 255) {
                printf("Invalid IPv4 octet: values must be 0-255.\n");
                return 1;
            }
        }

        printf("32-bit binary: ");
        for (i = 0; i < 4; i++) {
            for (j = 7; j >= 0; j--) {
                printf("%d", (octet[i] >> j) & 1);
            }
            if (i < 3) printf(".");
        }
        printf("\n");
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}
