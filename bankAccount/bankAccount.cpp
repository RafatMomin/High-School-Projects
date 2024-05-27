#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//@ author Rafat Momin
//date: 02/01/2022
#define MAX_ACCOUNTS 100 // Maximum number of accounts the system can handle

// Structure to represent a bank account
typedef struct {
    int accountNumber;
    char name[100];
    double balance;
} Account;

Account accounts[MAX_ACCOUNTS]; // Array to store all bank accounts
int totalAccounts = 0; // Counter to keep track of the total number of accounts

// Function to create a new account
void createAccount() {
    if (totalAccounts >= MAX_ACCOUNTS) {
        printf("Cannot create more accounts. Maximum limit reached.\n");
        return;
    }

    Account newAccount; // Create a new account object
    newAccount.accountNumber = totalAccounts + 1; // Assign account number

    printf("Enter account holder name: ");
    scanf("%s", newAccount.name); // Read the account holder's name

    newAccount.balance = 0.0; // Initialize balance to 0
    accounts[totalAccounts] = newAccount; // Store the new account in the array
    totalAccounts++; // Increment the total accounts counter

    printf("Account created successfully. Account Number: %d\n", newAccount.accountNumber);
}

// Function to deposit money into an account
void depositMoney() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber); // Read the account number

    if (accountNumber <= 0 || accountNumber > totalAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to deposit: ");
    scanf("%lf", &amount); // Read the amount to deposit

    if (amount < 0) {
        printf("Invalid amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance += amount; // Update the balance
    printf("Amount deposited successfully. New balance: %.2lf\n", accounts[accountNumber - 1].balance);
}

// Function to withdraw money from an account
void withdrawMoney() {
    int accountNumber;
    double amount;

    printf("Enter account number: ");
    scanf("%d", &accountNumber); // Read the account number

    if (accountNumber <= 0 || accountNumber > totalAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    printf("Enter amount to withdraw: ");
    scanf("%lf", &amount); // Read the amount to withdraw

    if (amount < 0 || amount > accounts[accountNumber - 1].balance) {
        printf("Invalid amount.\n");
        return;
    }

    accounts[accountNumber - 1].balance -= amount; // Update the balance
    printf("Amount withdrawn successfully. New balance: %.2lf\n", accounts[accountNumber - 1].balance);
}

// Function to check the balance of an account
void checkBalance() {
    int accountNumber;

    printf("Enter account number: ");
    scanf("%d", &accountNumber); // Read the account number

    if (accountNumber <= 0 || accountNumber > totalAccounts) {
        printf("Invalid account number.\n");
        return;
    }

    // Display the account details
    printf("Account Number: %d\n", accounts[accountNumber - 1].accountNumber);
    printf("Account Holder: %s\n", accounts[accountNumber - 1].name);
    printf("Balance: %.2lf\n", accounts[accountNumber - 1].balance);
}

int main() {
    int choice;

    while (1) {
        // Display menu options
        printf("\nBank Account Management System\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Read user's choice

        // Call the appropriate function based on user's choice
        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                exit(0); // Exit the program
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
