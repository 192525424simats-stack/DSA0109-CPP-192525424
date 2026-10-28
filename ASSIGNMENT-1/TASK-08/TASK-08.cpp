#include <iomanip>
#include <iostream>
#include <limits>
using namespace std;

int main() {
    int zone, hour;
    long long balance;

    cout << "Enter zone (1-3): ";
    if (!(cin >> zone) || zone < 1 || zone > 3) {
        cout << "Invalid zone\n";
        return 1;
    }

    cout << "Enter hour (0-23): ";
    if (!(cin >> hour) || hour < 0 || hour > 23) {
        cout << "Invalid hour\n";
        return 1;
    }

    cout << "Enter balance in rupees: ";
    if (!(cin >> balance) || balance < 0) {
        cout << "Invalid balance\n";
        return 1;
    }

    int fare = zone * 1000;
    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare += fare * 20 / 100;

    cout << fixed << setprecision(2);
    cout << "Fare: Rs " << fare / 100.0 << '\n';
    cout << "Balance: Rs " << balance << '\n';

    return 0;
}
