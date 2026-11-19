#include <iostream>
#include <vector>
using namespace std;

class Bill {
public:
    virtual double total() const = 0;
    virtual ~Bill() = default;
};

class OPBill : public Bill {
    double consultation, tests;

public:
    OPBill(double c, double t) : consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }
};

class IPBill : public Bill {
    int days;
    double rate, surgery;

public:
    IPBill(int d, double r, double s)
        : days(d), rate(r), surgery(s) {}

    double total() const override {
        return days * rate + surgery;
    }
};

struct SimpleBill {
    int type;
    double a, b, c;

    double total() const {
        switch (type) {
            case 1:
                return a + b;

            case 2:
                return a * b + c;

            default:
                return 0;
        }
    }
};

int main() {
    vector<Bill*> virtualBills;
    vector<SimpleBill> switchBills;

    for (int i = 0; i < 10; i++) {
        if (i % 2 == 0) {
            virtualBills.push_back(new OPBill(500, 1200));
            switchBills.push_back({1, 500, 1200, 0});
        }
        else {
            virtualBills.push_back(new IPBill(3, 2500, 40000));
            switchBills.push_back({2, 3, 2500, 40000});
        }
    }

    double virtualTotal = 0;
    double switchTotal = 0;

    for (Bill* b : virtualBills)
        virtualTotal += b->total();

    for (const SimpleBill& b : switchBills)
        switchTotal += b.total();

    cout << "Virtual Total: " << virtualTotal << endl;
    cout << "Switch Total: " << switchTotal << endl;

    for (Bill* b : virtualBills)
        delete b;

    return 0;
}
