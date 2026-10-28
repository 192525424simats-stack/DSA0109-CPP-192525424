#include <iostream>
using namespace std;

constexpr int INNER_FARE = 10;
constexpr int MIDDLE_FARE = 20;
constexpr int OUTER_FARE = 30;
constexpr int MIN_BALANCE = 50;

enum class Zone {
    Inner,
    Middle,
    Outer
};

int main() {
    cout << "Inner fare: Rs " << INNER_FARE << '\n';
    cout << "Middle fare: Rs " << MIDDLE_FARE << '\n';
    cout << "Outer fare: Rs " << OUTER_FARE << '\n';
    cout << "Minimum remaining balance: Rs "
         << MIN_BALANCE << '\n';
    return 0;
}
