#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    string name;
    int age;

public:
    Person() : name(""), age(0) {}
    Person(string name, int age) : name(name), age(age) {}
    Person(const Person& other) : name(other.name), age(other.age) {}
    Person getOlder(const Person& other) const {
        return (other.age > this->age) ? other : *this;
    }

    void getInfo() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Apartment {
private:
    double area;
    int floor;
    vector<Person> residents;

public:
    Apartment() : area(0.0), floor(0) {}
    Apartment(double area, int floor) : area(area), floor(floor) {}
    Apartment(const Apartment& other) : area(other.area), floor(other.floor), residents(other.residents) {}

    void addResident(const Person& person) {
        residents.push_back(person);
    }

    void getInfo() const {
        cout << "Area: " << area << " square meters, Floor: " << floor << endl;
        cout << "Residents:" << endl;
        for (const auto& resident : residents) {
            resident.getInfo();
        }
    }
};

int main() {
    Person person1("John", 25);
    Person person2("Alice", 30);
    Person person3("Bob", 28);

    Apartment apartment1(100.0, 5);
    apartment1.addResident(person1);
    apartment1.addResident(person2);

    cout << "Apartment 1:" << endl;
    apartment1.getInfo();

    Apartment apartment2 = apartment1;
    apartment2.addResident(person3);

    cout << "\nApartment 2 (copied from Apartment 1):" << endl;
    apartment2.getInfo();

    cout << "\nOlder person in Apartment 1:" << endl;
    Person olderPerson = person1.getOlder(person2);
    olderPerson.getInfo();

    return 0;
}
