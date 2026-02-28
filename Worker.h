#ifndef __WORKER_H
#define __WORKER_H
#include "Person.h"
#include <iostream>
using namespace std;

class Worker : public Person
{
protected:
    static int workersCounter;
    const int workerID;
    Worker(const Worker& other) = default;
    Worker(Worker&& other) = default;
public:
    Worker(const string& name, const int idNum, const Date birthDate, const eGender gender);
    virtual ~Worker() {}
   
    const Worker& operator=(const Worker& other) = delete;
    const Worker& operator=(Worker&& other) = delete;
    void toOs(ostream& os) const override;
    virtual Worker* clone() const = 0;
};


#endif
