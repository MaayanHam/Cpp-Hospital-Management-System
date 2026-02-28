#ifndef _NURSE_H
#define _NURSE_H
#include "Worker.h"
class Department;
class Nurse : public Worker
{
private:
    //DEPARTMENT
    int yearsOfExperience;
    Department *department;

    Nurse(const Nurse& other) = default;
    Nurse(Nurse&& other) = default;
public:
    Nurse(const string& name, const int idNum, const Date birthDate, const eGender gender,int yearsOfExperience);
    const Nurse& operator=(const Nurse& other) = delete;
    const Nurse& operator=(Nurse&& other) = delete;
    void toOs(ostream& os) const override;
    virtual Worker* clone() const override { return new Nurse(*this); }
    friend class Department;
    friend class Hospital;
};

#endif // !_NURSE_H
