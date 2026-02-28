#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Person.h"

const char* genderStr[] = {"male", "female"};

void Person::setName(const string& name)
{
    this->name = name;
}



Person::Person (const string& name, const int idNum, const Date birthDate, const eGender gender) : name(name), idNum(idNum), birthDate(birthDate), gender(gender)
{
}

void Person::toOs(ostream& os) const
{
    os << name << "'s ID is " << idNum << " and is a " << genderStr[(int)gender] << " and was born in " << birthDate;
}

std::ostream& operator<<(std::ostream& os, const Person& person)
{
    person.toOs(os);
    return os;
}
