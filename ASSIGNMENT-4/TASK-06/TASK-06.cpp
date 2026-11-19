#include <iostream>
using namespace std;

class Vehicle {
protected:
    int days;

public:
    Vehicle(int d) {
        days = d;
    }

    virtual double calculateRent() = 0;

    virtual void display() {
        cout << "Rental Days: " << days << endl;
        cout << "Rental Amount: " << calculateRent() << endl;
    }

    virtual ~Vehicle() {}
};

class Bicycle : public Vehicle {
public:
    Bicycle(int d) : Vehicle(d) {}

    double calculateRent() override {
        return days * 200;
    }
};

class TwoWheeler : public Vehicle {
public:
    TwoWheeler(int d) : Vehicle(d) {}

    double calculateRent() override {
        return days * 400;
    }
};

class Car : public Vehicle {
public:
    Car(int d) : Vehicle(d) {}

    double calculateRent() override {
        return days * 2000;
    }
};

class ElectricCar : public Car {
public:
    ElectricCar(int d) : Car(d) {}

    double calculateRent() override {
        return days * 3500;
    }
};

class ElectricBus : public Vehicle {
public:
    ElectricBus(int d) : Vehicle(d) {}

    double calculateRent() override {
        return days * 7500;
    }
};

int main() {
    Bicycle bicycle(2);
    TwoWheeler bike(2);
    Car car(2);
    ElectricCar electricCar(2);
    ElectricBus electricBus(2);

    Vehicle* vehicles[5] = {
        &bicycle,
        &bike,
        &car,
        &electricCar,
        &electricBus
    };

    cout << "--- Vehicle Rental System ---" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "\nVehicle " << i + 1 << endl;
        vehicles[i]->display();
    }

    return 0;
}
