/* Experiment 2: Identify IPv4 class from dotted-decimal address. */
#include <stdio.h>

int main(void) {
    int a, b, c, d;

    printf("Enter IPv4 address (example 172.16.5.4): ");
    if (scanf("%d.%d.%d.%d", &a, &b, &c, &d) != 4) {
        printf("Invalid address format.\n");
        return 1;
    }

    if (a < 0 || a > 255 || b < 0 || b > 255 ||
        c < 0 || c > 255 || d < 0 || d > 255) {
        printf("Invalid IPv4 address: each octet must be 0-255.\n");
    } else if (a == 0) {
        printf("First octet 0: special-use address, not ordinary Class A.\n");
    } else if (a >= 1 && a <= 126) {
        printf("Class A\n");
    } else if (a == 127) {
        printf("127.x.x.x is reserved for loopback.\n");
    } else if (a >= 128 && a <= 191) {
        printf("Class B\n");
    } else if (a >= 192 && a <= 223) {
        printf("Class C\n");
    } else if (a >= 224 && a <= 239) {
        printf("Class D (multicast)\n");
    } else {
        printf("Class E (reserved/experimental)\n");
    }

    return 0;
}
