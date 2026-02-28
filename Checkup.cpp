#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Checkup.h"

Checkup::Checkup(const Date& date, const string& purpose, Department* dept, Worker* caregiver)
    : Visit(date, purpose, dept, caregiver)
{
}

void Checkup::toOs(ostream& os) const
{
    os << "Type: Checkup | ";
    Visit::toOs(os);
}
