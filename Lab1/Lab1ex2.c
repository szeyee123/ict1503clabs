#include <stdio.h>

int main() {
    // Variable declarations
    int a = -1;
    int b = 2;
    float x = 0.1;
    float y = 1.5;
    char c = 'p';
    
    // Perform part a
    int resulta = a / b;
    int resultb = a * b;
    int resultc = (b * 3) % 4;
    float resultd = x * a ;
    float resulte = x * y;
    float resultf = y / x;
    char resultg = c - 3;

    // Print the result part a
    printf("The result of a / b is: %d\n", resulta);
    printf("The result of a * b is: %d\n", resultb);
    printf("The result of (b * 3)4 is: %d\n", resultc);
    printf("The result of x * a is: %d\n", resultd);
    printf("The result of x * y is: %d\n", resulte);
    printf("The result of y / x is: %d\n", resultf);
    printf("The result of c - 3 is: %d\n", resultg);
    
    //Print the result part b
    printf("%4d\n", a);
    printf("%04d\n", b);
    printf("a/b = %d\n", a / b);
    printf("%x\n", b);
    printf("%.2f\n", y);
    printf("%10.1f\n", x);
    printf("c =\t%c\n", c);

    return 0;
}