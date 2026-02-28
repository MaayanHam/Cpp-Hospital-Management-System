#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Hospital.h"
#include "Surgeon.h"
void Hospital::setName(const string& name)
{
    this->name = name;
}

Hospital::Hospital(const string& name, const string& researchCenterName):
    name(name),
    researchCenter(researchCenterName)
{
}


const Hospital& Hospital::operator+=(const string& departmentName)
{
    if (departments.size() == departments.capacity())
    {
        departments.reserve(departments.capacity() * 2);
    }
    Department* temp = new Department(departmentName);
    departments.push_back(temp);
    temp->setHospital(this);
    return  *this;
}

ostream& operator<<(ostream& os, const Hospital& hospital)
{
    os <<"HOSPITAL:    " <<  hospital.name << endl;
    cout<<"Departments" << endl;
    for (Department* dep : hospital.departments)
    {
        cout <<  "    " <<  *dep << endl;
    }
    cout << hospital.researchCenter;
    return os;
}

Hospital::~Hospital()
{
    for (Department* dep : departments) delete dep;
    for (Patient* pat : allPatients) delete pat;
    for (Doctor* doc : allDoctors) delete doc;
    for (Nurse* nur : allNurses) delete nur;
}

const Hospital& Hospital::operator+=(Patient& patient)
{
    if (allPatients.size() == allPatients.capacity())
        allPatients.reserve(allPatients.capacity() * 2);

    allPatients.push_back(new Patient(patient));
    return *this;
}

const Hospital& Hospital::operator+=(Worker& worker)
{
    if (Doctor* d = dynamic_cast<Doctor*>(&worker))
    {
        if (allDoctors.size() == allDoctors.capacity())
            allDoctors.reserve(allDoctors.capacity() * 2);
        
        allDoctors.push_back(d);
    }
    else if (Nurse* n = dynamic_cast<Nurse*>(&worker))
    {
        if (allNurses.size() == allNurses.capacity())
            allNurses.reserve(allNurses.capacity() * 2);
        allNurses.push_back(n);
    }
    return *this;
}

Department* Hospital::getDepartmentByName(const string& name) const
{
    for (Department* dep : departments)
    {
        if (dep->getName() == name)
            return dep;
    }
    return nullptr;
}
Patient* Hospital::getPatientByID(int id) const
{
    for (Patient* pat : allPatients)
    {
        if (pat->getIdNum() == id)
            return pat;
    }
    return nullptr;
}
Worker* Hospital::assignAutoCaregiver(const string& deptName, bool isSurgery)
{
    Department* dept = getDepartmentByName(deptName);

    if (dept == nullptr)
    {
        cout << "Error: Department " << deptName << " not found." << endl;
        return nullptr;
    }

    if (isSurgery)
    {
        return dept->getSurgeon();
    }
    return dept->getNextWorker();
}

void Hospital::showAllResearchers()
{
    this->researchCenter.sortResearchers();
    cout << researchCenter << endl;
}

void Hospital::showAllDoctors() const
{
    cout << "--- All Doctors in Hospital ---" << endl;
    for (Doctor* doc : allDoctors)
        cout<<*doc<<endl;
}

void Hospital::showAllNurses() const
{
    cout << "--- All Nurses in Hospital ---" << endl;
    for (Nurse* nur : allNurses)
    {
       cout<<*nur<<endl;
    }
}
void Hospital::showAllSurgeons() const
{
    cout << "--- All Surgeons in Hospital ---" << endl;

    for (Doctor* doc : allDoctors)
    {
        Surgeon* s = dynamic_cast<Surgeon*>(doc);
        if (s != nullptr)
        {
            cout << *s << endl;
        }
    }
}

void Hospital::showPatientsInDepartment(const string& deptName) const
{
    cout << "--- Patients visited in Department: " << deptName << " ---" << endl;
    bool flag = false;

    for (Patient* p : allPatients)
    {
        bool visitedThisDept = false;
        for (Visit* v : p->visits)
        {
            Department* d = v->getDepartment();
            if (d != nullptr && d->getName() == deptName)
            {
                visitedThisDept = true;
                break; 
            }
        }
        if (visitedThisDept)
        {
            cout << *p << endl; 
            flag = true;
        }
    }

    if (!flag)
    {
        cout << "No patients found for this department." << endl;
    }
}
