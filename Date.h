#ifndef __DATE_H
#define __DATE_H
#include <iostream>
using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;
public:
    Date (int day, int month, int year);
    friend std::ostream& operator<<(std::ostream& os, const Date date);
};

#endif // !__DATE_H
