#include "Person.h"

Person::Person(std::string n, int a) : name(n), age(a) {}

bool Person::operator<(const Person& other) const {
    return age < other.age;
}