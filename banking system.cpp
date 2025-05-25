#include <iostream>
#include <vector>
#include <string>

class Account {
private:
    int accountNumber;
    std::string accountHolder;
    double balance;
public:
    Account(int accNum, const std::string& holder, double initialBalance)
        : accountNumber(accNum), accountHolder(holder), balance(initialBalance) {}
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: " << amount << "\nNew Balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << "\nRemaining Balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount or insufficient funds.\n";
        }
    }
    void transfer(Account& toAccount, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            toAccount.balance += amount;
            std::cout << "Transferred: " << amount << "\nYour New Balance: " << balance
                      << "\nRecipient's New Balance: " << toAccount.balance << std::endl;
        } else {
            std::cout << "Invalid transfer amount or insufficient funds.\n";
        }
    }
    void displayAccountInfo() const {
        std::cout << "Account Number: " << accountNumber
                  << "\nAccount Holder: " << accountHolder
                  << "\nBalance: " << balance << std::endl;
    }

    int getAccountNumber() const {
        return accountNumber;
    }
};
class Bank {
private:
    std::vector<Account> accounts;

public:
    void createAccount(int accNum, const std::string& holder, double initialBalance) {
        accounts.emplace_back(accNum, holder, initialBalance);
        std::cout << "Account created successfully.\n";
    }
    Account* findAccount(int accNum) {
        for (auto& acc : accounts) {
            if (acc.getAccountNumber() == accNum) {
                return &acc;
            }
        }
        std::cout << "Account not found.\n";
        return nullptr;
    }
    void displayAllAccounts() const {
        for (const auto& acc : accounts) {
            acc.displayAccountInfo();
            std::cout << "-----------------------------\n";
        }
    }
};

int main() {
    Bank bank;
    int choice, accNum;
    std::string holder;
    double amount;
    do {
        std::cout << "\nBank Management System\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Transfer\n";
        std::cout << "5. Display Account Info\n";
        std::cout << "6. Display All Accounts\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                std::cin.ignore();
                std::cout << "Enter Account Holder Name: ";
                std::getline(std::cin, holder);
                std::cout << "Enter Initial Deposit: ";
                std::cin >> amount;
                bank.createAccount(accNum, holder, amount);
                break;
            case 2:
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                if (Account* acc = bank.findAccount(accNum)) {
                    std::cout << "Enter Deposit Amount: ";
                    std::cin >> amount;
                    acc->deposit(amount);
                }
                break;
            case 3:
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                if (Account* acc = bank.findAccount(accNum)) {
                    std::cout << "Enter Withdrawal Amount: ";
                    std::cin >> amount;
                    acc->withdraw(amount);
                }
                break;
            case 4:
                int toAccNum;
                std::cout << "Enter Your Account Number: ";
                std::cin >> accNum;
                if (Account* fromAcc = bank.findAccount(accNum)) {
                    std::cout << "Enter Recipient Account Number: ";
                    std::cin >> toAccNum;
                    if (Account* toAcc = bank.findAccount(toAccNum)) {
                        std::cout << "Enter Transfer Amount: ";
                        std::cin >> amount;
                        fromAcc->transfer(*toAcc, amount);
                    }
                }
                break;
            case 5:
                std::cout << "Enter Account Number: ";
                std::cin >> accNum;
                if (Account* acc = bank.findAccount(accNum)) {
                    acc->displayAccountInfo();
                }
                break;
            case 6:
                bank.displayAllAccounts();
                break;
            case 7:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);
    
    return 0;
}
