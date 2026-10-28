#include <iostream>
using namespace std;

class FareTable {
public:
    int calculateFare(int zone, bool peak) {
        int fare;

        switch (zone) {
            case 1: fare = 1000; break;
            case 2: fare = 2000; break;
            case 3: fare = 3000; break;
            default: return -1;
        }

        if (peak)
            fare += fare * 20 / 100;

        return fare;
    }
};

class SmartCard {
private:
    long long balance;

public:
    SmartCard(long long amount) : balance(amount) {}

    bool deductFare(int fare) {
        if (fare < 0 || balance - fare < 5000)
            return false;

        balance -= fare;
        return true;
    }

    long long getBalance() const {
        return balance;
    }
};

int main() {
    FareTable table;
    SmartCard card(10000);

    int fare = table.calculateFare(1, false);

    if (card.deductFare(fare))
        cout << "Travel allowed\n";
    else
        cout << "Travel denied\n";

    cout << "Balance: Rs " << card.getBalance() / 100 << '\n';

    return 0;
}
