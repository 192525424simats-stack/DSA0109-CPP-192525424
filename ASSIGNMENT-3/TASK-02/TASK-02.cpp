#include <iostream>
#include <string>
using namespace std;

class Prescription {
    int n;
    string* medicines;

public:
    // Parameterised constructor
    explicit Prescription(int count)
        : n(count),
          medicines(count > 0 ? new string[count] : nullptr) {}

    // Deep copy constructor
    Prescription(const Prescription& other)
        : n(other.n),
          medicines(n > 0 ? new string[n] : nullptr) {

        for (int i = 0; i < n; i++) {
            medicines[i] = other.medicines[i];
        }

        cout << "[copy constructor] ";
    }

    // Copy assignment operator
    Prescription& operator=(const Prescription& other) {
        if (this == &other)
            return *this;

        string* temp =
            other.n > 0 ? new string[other.n] : nullptr;

        for (int i = 0; i < other.n; i++) {
            temp[i] = other.medicines[i];
        }

        delete[] medicines;

        medicines = temp;
        n = other.n;

        cout << "[copy assignment] ";

        return *this;
    }

    // Destructor
    ~Prescription() {
        delete[] medicines;
    }

    void set(int i, const string& m) {
        if (i >= 0 && i < n)
            medicines[i] = m;
    }

    string get(int i) const {
        if (i >= 0 && i < n)
            return medicines[i];

        return "";
    }

    int size() const {
        return n;
    }
};

void receiveByValue(Prescription p) {
    cout << "value parameter received; ";
}

void receiveByReference(const Prescription& p) {
    cout << "const reference received; ";
}

int main() {
    Prescription p(2);

    p.set(0, "Paracetamol");
    p.set(1, "ORS");

    Prescription q = p;

    q.set(1, "Cetirizine");

    Prescription r(1);

    r = p;

    p.set(0, "Ibuprofen");

    // Self-assignment test
    r = r;

    cout << '\n';

    cout << p.get(0) << ' '
         << p.get(1) << " | ";

    cout << q.get(0) << ' '
         << q.get(1) << " | ";

    cout << r.get(0) << ' '
         << r.get(1) << '\n';

    receiveByValue(p);

    receiveByReference(p);

    cout << "\nCopies are independent; "
         << "self-assignment is safe.\n";

    return 0;
}
