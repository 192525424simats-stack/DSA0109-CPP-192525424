
#include <iostream>
using namespace std;

// Call by value
void changeValue(int a) {
    a += 10;
}

// Call by reference
void changeReference(int& b) {
    b += 10;
}

// Call by pointer
void changePointer(int* c) {
    *c += 10;
}

// Return by reference
int& bigger(int& p, int& q) {
    return (p > q) ? p : q;
}

// Default arguments
void show(int x, int y = 5, int z = 10) {
    cout << x + y + z << " ";
}

// Hostel fee concession using call by value
void applyByValue(long long fee, int percent) {
    fee -= fee * percent / 100;
}

// Hostel fee concession using call by reference
void applyConcession(long long& fee, int percent) {
    fee -= fee * percent / 100;
}

int main() {
    int a = 1, b = 2, c = 3;

    changeValue(a);
    changeReference(b);
    changePointer(&c);

    cout << a << " " << b << " " << c << '\n';

    bigger(a, c) = 100;

    cout << a << " " << c << '\n';

    show(1);
    show(1, 2);
    show(1, 2, 3);
    cout << '\n';

    long long hostelFee = 45000;

    applyByValue(hostelFee, 10);
    cout << "after call by value   : "
         << hostelFee << '\n';

    applyConcession(hostelFee, 10);
    cout << "after call by reference: "
         << hostelFee << '\n';

    return 0;
}

