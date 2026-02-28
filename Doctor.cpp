#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Doctor.h"


void Doctor::setExpertise(const string& expertise)
{
    this->expertise = expertise;
}
Doctor::Doctor(const string& name, const int idNum, const Date& birthDate, const eGender gender, const string& expertise)
    : Worker(name, idNum, birthDate, gender),
    department(nullptr),
    expertise(expertise)

{
}
void Doctor::toOs(ostream& os) const
{
    Worker::toOs(os);
    os << " and is an expert in " << expertise;
}

