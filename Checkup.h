#ifndef __CHECKUP_H
#define __CHECKUP_H
#include "Visit.h"

class Checkup : public Visit 
{
public:
    Checkup(const Date& date, const string& purpose, Department* dept, Worker* caregiver);
        

    virtual void toOs(ostream& os) const override;
    
};

#endif //!__CHECKUP_H
