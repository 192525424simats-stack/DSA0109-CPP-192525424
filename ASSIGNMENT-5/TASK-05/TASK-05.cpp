#include <iostream>
#include <stdexcept>
using namespace std;

void validate(double amount) {
    if (amount < 0)
        throw invalid_argument("negative");

    if (amount > 1e6)
        throw out_of_range("too large");

    cout << "ok ";
}

void process(double amount) {
    try {
        validate(amount);
    }
    catch (const out_of_range& e) {
        cout << "[log " << e.what() << "] ";
        throw;
    }
}

int main() {
    for (double a : {100.0, -5.0, 2e6}) {
        try {
            process(a);
            cout << "done ";
        }
        catch (const exception& e) {
            cout << "caught " << e.what() << ' ';
        }
    }

    cout << endl;

    return 0;
}
