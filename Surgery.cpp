#include "Surgery.h"
#include "Surgeon.h"

Surgery::Surgery(const Date& date, const string& purpose, Department* dept, Worker* caregiver, int room, bool fast)
    : Visit(date, purpose, dept, caregiver), roomNum(room), isFasting(fast)
{
    if (Surgeon* s = dynamic_cast<Surgeon*>(caregiver))
    {
        s->addSurgery(); 
    }
}


void Surgery::toOs(ostream& os) const 
{
    os << "Type: Surgery | ";
    Visit::toOs(os);
    os << " | Surgery in Room: " << roomNum << " | Fasting: " << (isFasting ? "Yes" : "No");
}
