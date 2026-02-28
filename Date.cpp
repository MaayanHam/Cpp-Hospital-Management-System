#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Date.h"

Date::Date (int day, int month, int year) : day(day), month(month), year(year)
{
    
}

 std::ostream& operator<<(std::ostream& os, const Date date)
{
     os << date.day << "."<< date.month << "."<< date.year;
     
     return os;
 }

