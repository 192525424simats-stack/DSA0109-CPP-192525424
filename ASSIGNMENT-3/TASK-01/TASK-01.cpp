#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
    string title;
    int copies;
    string author;

    static int validCopies(int n) {
        if (n < 0)
            throw invalid_argument("Number of copies cannot be negative");
        return n;
    }

public:
    // Default constructor
    Book() : Book("Untitled", 0, "Unknown") {}

    // Parameterised constructor
    explicit Book(const string& t)
        : Book(t, 1, "Unknown") {}

    // Overloaded constructor
    Book(const string& t, int c)
        : Book(t, c, "Unknown") {}

    // Full parameterised constructor
    Book(const string& t, int c, const string& a)
        : title(t), copies(validCopies(c)), author(a) {}

    void display() const {
        cout << "Title: " << title
             << ", Copies: " << copies
             << ", Author: " << author << '\n';
    }
};

int main() {
    try {
        Book empty;
        Book donated("The Alchemist");
        Book full("Wings of Fire", 5,
                  "A. P. J. Abdul Kalam");

        empty.display();
        donated.display();
        full.display();

        try {
            Book invalid("Invalid Book", -2, "Unknown");
            invalid.display();
        }
        catch (const invalid_argument& e) {
            cout << "Invalid book rejected: "
                 << e.what() << '\n';
        }
    }
    catch (const exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }

    return 0;
}
