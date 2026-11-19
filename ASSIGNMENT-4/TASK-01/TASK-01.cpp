#include <iostream>
#include <string>
using namespace std;

// Base class
class Staff {
protected:
    string name;
    int id;
    double basic;

public:
    Staff(string n, int i, double b)
        : name(n), id(i), basic(b) {}

    virtual double pay() const = 0;

    void display() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Pay: " << pay() << endl;
    }

    virtual ~Staff() {}
};

// Derived class: Professor
class Professor : public Staff {
private:
    double research;

public:
    Professor(string n, int i, double b, double r)
        : Staff(n, i, b), research(r) {}

    double pay() const override {
        return basic + basic * 0.42 + research;
    }
};

// Derived class: LabAssistant
class LabAssistant : public Staff {
public:
    LabAssistant(string n, int i, double b)
        : Staff(n, i, b) {}

    double pay() const override {
        return basic + basic * 0.42;
    }
};

// Derived class: GuestFaculty
class GuestFaculty : public Staff {
private:
    double hours;
    double rate;

public:
    GuestFaculty(string n, int i, double h, double r)
        : Staff(n, i, 0), hours(h), rate(r) {}

    double pay() const override {
        return hours * rate;
    }
};

int main() {
    Professor p("Arun", 101, 50000, 10000);
    LabAssistant l("Kavya", 102, 30000);
    GuestFaculty g("Ravi", 103, 20, 1000);

    Staff* staff[3] = {&p, &l, &g};

    cout << "--- Staff Payroll ---" << endl;

    for (int i = 0; i < 3; i++) {
        staff[i]->display();
        cout << endl;
    }

    return 0;
}
