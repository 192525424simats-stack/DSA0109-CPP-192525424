#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {
        cout << "Person Constructor" << endl;
    }

    virtual ~Person() {
        cout << "Person Destructor" << endl;
    }
};

class Student : virtual public Person {
protected:
    int rollNo;

public:
    Student(string n, int r) : Person(n), rollNo(r) {
        cout << "Student Constructor" << endl;
    }

    ~Student() {
        cout << "Student Destructor" << endl;
    }
};

class Staff : virtual public Person {
protected:
    string department;

public:
    Staff(string n, string d) : Person(n), department(d) {
        cout << "Staff Constructor" << endl;
    }

    ~Staff() {
        cout << "Staff Destructor" << endl;
    }
};

class Address {
public:
    string city;

    Address(string c) : city(c) {
        cout << "Address Constructor" << endl;
    }

    ~Address() {
        cout << "Address Destructor" << endl;
    }
};

class Course {
public:
    string courseName;

    Course(string c) : courseName(c) {
        cout << "Course Constructor" << endl;
    }

    ~Course() {
        cout << "Course Destructor" << endl;
    }
};

class TeachingAssistant : public Student, public Staff {
private:
    Address address;
    Course course;

public:
    TeachingAssistant(string n, int r, string d,
                      string city, string c)
        : Person(n),
          Student(n, r),
          Staff(n, d),
          address(city),
          course(c) {
        cout << "TeachingAssistant Constructor" << endl;
    }

    void display() {
        cout << "\nName: " << name << endl;
        cout << "Roll Number: " << rollNo << endl;
        cout << "Department: " << department << endl;
        cout << "City: " << address.city << endl;
        cout << "Course: " << course.courseName << endl;
    }

    ~TeachingAssistant() {
        cout << "TeachingAssistant Destructor" << endl;
    }
};

int main() {
    TeachingAssistant ta("Arun", 101, "CSE",
                        "Chennai", "Data Structures");

    ta.display();

    return 0;
}
