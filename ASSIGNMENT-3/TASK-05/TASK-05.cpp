#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;

class Time {
    int seconds;

public:
    Time(int s = 0) : seconds(s) {}

    // Prefix increment
    Time& operator++() {
        ++seconds;
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old(*this);
        ++seconds;
        return old;
    }

    // Equality operator
    bool operator==(const Time& t) const {
        return seconds == t.seconds;
    }

    // Less than operator
    bool operator<(const Time& t) const {
        return seconds < t.seconds;
    }

    int value() const {
        return seconds;
    }
};

class Playlist {
    vector<string> tracks;

public:
    Playlist(initializer_list<string> names)
        : tracks(names) {}

    // Non-const subscript operator
    string& operator[](int i) {

        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Playlist index out of range");

        return tracks[i];
    }

    // Const subscript operator
    const string& operator[](int i) const {

        if (i < 0 || i >= (int)tracks.size())
            throw out_of_range("Playlist index out of range");

        return tracks[i];
    }

    int size() const {
        return (int)tracks.size();
    }
};

int main() {

    Time t(5);

    Time a = t++;

    Time b = ++t;

    cout << "a = " << a.value()
         << ", b = " << b.value()
         << ", t = " << t.value() << '\n';

    Playlist playlist{
        "Track One",
        "Track Two",
        "Track Three"
    };

    cout << "playlist[1] = "
         << playlist[1] << '\n';

    try {

        cout << playlist[playlist.size()] << '\n';

    }
    catch (const out_of_range& e) {

        cout << "Range check: "
             << e.what() << '\n';
    }

    Time first(10);
    Time second(12);

    cout << boolalpha
         << "first < second: "
         << (first < second) << '\n';

    return 0;
}
