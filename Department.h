#ifndef __DEPARTMENT_H
#define __DEPARTMENT_H
#include <iostream>
using namespace std;
#include "Nurse.h"
#include "Doctor.h"
#include <vector>
class Hospital;


class Department
{
private:
    string name;
    vector <Worker*> workers;
    int appointmentCounter;
    Hospital* hospital;
public:
    Department (const string& name);
    Department (const Department& other);
    Department (Department&& other);
    ~Department ();
    const Department& operator=(const Department& other);
    const Department& operator=(Department&& other);
    const Department& operator+=(Worker& worker);
    friend std::ostream& operator<<(std::ostream& os, const Department& department);
    void setName(const string& name);
    void setHospital(Hospital* hospital);
    const string getName() const { return name; }
    Worker* getNextWorker();
    Worker* getSurgeon();
};

#endif // !__DEPARTMENT_H
