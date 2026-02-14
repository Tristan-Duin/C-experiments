#include <stdio.h>

void guessNumber(int guess) {
    if ( guess > 555 ) {
        printf( "Your guess: %i is too high\n", guess );
    } else if ( guess < 555) {
        printf( "Your guess: %i is too low\n", guess );
    } else {
        printf( "Your guess: 555 is correct!\n" );
    }
}

int main() {
    guessNumber(500);
    guessNumber(600);
    guessNumber(555);
}