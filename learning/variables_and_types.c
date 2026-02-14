#include <stdio.h>

#define BOOL char
#define FALSE 0
#define TRUE 1

int main() {
    int a = 3;
    float b = 4.5;
    double c = 5.25;
    float sum;

    sum = a + b + c;

    char * printable_string = "Test";

    printf("This is a printable string: %s\n", printable_string);

    printf("a = %i\n", a);
    printf("b = %f\n", b);
    printf("c = %f\n", c);
    printf("The sum of a, b, and c is %f.\n", sum);
    return 0;
}