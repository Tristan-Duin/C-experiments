#include <stdio.h>

typedef struct structures
{
    char * name;
    int age;
} person;

int main() {
    person john;

    john.name = "John";
    john.age = 27;
    printf("%s is %d years old.\n", john.name, john.age);
}