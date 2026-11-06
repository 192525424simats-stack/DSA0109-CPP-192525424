
#include <iostream>
#include <string>
using namespace std;

class SavingsAccount {
private:
    int accountNumber;
    double balance;

    string transactions[10];
    int count;
    int nextIndex;

public:
    SavingsAccount(int accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
        nextIndex = 0;
    }

    void addTransaction(string transaction);

    void deposit(double amount);

    void withdraw(double amount);

    void miniStatement();
};

// Function defined outside the class
void SavingsAccount::addTransaction(string transaction) {
    transactions[nextIndex] = transaction;

    nextIndex = (nextIndex + 1) % 10;

    if (count < 10) {
        count++;
    }
}

void SavingsAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        addTransaction("Deposit: " + to_string(amount));
    }
}

void SavingsAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        addTransaction("Withdraw: " + to_string(amount));
    } else {
        cout << "Insufficient balance or invalid amount\n";
    }
}

void SavingsAccount::miniStatement() {
    cout << "\nAccount Number: " << accountNumber;
    cout << "\nBalance: " << balance << '\n';

    cout << "Last transactions:\n";

    int start = (count == 10) ? nextIndex : 0;

    for (int i = 0; i < count; i++) {
        int index = (start + i) % 10;
        cout << transactions[index] << '\n';
    }
}

int main() {
    SavingsAccount account(1001, 5000);

    account.deposit(1000);
    account.withdraw(500);
    account.deposit(200);
    account.withdraw(100);

    // Add more transactions to test the array
    for (int i = 1; i <= 10; i++) {
        account.deposit(i * 100);
    }

    account.miniStatement();

    return 0;
}

