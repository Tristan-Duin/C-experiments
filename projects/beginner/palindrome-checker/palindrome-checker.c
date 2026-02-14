#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 1000

int is_palindrome( const char *str ) {
    int left = 0;
    int right = strlen( str ) - 1;

    while ( left < right ) {
        while ( left < right && !isalnum( str[left] ) ) left++;
        while ( left < right && !isalnum( str[right] ) ) right--;

        if ( tolower(str[left]) != tolower( str[right] ) ) {
            return 0;
        }

        left++;
        right--;
    }

    return 1;
}

int main() {
    char input[MAX_LEN];

    printf( "Enter a string to check if it's a palindrome:\n" );
    fgets( input, sizeof( input ), stdin );

    size_t len = strlen( input );
    if ( input[len - 1] == '\n' ) {
        input[len - 1] = '\0';
    }

    if ( is_palindrome( input ) ) {
        printf( "\"%s\" is a palindrome!\n", input );
    } else {
        printf( "\"%s\" is not a palindrome.\n", input );
    }

    return 0;
}
