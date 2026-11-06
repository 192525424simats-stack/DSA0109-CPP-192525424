
#include <iostream>
using namespace std;

struct Parcel {
    double weight;
    bool express;
    bool insured;
};

// Default arguments for weight in kg
double charge(double weight,
              bool express = false,
              bool insured = false) {
    double amount = weight * 50;

    if (express) {
        amount += 100;
    }

    if (insured) {
        amount += 50;
    }

    return amount;
}

// Overload for weight in grams
double charge(int grams) {
    double weight = grams / 1000.0;
    return charge(weight);
}

// Overload for Parcel object
double charge(const Parcel& p) {
    return charge(p.weight, p.express, p.insured);
}

int main() {
    Parcel p = {3.0, true, true};

    cout << "Charge for 2 kg: "
         << charge(2) << '\n';

    cout << "Charge for 2.0 kg: "
         << charge(2.0) << '\n';

    cout << "Charge for 2.0f kg: "
         << charge(2.0f) << '\n';

    cout << "Charge for 500 grams: "
         << charge(500) << '\n';

    cout << "Express charge: "
         << charge(2.0, true) << '\n';

    cout << "Parcel charge: "
         << charge(p) << '\n';

    return 0;
}

