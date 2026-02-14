#include <stdio.h>

char board[3][3];
char current_player = 'X';

void initialize_board() {
    int pos = 1;
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 3; j++ )
            board[i][j] = '0' + pos++;
}

void print_board() {
    printf( "\n" );
    for ( int i = 0; i < 3; i++ ) {
        printf( " %c | %c | %c ", board[i][0], board[i][1], board[i][2] );
        if ( i < 2 ) printf( "\n---|---|---\n" );
    }
    printf( "\n\n" );
}

int make_move( int position ) {
    int row = ( position - 1 ) / 3;
    int col = ( position - 1 ) % 3;

    if ( position < 1 || position > 9 || board[row][col] == 'X' || board[row][col] == 'O' ) {
        return 0; 
    }

    board[row][col] = current_player;
    return 1; 
}

int check_win() {
    for ( int i = 0; i < 3; i++ ) {
        if ( ( board[i][0] == current_player &&
             board[i][1] == current_player &&
             board[i][2] == current_player ) ||
            ( board[0][i] == current_player &&
             board[1][i] == current_player &&
             board[2][i] == current_player ) ) {
            return 1;
        }
    }

    if ( ( board[0][0] == current_player &&
         board[1][1] == current_player &&
         board[2][2] == current_player ) ||
        ( board[0][2] == current_player &&
         board[1][1] == current_player &&
         board[2][0] == current_player ) ) {
        return 1;
    }

    return 0;
}

int is_draw() {
    for ( int i = 0; i < 3; i++ )
        for ( int j = 0; j < 3; j++ )
            if ( board[i][j] != 'X' && board[i][j] != 'O' )
                return 0;
    return 1;
}

void switch_player() {
    current_player = ( current_player == 'X' ) ? 'O' : 'X';
}

int main() {
    int position;

    initialize_board();

    printf( "Welcome to Tic-Tac-Toe!\n" );
    print_board();

    while ( 1 ) {
        printf( "Player %c, enter position (1-9): ", current_player );

        if ( scanf( "%d", &position ) != 1) {
            while ( getchar() != '\n' );
            printf( "Invalid input. Please enter a number between 1 and 9.\n" );
            continue;
        }

        if ( !make_move( position ) ) {
            printf( "Invalid move. Try again.\n" );
            continue;
        }

        print_board();

        if ( check_win() ) {
            printf( "Player %c wins!\n", current_player );
            break;
        }

        if ( is_draw() ) {
            printf( "It's a draw!\n" );
            break;
        }

        switch_player();
    }

    return 0;
}
