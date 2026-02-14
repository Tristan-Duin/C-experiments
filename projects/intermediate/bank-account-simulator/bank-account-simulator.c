#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int account_number;
    char name[100];
    double balance;
} BankAccount;

void display_menu() {
    printf( "\n=== Bank Account Menu ===\n" );
    printf( "1. Deposit\n" );
    printf( "2. Withdraw\n" );
    printf( "3. Check Balance\n" );
    printf( "4. Exit\n");
    printf( "Enter your choice: " );
}

void deposit( BankAccount *account, double amount ) {
    if ( amount <= 0 ) {
        printf( "Amount must be positive.\n" );
        return;
    }
    account->balance += amount;
    printf( "\n\tDeposited $%.2f successfully.\n", amount );
}

void withdraw( BankAccount *account, double amount ) {
    if ( amount <= 0 ) {
        printf( "\n\tAmount must be positive.\n" );
        return;
    }
    if ( amount > account->balance ) {
        printf( "\n\tInsufficient funds.\n" );
        return;
    }
    account->balance -= amount;
    printf( "\n\tWithdrew $%.2f successfully.\n", amount );
}

void check_balance( BankAccount *account ) {
    printf( "\n\tAccount Holder: %s\n", account->name );
    printf( "\tAccount Number: %d\n", account->account_number );
    printf( "\tCurrent Balance: $%.2f\n", account->balance );
}

int main() {
    BankAccount account;
    int choice;
    double amount;

    printf( "Enter your name: " );
    fgets( account.name, sizeof( account.name ), stdin );
    size_t len = strlen( account.name );
    if ( account.name[len - 1] == '\n' ) {
        account.name[len - 1] = '\0';
    }

    printf( "Enter account number: " );
    scanf( "%d", &account.account_number );

    printf( "Enter starting balance: $" );
    scanf( "%lf", &account.balance );

    do {
        display_menu();
        scanf( "%d", &choice );

        switch ( choice ) {
            case 1:
                printf( "Enter amount to deposit: $" );
                scanf( "%lf", &amount );
                deposit( &account, amount );
                break;
            case 2:
                printf( "Enter amount to withdraw: $" );
                scanf( "%lf", &amount );
                withdraw( &account, amount );
                break;
            case 3:
                check_balance( &account );
                break;
            case 4:
                printf( "\n\tExiting. Thank you!\n" );
                break;
            default:
                printf( "Invalid choice. Try again.\n" );
        }

    } while ( choice != 4 );

    return 0;
}
