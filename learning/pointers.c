#include <stdio.h>

int main() {
    int n = 10;

    int * pointer_to_n = &n;

    *pointer_to_n += 1;

    if (pointer_to_n != &n) return 1;
    if (*pointer_to_n != 11) return 1;

    printf("Pointer to n: %p\n", pointer_to_n);

    printf("n: %i\n", n);

    *pointer_to_n += 1;

    printf("After *pointer_to_n += 1; : %i\n", n);

    pointer_to_n += 1;

    printf("After pointer_to_n += 1; : %i\n", n);
    printf("After pointer_to_n += 1; %p\n", pointer_to_n);
    printf("Broken pointer that is not referencing n's location in mem anymore:\n");
    printf("After pointer_to_n += 1; %i\n", *pointer_to_n);

    printf("Done!\n");
    return 0;
}