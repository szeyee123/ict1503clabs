#include <stdio.h>
#include <string.h>

int main() {
    //Variable declarations
    char *a = "abcdef";
    char b[7];
    strcpy(b, a);
    for (int i = 0; i < 3; i++) 
        b[i] = b[i] + 1;
    b[3] = '\0';

    printf("a[0] = %c\n", a[0]);
    printf("b[0] = %c\n", b[0]);
    printf("b[4] = %c\n", b[4]);
    printf("strlen(a) = %c\n", strlen(a));
    printf("strlen(b) = %c\n", strlen(b));
    printf("strcmp(a, b) = %c\n", strcmp(a, b));

    return 0;
}