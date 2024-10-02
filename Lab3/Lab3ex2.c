#include <stdio.h>

int main() {
    long int *lPtr;
    long int value1 = 200000;
    lPtr = &value1;

    printf("Value of variable pointed to: %ld\n", *lPtr);

    long int value2 = *lPtr;
    printf("Value of value2: %ld\n", value2);
    printf("Address of value1: %p\n", &value1);
    printf("Address stored in lPtr: %p\n", lPtr);

    return 0;
}
