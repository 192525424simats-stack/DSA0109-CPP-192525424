#include <iostream>
#include <limits>
using namespace std;

int main() {
    long long journeys[] = {20000, 500000, 3000000};

    cout << "Maximum int: "
         << numeric_limits<int>::max() << '\n';

    for (long long n : journeys) {
        long long totalPaise = n * 1000LL;
        cout << n << " journeys at Rs 10 each = Rs "
             << totalPaise / 100 << '\n';
    }

    double totalDouble = 0.0;
    long long totalIntegerPaise = 0;

    for (int i = 0; i < 100000; ++i) {
        totalDouble += 0.10;
        totalIntegerPaise += 10;
    }

    cout.precision(15);
    cout << "Double total: Rs " << totalDouble << '\n';
    cout << "Integer total: Rs "
         << totalIntegerPaise / 100.0 << '\n';

    return 0;
}
