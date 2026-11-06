
#include <iostream>
#include <string>
using namespace std;

class BusTicket {
private:
    static int issued;

    static const int CAPACITY = 3;

    int seat;
    string name;

public:
    BusTicket(string passengerName) {
        name = passengerName;

        if (issued < CAPACITY) {
            issued++;
            seat = issued;
        } else {
            seat = 0;
        }
    }

    static int count() {
        return issued;
    }

    void print() const {
        cout << name << ": ";

        if (seat == 0) {
            cout << "Waiting\n";
        } else {
            cout << "Seat " << seat << '\n';
        }
    }
};

// Definition of static data member
int BusTicket::issued = 0;

void createTickets() {
    BusTicket tickets[4] = {
        BusTicket("Asha"),
        BusTicket("Bala"),
        BusTicket("Chitra"),
        BusTicket("Dev")
    };

    for (int i = 0; i < 4; i++) {
        tickets[i].print();
    }
}

int main() {
    createTickets();

    cout << "Issued: " << BusTicket::count() << '\n';

    return 0;
}

