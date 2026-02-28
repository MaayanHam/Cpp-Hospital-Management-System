#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Worker.h"

int Worker::workersCounter = 1;
Worker::Worker(const string& name, const int idNum, const Date birthDate, const eGender gender) : Person(name, idNum, birthDate, gender), workerID(workersCounter++)
{
    
}

void Worker::toOs(ostream& os) const
{
    os << "worker #" << workerID << " ";
    Person::toOs(os);
}

