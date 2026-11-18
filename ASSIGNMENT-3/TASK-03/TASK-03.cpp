#include <iostream>
using namespace std;

class Event {
    int rows;
    int seatsPerRow;
    bool** seats;
    int booked;

public:
    // Dynamic constructor
    Event(int r, int s)
        : rows(r > 0 ? r : 0),
          seatsPerRow(s > 0 ? s : 0),
          seats(nullptr),
          booked(0) {

        if (rows > 0 && seatsPerRow > 0) {

            seats = new bool*[rows];

            for (int i = 0; i < rows; i++) {
                seats[i] = new bool[seatsPerRow]{};
            }
        }

        cout << "Created event ("
             << rows << " x "
             << seatsPerRow << ")\n";
    }

    // Check valid seat
    bool valid(int r, int s) const {
        return seats &&
               r >= 0 && r < rows &&
               s >= 0 && s < seatsPerRow;
    }

    // Book seat
    bool book(int r, int s) {

        if (!valid(r, s) || seats[r][s])
            return false;

        seats[r][s] = true;
        booked++;

        return true;
    }

    // Cancel seat
    bool cancel(int r, int s) {

        if (!valid(r, s) || !seats[r][s])
            return false;

        seats[r][s] = false;
        booked--;

        return true;
    }

    // Destructor
    ~Event() {

        for (int i = 0; i < rows; i++) {
            delete[] seats[i];
        }

        delete[] seats;

        cout << "Closed event; booked seats at closing: "
             << booked << '\n';
    }
};

int main() {

    cout << "Stack object:\n";

    Event mainEvent(2, 3);

    mainEvent.book(0, 1);
    mainEvent.book(1, 2);
    mainEvent.cancel(0, 1);

    cout << "Block object:\n";

    {
        Event blockEvent(1, 2);

        blockEvent.book(0, 0);
    }

    cout << "Heap object:\n";

    Event* heapEvent = new Event(2, 2);

    heapEvent->book(1, 1);

    delete heapEvent;

    cout << "Zero-row object:\n";

    Event emptyEvent(0, 5);

    cout << "Program ending\n";

    return 0;
}
