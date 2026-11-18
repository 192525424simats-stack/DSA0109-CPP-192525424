#include <cstring>
#include <iostream>
using namespace std;

class Text {
    char* data;

public:
    // Constructor
    Text(const char* s = "") {

        data = new char[strlen(s) + 1];

        strcpy(data, s);
    }

    // Copy constructor
    Text(const Text& other) {

        data = new char[strlen(other.data) + 1];

        strcpy(data, other.data);

        cout << "[copy] ";
    }

    // Copy assignment operator
    Text& operator=(const Text& other) {

        if (this != &other) {

            char* temp =
                new char[strlen(other.data) + 1];

            strcpy(temp, other.data);

            delete[] data;

            data = temp;
        }

        return *this;
    }

    // Concatenation using +=
    Text& operator+=(const Text& other) {

        char* temp =
            new char[strlen(data) +
                     strlen(other.data) + 1];

        strcpy(temp, data);

        strcat(temp, other.data);

        delete[] data;

        data = temp;

        return *this;
    }

    // Addition operator
    friend Text operator+(const Text& a,
                          const Text& b) {

        Text result(a);

        result += b;

        return result;
    }

    // Equality operator
    bool operator==(const Text& other) const {

        return strcmp(data, other.data) == 0;
    }

    // Not equal operator
    bool operator!=(const Text& other) const {

        return !(*this == other);
    }

    // Output operator
    friend ostream& operator<<(ostream& out,
                               const Text& t) {

        return out << t.data;
    }

    // Destructor
    ~Text() {

        delete[] data;
    }
};

int main() {

    Text a("Hello");
    Text b(" ");
    Text c("World");

    Text message = a + b + c;

    cout << "\nMessage: " << message << '\n';

    Text empty;

    cout << "Empty text: ["
         << empty << "]\n";

    Text copy = message;

    cout << "Copy: " << copy << '\n';

    // Self-assignment
    copy = copy;

    cout << boolalpha;

    cout << "Equal after self-assignment: "
         << (copy == message) << '\n';

    cout << "Different from empty: "
         << (copy != empty) << '\n';

    return 0;
}
