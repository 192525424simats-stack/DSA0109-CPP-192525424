#include <iostream>
#include <string>
using namespace std;

// Base class
class Person {
protected:
    string name;
    int id;
    string phone;

public:
    Person(string n, int i, string p)
        : name(n), id(i), phone(p) {}

    void displayPerson() const {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
        cout << "Phone: " << phone << endl;
    }
};

// Student virtually inherits Person
class Student : virtual public Person {
protected:
    string programme;
    double cgpa;

public:
    Student(string n, int i, string p, string prog, double c)
        : Person(n, i, p), programme(prog), cgpa(c) {}

    void displayStudent() const {
        cout << "Programme: " << programme << endl;
        cout << "CGPA: " << cgpa << endl;
    }
};

// Staff virtually inherits Person
class Staff : virtual public Person {
protected:
    string department;
    double salary;

public:
    Staff(string n, int i, string p, string dept, double sal)
        : Person(n, i, p), department(dept), salary(sal) {}

    void displayStaff() const {
        cout << "Department: " << department << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Multiple inheritance
class TeachingAssistant : public Student, public Staff {
public:
    TeachingAssistant(string n, int i, string p,
                     string prog, double c,
                     string dept, double sal)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          Staff(n, i, p, dept, sal) {}

    void display() const {
        cout << "--- Teaching Assistant ---" << endl;
        displayPerson();
        displayStudent();
        displayStaff();
    }
};

// Multilevel inheritance
class ResearchScholar : public Student {
private:
    double fellowship;

public:
    ResearchScholar(string n, int i, string p,
                   string prog, double c, double f)
        : Person(n, i, p),
          Student(n, i, p, prog, c),
          fellowship(f) {}

    void display() const {
        cout << "--- Research Scholar ---" << endl;
        displayPerson();
        displayStudent();
        cout << "Fellowship: " << fellowship << endl;
    }
};

int main() {
    TeachingAssistant ta(
        "Arun", 101, "9876543210",
        "Computer Science", 8.5,
        "CSE", 25000
    );

    ResearchScholar rs(
        "Kavya", 102, "9876543211",
        "Information Technology", 9.0, 15000
    );

    ta.display();
    cout << endl;

    rs.display();

    return 0;
}
