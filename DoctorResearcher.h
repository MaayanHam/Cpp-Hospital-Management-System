#ifndef __RESEARCHER_DOCTOR_H
#define __RESEARCHER_DOCTOR_H

#include "Researcher.h"
#include "Doctor.h"
class ResearchCenter;
class DoctorResearcher : public Researcher, public Doctor
{
private:
    DoctorResearcher(const DoctorResearcher& other) = default;
    DoctorResearcher(DoctorResearcher&& other) = default;
public:
    DoctorResearcher(const string& name, int id, const Date& birthDate, Person::eGender gender, const string& expertise);

    void toOs(ostream& os) const override;
    virtual Worker* clone() const override { return new DoctorResearcher(*this); }

    friend class ResearchCenter;
};


#endif //!__RESEARCHER_DOCTOR_H
