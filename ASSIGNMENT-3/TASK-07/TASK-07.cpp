#include <cmath>
#include <iostream>
#include <stdexcept>
using namespace std;

class Complex {
    double real;
    double imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Single parameter constructor
    Complex(double r) : real(r), imag(0) {}

    // Two parameter constructor
    Complex(double r, double i)
        : real(r), imag(i) {}

    // Addition operator
    Complex operator+(const Complex& z) const {

        return Complex(
            real + z.real,
            imag + z.imag
        );
    }

    // Subtraction operator
    Complex operator-(const Complex& z) const {

        return Complex(
            real - z.real,
            imag - z.imag
        );
    }

    // Multiplication operator
    Complex operator*(const Complex& z) const {

        return Complex(
            real * z.real - imag * z.imag,
            real * z.imag + imag * z.real
        );
    }

    // Division operator
    Complex operator/(const Complex& z) const {

        double denominator =
            z.real * z.real + z.imag * z.imag;

        if (denominator == 0.0)
            throw runtime_error(
                "division by zero impedance"
            );

        return Complex(
            (real * z.real + imag * z.imag)
                / denominator,

            (imag * z.real - real * z.imag)
                / denominator
        );
    }

    // Equality operator
    bool operator==(const Complex& z) const {

        return real == z.real &&
               imag == z.imag;
    }

    // Magnitude calculation
    double magnitude() const {

        return sqrt(real * real + imag * imag);
    }

    // Output operator
    friend ostream& operator<<(ostream& out,
                               const Complex& z) {

        out << z.real;

        if (z.imag >= 0)
            out << " + j" << z.imag;
        else
            out << " - j" << -z.imag;

        return out;
    }
};

int main() {

    // Resistor impedance
    Complex resistor(10, 0);

    // Inductor impedance
    Complex inductor(0, 5);

    // Capacitor impedance
    Complex capacitor(0, -10);

    // Series impedance
    Complex series =
        resistor + inductor + capacitor;

    cout << "Series impedance: "
         << series << '\n';

    cout << "Series magnitude: "
         << series.magnitude() << '\n';

    // Parallel impedance
    Complex z1(10, 5);
    Complex z2(0, -10);

    Complex parallel =
        (z1 * z2) / (z1 + z2);

    cout << "Parallel impedance: "
         << parallel << '\n';

    cout << "Parallel magnitude: "
         << parallel.magnitude() << '\n';

    // Division by zero test
    try {

        Complex invalid =
            z1 / Complex(0, 0);

        cout << invalid << '\n';
    }
    catch (const runtime_error& e) {

        cout << "Safe error: "
             << e.what() << '\n';
    }

    return 0;
}
