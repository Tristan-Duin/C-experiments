#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Simple shell compiled with wsl for these includes
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT 1024
#define MAX_ARGS 64

void shell_loop() {
    char input[MAX_INPUT];
    char *args[MAX_ARGS];
    char *token;
    pid_t pid;
    int status;

    while (1) {
        printf( "masked-shell> " );
        fflush( stdout );

        if ( fgets( input, sizeof( input ), stdin ) == NULL ) {
            printf( "\n" );
            break; 
        }

        input[strcspn( input, "\n" )] = '\0';

        if ( strcmp( input, "exit" ) == 0 ) {
            break;
        }

        int i = 0;
        token = strtok( input, " " );
        while ( token != NULL && i < MAX_ARGS - 1 ) {
            args[i++] = token;
            token = strtok( NULL, " " );
        }
        args[i] = NULL;

        if ( args[0] == NULL ) {
            continue;
        }

        pid = fork();

        if ( pid < 0 ) {
            perror( "fork" );
        } else if ( pid == 0 ) {
            execvp( args[0], args );
            perror( "execvp" );
            exit( EXIT_FAILURE );
        } else {
            waitpid( pid, &status, 0 );
        }
    }
}

int main() {
    printf( "Welcome to masked-shell (type 'exit' to quit)\n" );
    shell_loop();
    return 0;
}
