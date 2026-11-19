#include <iostream>
#include <string>
using namespace std;

class Bill {
protected:
    string patient;

public:
    Bill(string p) : patient(p) {}

    virtual ~Bill() = default;

    virtual double total() const = 0;
    virtual string type() const = 0;
};

class OutPatient : public Bill {
    double consultation, tests;

public:
    OutPatient(string p, double c, double t)
        : Bill(p), consultation(c), tests(t) {}

    double total() const override {
        return consultation + tests;
    }

    string type() const override {
        return "OP";
    }
};

class InPatient : public Bill {
    int days;
    double rate, surgery;

public:
    InPatient(string p, int d, double r, double s)
        : Bill(p), days(d), rate(r), surgery(s) {}

    double total() const override {
        return days * rate + surgery;
    }

    string type() const override {
        return "IP";
    }
};

class EmergencyBill : public Bill {
    double baseCharge, hourlyCharge;
    int hours;

public:
    EmergencyBill(string p, double b, double h, int hrs)
        : Bill(p), baseCharge(b), hourlyCharge(h), hours(hrs) {}

    double total() const override {
        return baseCharge + hourlyCharge * hours;
    }

    string type() const override {
        return "Emergency";
    }
};

class Payer {
public:
    virtual double amountCovered(const Bill& b) const = 0;
    virtual ~Payer() = default;
};

class SelfPay : public Payer {
public:
    double amountCovered(const Bill& b) const override {
        return b.total();
    }
};

class Insurance : public Payer {
    double limit;

public:
    Insurance(double l) : limit(l) {}

    double amountCovered(const Bill& b) const override {
        return b.total() < limit ? b.total() : limit;
    }
};

class CorporatePayer : public Payer {
    double percentage;

public:
    CorporatePayer(double p) : percentage(p) {}

    double amountCovered(const Bill& b) const override {
        return b.total() * percentage / 100;
    }
};

int main() {
    Bill* bills[] = {
        new OutPatient("Ravi", 500, 1200),
        new InPatient("Meena", 3, 2500, 40000),
        new EmergencyBill("Arun", 5000, 1000, 4)
    };

    Payer* payers[] = {
        new SelfPay(),
        new Insurance(50000),
        new CorporatePayer(80)
    };

    for (Bill* b : bills) {
        cout << b->type() << " Bill: " << b->total() << endl;

        for (Payer* p : payers) {
            cout << "Covered: "
                 << p->amountCovered(*b) << endl;
        }

        cout << endl;
    }

    for (Bill* b : bills)
        delete b;

    for (Payer* p : payers)
        delete p;

    return 0;
}
