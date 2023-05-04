#ifndef HEAP_PERSON_H
#define HEAP_PERSON_H

#include "Date.h"
#include "HeapType.h"

class Person {
public:
    Person() = default;
    Person(std::string date, std::string name);
    Person(const Person& from);
    Date date;
    std::string name;
    std::string notation();

    friend std::ostream& operator<<(std::ostream& out, Person person);

    bool compare(const Person& other, HeapType condition, bool amIBigger, int id, int otherId);
    bool operator==(const Person& other);
};

Person::Person(const Person& from) {
    name = from.name;
    date = from.date;
}

Person::Person(std::string date, std::string name) : date(Date(date)), name(name) {}

std::string Person::notation() {
    return date.notation() + ' ' +name;
}

std::ostream &operator<<(std::ostream &out, Person person) {
    out << person.notation();
    return out;
}

bool Person::compare(const Person &other, HeapType condition, bool amIBigger, int id, int otherId) {
    if(condition == name_first) {
        if(amIBigger) return name < other.name;
        return name > other.name;
    }
    if(amIBigger) return date > other.date;
    return date < other.date;
}

bool Person::operator==(const Person& other) {
    bool canBe = true;
    if(name != other.name) return false;
    if(date != other.date) return false;
    return true;
}

#endif //HEAP_PERSON_H
