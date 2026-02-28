#ifndef _PATIENT_H
#define _PATIENT_H
#include "Person.h"
#include <vector>
class Visit;

class Patient : public Person
{
private:
    vector <Visit*> visits;
    Patient(const Patient& other);
    Patient(Patient&& other);
public:
    Patient(const string& name, int id, const Date& birthDate, eGender gender);
    
    ~Patient();
    const Patient& operator=(const Patient& other) = delete;
    const Patient& operator=(Patient&& other) = delete;
    const Patient& operator+=(const Visit& other);
    const Patient& operator+=(Visit&& other);
    void toOs(ostream& os) const override;
    friend class Hospital;
};

#endif // !__PATIENT_H
