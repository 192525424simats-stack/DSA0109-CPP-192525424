#include <iostream>
using namespace std;

long long calculateFare(int zone, int hour) {
    if (zone < 1 || zone > 3 || hour < 0 || hour > 23)
        return -1;

    long long fare = zone * 1000LL;

    bool peak = (hour >= 8 && hour < 10) ||
                (hour >= 17 && hour < 20);

    if (peak)
        fare += fare * 20 / 100;

    return fare;
}

bool canTravel(long long balance, long long fare) {
    return fare >= 0 && balance >= fare &&
           balance - fare >= 5000;
}

int main() {
    struct Test {
        int zone;
        int hour;
    };

    Test tests[] = {
        {1, 7}, {1, 8}, {1, 10},
        {2, 17}, {2, 20}, {3, 12},
        {4, 12}, {1, -1}
    };

    for (const Test& t : tests) {
        long long f = calculateFare(t.zone, t.hour);

        cout << "Zone " << t.zone
             << ", hour " << t.hour << ": ";

        if (f == -1)
            cout << "Invalid input";
        else
            cout << "Fare Rs " << f / 100
                 << '.' << (f % 100 < 10 ? "0" : "")
                 << f % 100;

        cout << '\n';
    }

    cout << "Balance 6000, fare 1000: "
         << (canTravel(6000, 1000) ? "Allowed" : "Denied")
         << '\n';

    cout << "Balance 5999, fare 1000: "
         << (canTravel(5999, 1000) ? "Allowed" : "Denied")
         << '\n';

    return 0;
}
