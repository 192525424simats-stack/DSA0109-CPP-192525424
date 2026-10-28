#include <iostream>
using namespace std;

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance >= fare &&
           balance - fare >= 5000;
}

int main() {
    long long balance = 10000;
    long long fare = 2000;

    if (canTravel(balance, fare)) {
        balance -= fare;
        cout << "Travel allowed\n";
    } else {
        cout << "Travel denied\n";
    }

    cout << "Balance: Rs " << balance / 100 << '\n';
    return 0;
}
