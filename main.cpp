#pragma warning (disable: 4996)
#include <iostream>
#include <string>
using namespace std;

#include "Hospital.h"
#include "Department.h"
#include "Doctor.h"
#include "Nurse.h"
#include "Patient.h"
#include "Visit.h"
#include "Researcher.h"
#include "Article.h"
#include "Date.h"
#include "Surgeon.h"
#include "Surgery.h"
#include "Checkup.h"
#include "DoctorResearcher.h"

void initHardCodedData(Hospital& hospital);
void initHardCodedData2(Hospital& hospital);
Date inputDate(const string& msg);
Person::eGender inputGender();
void case1(Hospital& hospital);
void case2(Hospital& hospital);
void case3(Hospital& hospital);
void case4(Hospital& hospital);
void case5(Hospital& hospital);
void case6(Hospital& hospital);
void case7(Hospital& hospital);
void case8(Hospital& hospital);
void case9(Hospital& hospital);
void case10(Hospital& hospital);
void case11(Hospital& hospital);

int main()
{
    Hospital hospital("Tel-Hashomer", "Big-Research-Center");

    initHardCodedData2(hospital);

    int choice;

    do
    {
        cout << "\n=== Hospital Management System ===" << endl;
        cout << "1.  Add Department" << endl;
        cout << "2.  Add Nurse" << endl;
        cout << "3.  Add Doctor / Surgeon / Doctor-Researcher" << endl;
        cout << "4.  Add Patient Visit" << endl;
        cout << "5.  Add Researcher" << endl;
        cout << "6.  Add Article to Researcher" << endl;
        cout << "7.  Show Patients in specific Department" << endl;
        cout << "8.  Show all Medical Staff" << endl;
        cout << "9.  Show all Researchers" << endl;
        cout << "10. Show all Surgeons" << endl;
        cout << "11. Search Patient by ID" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: case1(hospital); break;
        case 2: case2(hospital); break;
        case 3: case3(hospital); break;
        case 4: case4(hospital); break;
        case 5: case5(hospital); break;
        case 6: case6(hospital); break;
        case 7: case7(hospital); break;
        case 8: case8(hospital); break;
        case 9: case9(hospital); break;
        case 10: case10(hospital); break;
        case 11: case11(hospital); break;
        case 12: cout << "Goodbye.\n"; break;
        default: cout << "Invalid option.\n";
        }
    } while (choice != 12);

    return 0;
}

Date inputDate(const string& msg)
{
    int d, m, y;
    cout << msg << " (format: DD MM YYYY): ";
    cin >> d >> m >> y;
    return Date(d, m, y);
}

Person::eGender inputGender()
{
    int choice;
    cout << "Enter Gender (0 - Male, 1 - Female): ";
    cin >> choice;
    if (choice == 1) return Person::eGender::FEMALE;
    return Person::eGender::MALE;
}

void case1(Hospital& hospital)
{
    string deptName;
    cout << "Enter Department Name: ";
    cin >> deptName;
    hospital += deptName;
    cout << "Department added successfully.\n";
}

void case2(Hospital& hospital)
{
    string nurseName;
    string deptName;
    cout << "--- Enter Nurse Details ---" << endl;
    cout << "Name: "; cin >> nurseName;
    int id; cout << "ID Number: "; cin >> id;
    Date birthDate = inputDate("Birth Date");
    Person::eGender gen = inputGender();
    int yearsExp; cout << "Years of Experience: "; cin >> yearsExp;
    cout << "To Which Department: "; cin >> deptName;

    Department* dept = hospital.getDepartmentByName(deptName);
    if (dept == nullptr)
    {
        cout << "Error: Department not found!" << endl;
    }
    else
    {
        Nurse n(nurseName, id, birthDate, gen, yearsExp);
        *dept += n;
        cout << "Nurse added successfully.\n";
    }
}

void case3(Hospital& hospital)
{
    string doctorName;
    string specialty;
    string deptName;

    cout << "--- Enter Doctor Details ---" << endl;
    cout << "Type (1 - Regular Doctor, 2 - Surgeon, 3 - Doctor-Researcher): ";
    int docType; cin >> docType;

    cout << "Name: "; cin >> doctorName;
    int id; cout << "ID Number: "; cin >> id;
    Date birthDate = inputDate("Birth Date");
    Person::eGender gen = inputGender();
    cout << "Specialty: "; cin >> specialty;

    cout << "To Which Department: "; cin >> deptName;
    Department* dept = hospital.getDepartmentByName(deptName);

    if (dept == nullptr)
    {
        cout << "Error: Department not found!" << endl;
    }
    else
    {
        if (docType == 2)
        {
            int numSurgeries;
            cout << "Number of Surgeries performed: "; cin >> numSurgeries;
            Surgeon s(doctorName, id, birthDate, gen, specialty, numSurgeries);
            *dept += s;
            cout << "Surgeon added successfully.\n";
        }
        else if (docType == 3)
        {
            DoctorResearcher dr(doctorName, id, birthDate, gen, specialty);
            *dept += dr;
            hospital.getResearchCenter() += dr;
            cout << "Doctor-Researcher added successfully to both.\n";
        }
        else
        {
            Doctor d(doctorName, id, birthDate, gen, specialty);
            *dept += d;
            cout << "Doctor added successfully.\n";
        }
    }
}

void case4(Hospital& hospital)
{
    string patientName;
    string deptName;
    string purpose;
    int id;

    cout << "--- New Visit Entry ---" << endl;
    cout << "Enter Patient ID: "; cin >> id;

    Patient* p = hospital.getPatientByID(id);
    if (p == nullptr)
    {
        cout << "Patient not found. Registering new patient...\n";
        cout << "Name: "; cin >> patientName;
        Date birthDate = inputDate("Birth Date");
        Person::eGender gen = inputGender();
        Patient newP(patientName, id, birthDate, gen);
        hospital += newP;
        p = hospital.getPatientByID(id);
    }

    cout << "Enter Department Name for visit: "; cin >> deptName;
    Department* dept = hospital.getDepartmentByName(deptName);

    if (dept == nullptr)
    {
        cout << "Error: Department not found!\n";
    }
    else
    {
        Date arrival = inputDate("Date of Visit");
        cout << "Visit Type (1 - Checkup, 2 - Surgery): ";
        int type; cin >> type;

        Worker* caregiver = hospital.assignAutoCaregiver(deptName, type == 2);

        if (caregiver == nullptr)
        {
            cout << "Error: No workers available in this department!" << endl;
            return;
        }

        if (type == 2)
        {
            int room;
            bool fast;
            cout << "Surgery Room: "; cin >> room;
            cout << "Fasting (1-Yes, 0-No): "; cin >> fast;

            if (Surgeon* surg = dynamic_cast<Surgeon*>(caregiver))
            {
                Surgery s(arrival, "Surgery", dept, surg, room, fast);
                *p += s;
                cout << "Surgery visit added successfully.\n";
            }
            else
            {
                cout << "Warning: Auto-assigned caregiver is not a Surgeon. Assigning generic Doctor.\n";
                Surgery s(arrival, "Surgery", dept, caregiver, room, fast);
                *p += s;
            }
        }
        else
        {
            cout << "Purpose: "; cin >> purpose;
            Checkup c(arrival, purpose, dept, caregiver);
            *p += c;
            cout << "Checkup visit added successfully.\n";
        }
    }
}

void case5(Hospital& hospital)
{
    string researcherName;
    string specialty;
    string deptName;

    cout << "--- Enter Researcher Details ---" << endl;
    cout << "Name: "; cin >> researcherName;
    int id; cout << "ID Number: "; cin >> id;
    Date birthDate = inputDate("Birth Date");
    Person::eGender gen = inputGender();

    char isDoc;
    cout << "Is this researcher also a doctor? (y/n): ";
    cin >> isDoc;

    if (isDoc == 'y' || isDoc == 'Y')
    {
        cout << "Specialty: "; cin >> specialty;
        cout << "To Which Department: "; cin >> deptName;
        Department* dept = hospital.getDepartmentByName(deptName);

        if (dept == nullptr)
        {
            cout << "Error: Department not found. Cannot add as Doctor.\n";
        }
        else
        {
            DoctorResearcher dr(researcherName, id, birthDate, gen, specialty);
            hospital.getResearchCenter() += dr;
            *dept += dr;
            cout << "Researcher-Doctor added successfully.\n";
        }
    }
    else
    {
        Researcher r(researcherName, id, birthDate, gen);
        hospital.getResearchCenter() += r;
        cout << "Researcher added successfully\n";
    }
}

void case6(Hospital& hospital)
{
    string articleName;
    string magazineName;
    int id;
    cout << "Enter Researcher ID: "; cin >> id;
    Researcher* r = hospital.getResearchCenter().getResearcherByID(id);
    if (r == nullptr)
    {
        cout << "Error: Researcher not found.\n";
    }
    else
    {
        cout << "Article Name: "; cin >> articleName;
        cout << "Magazine Name: "; cin >> magazineName;
        Date pubDate = inputDate("Publication Date");
        Article art(articleName, magazineName, pubDate);
        *r += art;
        cout << "Article added successfully!\n";
    }
}

void case7(Hospital& hospital)
{
    string deptName;
    cout << "Enter Department Name: "; cin >> deptName;
    hospital.showPatientsInDepartment(deptName);
}

void case8(Hospital& hospital)
{
    hospital.showAllDoctors();
    hospital.showAllNurses();
}

void case9(Hospital& hospital)
{
    hospital.showAllResearchers();
}

void case10(Hospital& hospital)
{
    hospital.showAllSurgeons();
}

void case11(Hospital& hospital)
{
    int id;
    cout << "Enter ID to search: "; cin >> id;
    Patient* p = hospital.getPatientByID(id);
    if (p) cout << *p << endl;
    else cout << "Patient not found.\n";
}

void initHardCodedData(Hospital& hospital)
{
    hospital += "Cardiology";
    hospital += "Neurology";

    Department* d1 = hospital.getDepartmentByName("Cardiology");
    Department* d2 = hospital.getDepartmentByName("Neurology");

    Doctor doc1("Dr. House", 111, Date(1, 1, 1975), Person::eGender::MALE, "Diagnostics");
    Surgeon surg1("Dr. Strange", 333, Date(2, 2, 1980), Person::eGender::MALE, "Brain", 150);
    Nurse nurse1("Nurse Joy", 222, Date(5, 5, 1990), Person::eGender::FEMALE, 5);

    if (d1)
    {
        *d1 += doc1;
        *d1 += surg1;
    }
    if (d2) *d2 += nurse1;

    Patient p1("Yaron", 123456789, Date(10, 10, 1980), Person::eGender::MALE);
    hospital += p1;
}

void initHardCodedData2(Hospital& hospital)
{
    hospital += "Cardiology";
    hospital += "Neurology";
    hospital += "Emergency";

    Department* deptCardio = hospital.getDepartmentByName("Cardiology");
    Department* deptNeuro = hospital.getDepartmentByName("Neurology");
    Department* deptER = hospital.getDepartmentByName("Emergency");

    Doctor docCardio("Dr. Mike", 1001, Date(10, 1, 1980), Person::eGender::MALE, "Heart Rhythm");
    Nurse nurseCardio("Nurse Sarah", 2001, Date(5, 5, 1990), Person::eGender::FEMALE, 5);

    if (deptCardio)
    {
        *deptCardio += docCardio;
        *deptCardio += nurseCardio;
    }

    Surgeon surgNeuro("Dr. Strange", 3001, Date(2, 2, 1975), Person::eGender::MALE, "Brain Surgery", 150);
    Doctor docNeuro("Dr. Grey", 1002, Date(15, 3, 1985), Person::eGender::FEMALE, "Nerves");

    if (deptNeuro)
    {
        *deptNeuro += surgNeuro;
        *deptNeuro += docNeuro;
    }

    Nurse nurseER("Nurse Ratched", 2002, Date(1, 1, 1965), Person::eGender::FEMALE, 25);
    if (deptER)
    {
        *deptER += nurseER;
    }

    Patient p1("Yaron Dvir", 123456789, Date(20, 10, 1995), Person::eGender::MALE);
    Patient p2("Dana Cohen", 987654321, Date(12, 12, 1988), Person::eGender::FEMALE);
    Patient p3("Israel Israeli", 112233445, Date(1, 4, 1950), Person::eGender::MALE);

    hospital += p1;
    hospital += p2;
    hospital += p3;

    Patient* pPtr1 = hospital.getPatientByID(123456789);
    if (pPtr1 && deptCardio)
    {
        Worker* caregiver = hospital.assignAutoCaregiver("Cardiology", false);
        if (caregiver) {
            Checkup c1(Date(1, 1, 2024), "Chest Pain", deptCardio, caregiver);
            *pPtr1 += c1;
        }
    }

    Patient* pPtr2 = hospital.getPatientByID(987654321);
    if (pPtr2 && deptNeuro)
    {
        Worker* caregiver = hospital.assignAutoCaregiver("Neurology", true);
        if (caregiver) {
            Surgery s1(Date(15, 1, 2024), "Brain Tumor Removal", deptNeuro, caregiver, 5, true);
            *pPtr2 += s1;
        }
    }

    Patient* pPtr3 = hospital.getPatientByID(112233445);
    if (pPtr3 && deptER)
    {
        Worker* caregiver = hospital.assignAutoCaregiver("Emergency", false);
        if (caregiver) {
            Checkup c2(Date(10, 2, 2024), "High Fever", deptER, caregiver);
            *pPtr3 += c2;
        }
    }

    Researcher r1("Prof. Einstein", 5001, Date(14, 3, 1879), Person::eGender::MALE);
    Researcher r2("Marie Curie", 5002, Date(7, 11, 1867), Person::eGender::FEMALE);

    hospital.getResearchCenter() += r1;
    hospital.getResearchCenter() += r2;

    Researcher* rPtr1 = hospital.getResearchCenter().getResearcherByID(5001);
    if (rPtr1)
    {
        Article a1("Theory of Relativity", "Science Weekly", Date(1, 1, 1905));
        Article a2("Photoelectric Effect", "Physics Today", Date(5, 6, 1906));
        *rPtr1 += a1;
        *rPtr1 += a2;
    }
}
