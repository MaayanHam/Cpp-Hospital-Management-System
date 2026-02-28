#ifndef __PERSON_H
#define __PERSON_H
#include "Date.h"
#include <iostream>
using namespace std;
#include <string>



class Person
{
public:
    enum class eGender {MALE, FEMALE};
    
    
protected:
    string name;
    const int idNum;
    const Date birthDate;
    const eGender gender;
    Person(const Person& other) = default;
    Person(Person&& other) = default;
public:
    Person (const string& name, const int idNum, const Date birthDate, const eGender gender);
    
    virtual ~Person () = default;

    const Person& operator=(const Person& other) = delete;
    const Person& operator=(Person&& other) = delete;
    virtual void toOs(ostream& os) const;
    friend std::ostream& operator<<(std::ostream& os, const Person& person);
    void setName(const string& name);
    const string getName() const { return name; }
    int getIdNum() const { return idNum; }
};

#endif // !__PERSON_H
