#include <iostream>
#include <limits>
using namespace std;

int main() {
    int zone = 1;
    bool peak = false;
    char category = 'S';
    double fareExample = 10.20;
    long long balancePaise = 10000;

    cout << "Size of int: " << sizeof(zone) << " bytes\n";
    cout << "Size of bool: " << sizeof(peak) << " bytes\n";
    cout << "Size of char: " << sizeof(category) << " bytes\n";
    cout << "Size of double: " << sizeof(fareExample) << " bytes\n";
    cout << "Size of long long: "
         << sizeof(balancePaise) << " bytes\n";

    cout << "Maximum int: "
         << numeric_limits<int>::max() << '\n';
    cout << "Balance in paise: " << balancePaise << '\n';
    return 0;
}
