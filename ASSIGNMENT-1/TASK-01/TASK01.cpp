#include <iostream>
using namespace std;

class FareTable {
public:
    int getFare(int zone) {
        switch (zone) {
            case 1: return 10;
            case 2: return 20;
            case 3: return 30;
            default: return -1;
        }
    }
};

class SmartCard {
private:
    int balance;

public:
    SmartCard(int amount) : balance(amount) {}

    bool deduct(int fare) {
        if (fare < 0 || balance - fare < 50)
            return false;

        balance -= fare;
        return true;
    }

    int getBalance() const {
        return balance;
    }
};

int main() {
    FareTable table;
    SmartCard card(100);

    int fare = table.getFare(1);

    if (fare != -1 && card.deduct(fare))
        cout << "Travel allowed\n";
    else
        cout << "Travel denied\n";

    cout << "Balance: Rs " << card.getBalance() << '\n';
    return 0;
}
