#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Nurse.h"


Nurse::Nurse(const string& name, const int idNum, const Date birthDate, const eGender gender, int yearsOfExperience)
    : Worker(name, idNum, birthDate, gender),
    yearsOfExperience(yearsOfExperience),
    department(nullptr)

{
   
}

void Nurse::toOs(ostream& os) const
{
    Worker::toOs(os);
    os << " and have " << yearsOfExperience << " years of experience";
}

