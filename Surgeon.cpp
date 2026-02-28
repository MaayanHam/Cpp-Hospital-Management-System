#include "Surgeon.h"



Surgeon::Surgeon(const string& name, int id, const Date& birthDate, eGender gender, const string& expertise, int numSurgeries)
    : Worker(name, id, birthDate, gender),
    Doctor(name, id, birthDate, gender, expertise),
    surgeriesAmount(numSurgeries)
{
}

void Surgeon::toOs(ostream& os) const
{

    Doctor::toOs(os);
    os << endl << " --- Also a Surgeon---" << endl;
    os << endl << "Surgeon details:" << endl;
    os << "Number of surgeries: " << surgeriesAmount << endl;
}
