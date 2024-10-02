#include <stdio.h>

int main() {
    int *zPtr; // zPtr will reference array z
    int *aPtr = NULL;
    void *sPtr = NULL;
    int number, i;
    int z[5] = {1, 2, 3, 4, 5};
    zPtr = z;
    sPtr = z;

    /* Use a pointer to get the first value of array */
    number = *zPtr;

    printf("First value of array: %d\n", number);

    /* Assign array element 2 (the value 3) to number */
    number = zPtr[2];

    printf("Third value of array: %d\n", number);

    /* Print the entire array z */
    for (i = 0; i < 5; i++) {
        printf("%d ", zPtr[i]);
    }

    return 0;
}
