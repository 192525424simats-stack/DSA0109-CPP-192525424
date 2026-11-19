#include <iostream>
using namespace std;

class Account {
protected:
    double balance;

public:
    Account(double b) {
        balance = b;
    }

    double rate() {
        return 3.5;
    }

    virtual double vrate() {
        return 3.5;
    }

    virtual ~Account() {
        cout << "Account Destructor" << endl;
    }
};

class SeniorAccount : public Account {
public:
    SeniorAccount(double b) : Account(b) {}

    double vrate() override {
        return 4.0;
    }

    ~SeniorAccount() {
        cout << "SeniorAccount Destructor" << endl;
    }
};

int main() {
    Account* a = new SeniorAccount(10000);

    cout << "Non-virtual rate: " << a->rate() << endl;
    cout << "Virtual rate: " << a->vrate() << endl;

    delete a;

    SeniorAccount s(20000);
    Account base = s;

    cout << "Base object rate: " << base.rate() << endl;
    cout << "Base object virtual rate: " << base.vrate() << endl;

    return 0;
}
