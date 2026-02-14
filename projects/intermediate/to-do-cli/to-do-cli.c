#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define TASK_LEN 256
#define FILENAME "todo.txt"

typedef struct {
    char text[TASK_LEN];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int task_count = 0;

void load_tasks() {
    FILE *file = fopen( FILENAME, "r" );
    if ( !file ) return;

    char line[TASK_LEN + 10];
    while ( fgets( line, sizeof( line ), file ) ) {
        Task t;
        if ( sscanf( line, "[%d] %[^\n]", &t.completed, t.text ) == 2 ) {
            tasks[task_count++] = t;
        }
    }

    fclose( file );
}

void save_tasks() {
    FILE *file = fopen( FILENAME, "w" );
    if ( !file ) return;

    for ( int i = 0; i < task_count; ++i ) {
        fprintf( file, "[%d] %s\n", tasks[i].completed, tasks[i].text );
    }

    fclose( file );
}

void add_task( const char *text ) {
    if ( task_count >= MAX_TASKS ) {
        printf( "Task list is full!\n" );
        return;
    }

    strncpy( tasks[task_count].text, text, TASK_LEN );
    tasks[task_count].completed = 0;
    task_count++;

    printf( "Added: %s\n", text );
}

void list_tasks() {
    if ( task_count == 0 ) {
        printf( "No tasks.\n" );
        return;
    }

    for ( int i = 0; i < task_count; ++i ) {
        printf( "%d. [%c] %s\n", i + 1,
               tasks[i].completed ? 'X' : ' ',
               tasks[i].text );
    }
}

void complete_task( int index ) {
    if ( index < 1 || index > task_count ) {
        printf( "Invalid task number.\n" );
        return;
    }

    tasks[index - 1].completed = 1;
    printf( "Marked task %d as completed.\n", index );
}

void delete_task( int index ) {
    if ( index < 1 || index > task_count ) {
        printf( "Invalid task number.\n" );
        return;
    }

    for ( int i = index - 1; i < task_count - 1; ++i ) {
        tasks[i] = tasks[i + 1];
    }

    task_count--;
    printf( "Deleted task %d.\n", index );
}

void print_help() {
    printf( "Commands:\n" );
    printf( "  add <task description> - Add a new task\n" );
    printf( "  list                   - List all tasks\n" );
    printf( "  done <task number>     - Mark task as completed\n" );
    printf( "  del <task number>      - Delete a task\n" );
    printf( "  help                   - Show this help\n" );
    printf( "  exit                   - Save and exit\n" );
}

int main() {
    char input[300];
    load_tasks();
    printf( "Welcome to To-Do CLI!\n" );
    print_help();

    while ( 1 ) {
        printf( "\n> " );
        if ( !fgets( input, sizeof( input ), stdin ) ) break;

        char command[10];
        char args[280];

        if ( sscanf( input, "%s %[^\n]", command, args ) < 1 ) continue;

        if ( strcmp( command, "add" ) == 0 ) {
            add_task( args );
        } else if ( strcmp( command, "list" ) == 0 ) {
            list_tasks();
        } else if ( strcmp( command, "done" ) == 0 ) {
            int index = atoi( args );
            complete_task( index );
        } else if ( strcmp( command, "del" ) == 0 ) {
            int index = atoi( args );
            delete_task( index );
        } else if ( strcmp( command, "help" ) == 0 ) {
            print_help();
        } else if ( strcmp( command, "exit" ) == 0 ) {
            save_tasks();
            break;
        } else {
            printf( "Unknown command. Type 'help' for a list of commands.\n" );
        }
    }

    return 0;
}
