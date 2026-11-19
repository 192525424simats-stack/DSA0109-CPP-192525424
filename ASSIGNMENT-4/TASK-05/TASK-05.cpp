#include <iostream>
using namespace std;

class Cart {
private:
    int cartId;
    double total;

public:
    Cart(int id, double amount) {
        cartId = id;
        total = amount;
    }

    Cart& addItem(double price) {
        total += price;
        return *this;
    }

    Cart& removeItem(double price) {
        total -= price;
        return *this;
    }

    void display() {
        cout << "Cart ID: " << cartId << endl;
        cout << "Total Amount: " << total << endl;
    }

    Cart* getPointer() {
        return this;
    }

    double getTotal() {
        return total;
    }
};

int main() {
    Cart c1(101, 500);

    cout << "--- Method Chaining ---" << endl;

    c1.addItem(200).addItem(300).removeItem(100);
    c1.display();

    cout << "\n--- Using this Pointer ---" << endl;

    Cart* ptr = c1.getPointer();
    ptr->display();

    cout << "\n--- Cart Array ---" << endl;

    Cart c2(102, 800);
    Cart c3(103, 1200);

    Cart* carts[3] = {&c1, &c2, &c3};

    int maxIndex = 0;

    for (int i = 1; i < 3; i++) {
        if (carts[i]->getTotal() > carts[maxIndex]->getTotal()) {
            maxIndex = i;
        }
    }

    cout << "Cart with Maximum Total:" << endl;
    carts[maxIndex]->display();

    return 0;
}
