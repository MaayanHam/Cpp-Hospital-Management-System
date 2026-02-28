#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Patient.h"
#include "Visit.h"
#include "Checkup.h"
#include "Surgery.h" 



Patient::Patient(const string& name, int id, const Date& birthDate, eGender gender)
    : Person(name, id, birthDate, gender)
{
}

Patient::Patient(const Patient& other)
    : Person(other)
{
    for (Visit* vis : visits)
    {
        if (Surgery* s = dynamic_cast<Surgery*>(vis))
        {
            visits.push_back(new Surgery (*s));
        }
        else if (Checkup* c = dynamic_cast<Checkup*>(vis))
        {
            visits.push_back(new Checkup (*c));
        }
    }
}


Patient::Patient(Patient&& other)
    : Person(other.name, other.idNum, other.birthDate, other.gender),
    visits(std::move(other.visits))
{
}

const Patient& Patient::operator+=(const Visit& visit)
{
    if (visits.size() == visits.capacity())
    {
        visits.reserve(visits.capacity() * 2);
    }

    if (const Surgery* s = dynamic_cast<const Surgery*>(&visit))
    {
        visits.push_back(new Surgery(*s));
    }
    else if (const Checkup* c = dynamic_cast<const Checkup*>(&visit))
    {
        visits.push_back(new Checkup (*c));
    }

    return *this;
}

const Patient& Patient::operator+=(Visit&& visit)
{
    return *this += visit;
}

void Patient::toOs(ostream& os) const
{
    Person::toOs(os);
    os << endl << "Visits History:" << endl;
    if (visits.size() == 0)
    {
        os << "No visits." << endl;
    }
    else
    {
        for (Visit* vis : visits)
        {
            os << *vis << endl;
        }
    }
}



Patient::~Patient()
{
    for (Visit* vis : visits)
    {
        delete vis;
    }
}
