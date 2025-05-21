#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BankAccount {
    int accountNumber;
    char name[100];
    float balance;
};

void createAccount(struct BankAccount *account) {
    printf("Enter Account Number: ");
    scanf("%d", &account->accountNumber);
    printf("Enter Account Holder Name: ");
    getchar(); // to consume newline
    fgets(account->name, sizeof(account->name), stdin);
    account->name[strcspn(account->name, "\n")] = 0; // remove newline
    account->balance = 0.0;
    printf("Account created successfully!\n");
}

void displayAccount(struct BankAccount account) {
    printf("\n--- Account Details ---\n");
    printf("Account Number: %d\n", account.accountNumber);
    printf("Name: %s\n", account.name);
    printf("Balance: ?%.2f\n", account.balance);
}

void deposit(struct BankAccount *account) {
    float amount;
    printf("Enter amount to deposit: ?");
    scanf("%f", &amount);
    if (amount > 0) {
        account->balance += amount;
        printf("Amount deposited successfully!\n");
    } else {
        printf("Invalid amount!\n");
    }
}

void withdraw(struct BankAccount *account) {
    float amount;
    printf("Enter amount to withdraw: ?");
    scanf("%f", &amount);
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Amount withdrawn successfully!\n");
    } else {
        printf("Insufficient balance or invalid amount!\n");
    }
}

int main() {
    struct BankAccount account;
    int choice;
    int accountCreated = 0;

    do {
        printf("\n==== Banking System Menu ====\n");
        printf("1. Create Account\n");
        printf("2. View Account\n");
        printf("3. Deposit Money\n");
        printf("4. Withdraw Money\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createAccount(&account);
                accountCreated = 1;
                break;
            case 2:
                if (accountCreated)
                    displayAccount(account);
                else
                    printf("No account found! Please create one.\n");
                break;
            case 3:
                if (accountCreated)
                    deposit(&account);
                else
                    printf("No account found! Please create one.\n");
                break;
            case 4:
                if (accountCreated)
                    withdraw(&account);
                else
                    printf("No account found! Please create one.\n");
                break;
            case 5:
                printf("Thank you for using the banking system. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Try again!\n");
        }
    } while (choice != 5);

    return 0;
}
