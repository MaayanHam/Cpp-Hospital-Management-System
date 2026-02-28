#ifndef __SURGERY_H
#define __SURGERY_H
#include "Visit.h"
class Surgery : public Visit 
{
private:
    int roomNum;
    bool isFasting;
public:
    Surgery(const Date& date, const string& purpose, Department* dept, Worker* caregiver, int room, bool fast);
        

    void toOs(ostream& os) const override;
};

#endif 
