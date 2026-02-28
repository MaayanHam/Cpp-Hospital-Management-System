#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Visit.h"
#include "Department.h" 
#include "Worker.h"


void Visit::setPurpose(const string& purpose)
{
    this->purpose = purpose;
}




Visit::Visit(const Date& arrivalDate, const string& purpose, Department* department, Worker* careGiver)
    : arrivalDate(arrivalDate), purpose(purpose), department(department), careGiver(careGiver)
{
}

void Visit::toOs(ostream& os) const
{
    os << "Date: " << arrivalDate << ", Purpose: " << purpose;
    if (department != nullptr)
        os << ", Dept: " << department->getName();
    if (careGiver != nullptr)
        os << ", Caregiver: " << careGiver->getName();
    else
        os << ", Caregiver: Not assigned yet";
}

std::ostream& operator<<(std::ostream& os, const Visit& visit)
{
    visit.toOs(os);
    return os;
}
