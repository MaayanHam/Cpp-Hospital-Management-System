#ifndef __HOSPITAL_H
#define __HOSPITAL_H
#include <iostream>
using namespace std;
#include "Department.h"
#include "ResearchCenter.h"
#include"Patient.h"
#include"Doctor.h"
#include"Nurse.h"
#include "Visit.h"
class Department;
class Hospital
{
private:
	string name;
	ResearchCenter researchCenter;
	vector <Department*> departments;
    vector <Patient*> allPatients;
    vector<Doctor*> allDoctors;
    vector<Nurse*> allNurses;
public:
    Hospital (const string& name, const string& researchCenterName);
    Hospital (const Hospital& other) = delete;
    Hospital (Hospital&& other) = delete;
    ~Hospital ();
    
    const Hospital& operator=(const Hospital& other) = delete;
    const Hospital& operator=(Hospital&& other) = delete;
    
    const Hospital& operator+=(const string& departmentName);
    const Hospital& operator+=(Patient& patient);
    const Hospital& operator+=(Worker& worker);

    void setName(const string& name);
    Department* getDepartmentByName(const string& name) const;
    Patient* getPatientByID(int id) const;
    ResearchCenter& getResearchCenter() { return researchCenter; }
    Worker* assignAutoCaregiver(const string& deptName, bool isSurgery = false);
    void showAllResearchers();
    void showAllDoctors() const;
    void showAllNurses() const;
    void showAllSurgeons() const;
    void showPatientsInDepartment(const string& deptName) const;
    friend std::ostream& operator<<(std::ostream& os, const Hospital& hospital);

};

#endif // !__HOSPITAL_H
