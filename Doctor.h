#ifndef _DOCTOR_H
#define _DOCTOR_H
#include "Worker.h"
class Department;

class Doctor : virtual public Worker
{
protected:
	string expertise;
    Department* department;

    Doctor(const Doctor& other) = default;
    Doctor(Doctor&& other) = default;
public:
    Doctor(const string& name, const int idNum, const Date& birthDate, const eGender gender ,const string& expertise);

    virtual ~Doctor() = default;
    virtual Worker* clone() const override { return new Doctor(*this); }
    const Doctor& operator=(const Doctor& other) = delete;
    const Doctor& operator=(Doctor&& other) = delete;
    void toOs(ostream& os) const override;
    void setExpertise(const string& expertise);
    friend class Department;
    friend class Hospital;
};

#endif // !_DOCTOR_H
