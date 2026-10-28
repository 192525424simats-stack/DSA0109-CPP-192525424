#include <iostream>
using namespace std;

enum class Zone {
    Inner = 1,
    Middle,
    Outer,
    Airport
};

class FareTable {
public:
    long long calculate(Zone zone, bool peak, bool weekend) const {
        long long fare;

        switch (zone) {
            case Zone::Inner:   fare = 1000; break;
            case Zone::Middle:  fare = 2000; break;
            case Zone::Outer:   fare = 3000; break;
            case Zone::Airport: fare = 6000; break;
            default: return -1;
        }

        if (weekend) {
            fare -= fare * 10 / 100;
        } else if (peak) {
            fare += fare * 20 / 100;
        }

        return fare;
    }
};

class MonthlyPass {
private:
    Zone firstZone;
    Zone secondZone;
    bool active;

public:
    MonthlyPass(Zone first, Zone second)
        : firstZone(first), secondZone(second), active(true) {}

    bool covers(Zone zone) const {
        return active &&
               (zone == firstZone || zone == secondZone);
    }

    void deactivate() {
        active = false;
    }
};

int main() {
    FareTable fares;

    cout << "Airport normal fare: Rs "
         << fares.calculate(Zone::Airport, false, false) / 100.0
         << '\n';

    cout << "Airport peak fare: Rs "
         << fares.calculate(Zone::Airport, true, false) / 100.0
         << '\n';

    cout << "Airport weekend fare: Rs "
         << fares.calculate(Zone::Airport, false, true) / 100.0
         << '\n';

    MonthlyPass pass(Zone::Inner, Zone::Middle);

    cout << "Pass covers Inner: "
         << (pass.covers(Zone::Inner) ? "Yes" : "No") << '\n';

    cout << "Pass covers Airport: "
         << (pass.covers(Zone::Airport) ? "Yes" : "No") << '\n';

    return 0;
}
