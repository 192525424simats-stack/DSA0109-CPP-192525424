
#include <iostream>
#include <cstdlib>
using namespace std;

class Time {
private:
    int h, m;

public:
    Time(int hh, int mm) {
        h = hh;
        m = mm;
    }

    friend int minutesBetween(const Time&, const Time&);

    friend bool earlier(const Time&, const Time&);

    inline int totalMinutes() const {
        return h * 60 + m;
    }
};

// Friend function to calculate difference
int minutesBetween(const Time& a, const Time& b) {
    return abs(a.totalMinutes() - b.totalMinutes());
}

// Friend function to compare two times
bool earlier(const Time& a, const Time& b) {
    return a.totalMinutes() < b.totalMinutes();
}

int main() {
    Time departure(9, 45);
    Time arrival(13, 10);

    cout << minutesBetween(departure, arrival)
         << " "
         << boolalpha
         << earlier(arrival, departure)
         << '\n';

    Time morning(10, 30);
    Time afternoon(14, 15);

    cout << "Difference: "
         << minutesBetween(morning, afternoon)
         << " minutes\n";

    cout << "Is morning earlier? "
         << earlier(morning, afternoon)
         << '\n';

    Time same1(12, 0);
    Time same2(12, 0);

    cout << "Same time difference: "
         << minutesBetween(same1, same2)
         << " minutes\n";

    cout << "Is first time earlier? "
         << earlier(same1, same2)
         << '\n';

    return 0;
}

