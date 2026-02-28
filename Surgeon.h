#ifndef __SURGEON_H
#define __SURGEON_H
#include "Doctor.h"
class Hospital;
class Department;
class Surgeon : public Doctor 
{
private:
    int surgeriesAmount;
    Surgeon(const Surgeon& other) = default;
    Surgeon(Surgeon&& other) = default;
public:
    Surgeon(const string& name, int id, const Date& birthDate, eGender gender, const string& expertise, int numSurgeries);
    
    virtual void toOs(ostream& os) const override;
    friend class Hospital;
    friend class Department;
    virtual Worker* clone() const override { return new Surgeon(*this); }
    void addSurgery() { surgeriesAmount++; }
};


#endif //!__SURGEON_H
