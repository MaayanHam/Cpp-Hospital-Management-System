#ifndef __VISIT_H
#define __VISIT_H

#include <iostream>
using namespace std;
#include "Date.h"
#include <string>

class Department;
class Worker;

class Visit
{
protected:     
    const Date arrivalDate;
    string purpose;
    Department* department;
    Worker* careGiver;
    Visit(const Date& arrivalDate, const string& purpose, Department* department, Worker* careGiver);
public:
    virtual ~Visit() = default;
    void setPurpose(const string& purpose);
    Department* getDepartment() const { return department; }
    virtual void toOs(ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Visit& visit);
};


#endif// !__VISIT_H
