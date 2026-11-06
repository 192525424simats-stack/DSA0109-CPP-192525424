
#include <iostream>
#include <string>
using namespace std;

class TransactionHistory {
private:
    static const int SIZE = 10;

    string transactions[SIZE];
    int count;
    int nextIndex;

public:
    TransactionHistory() {
        count = 0;
        nextIndex = 0;
    }

    // Add transaction in O(1) time
    void addTransaction(string transaction) {
        transactions[nextIndex] = transaction;

        nextIndex = (nextIndex + 1) % SIZE;

        if (count < SIZE) {
            count++;
        }
    }

    // Display transactions from oldest to newest
    void display() const {
        cout << "\nTransaction History:\n";

        int start = (count == SIZE) ? nextIndex : 0;

        for (int i = 0; i < count; i++) {
            int index = (start + i) % SIZE;

            cout << transactions[index] << '\n';
        }
    }

    int getCount() const {
        return count;
    }
};

int main() {
    TransactionHistory history;

    // Add 12 transactions
    for (int i = 1; i <= 12; i++) {
        history.addTransaction(
            "Transaction " + to_string(i)
        );
    }

    history.display();

    cout << "\nTotal stored transactions: "
         << history.getCount() << '\n';

    return 0;
}

