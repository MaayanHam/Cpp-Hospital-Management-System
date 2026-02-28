#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Department.h"
#include "Surgeon.h"
#include "Hospital.h"

void Department::setName(const string& name)
{
    this->name = name;
}

void Department::setHospital(Hospital* hospital)
{
    this->hospital = hospital;
}

Department::Department (const string& name):
    name(name),
    appointmentCounter(0)
{
}

const Department& Department::operator=(const Department& other)
{
    if (this != &other)
    {
        setName(other.name);

        for (Worker* wor : workers) delete wor;

        this->appointmentCounter = other.appointmentCounter;
        this->workers.reserve(other.workers.capacity());
        for (Worker* wor : workers)
        {
            *this += *wor;
        }
    }
    return *this;
}


Department::Department(const Department& other)
{
    *this = other; 
}

const Department& Department::operator=(Department&& other)
{
    if (this != &other)
    {
        this->name = std::move(other.name);
        for (Worker* wor : workers) delete wor;
        this->workers = std::move(other.workers);
        this->appointmentCounter = other.appointmentCounter;
        
        
    }
    return *this;
}

Department::Department(Department&& other)
{
    *this = std::move(other);
}

const Department& Department::operator+=(Worker& worker)
{
    
    if (workers.size() == workers.capacity())
    {
        workers.reserve(workers.capacity() * 2);
    }
    
    Worker* newWorker = worker.clone();

    if (Doctor* d = dynamic_cast<Doctor*>(newWorker)) d->department = this;
    else if (Nurse* n = dynamic_cast<Nurse*>(newWorker)) n->department = this;
    
    
    *(this->hospital) += *newWorker;
    this->workers.push_back(newWorker);
   
    return *this;
}

Worker* Department::getNextWorker()
{
   if (workers.size() == 0) return nullptr;

    Worker* selectedWorker = nullptr;
   
    if (appointmentCounter < workers.size())
    {
        selectedWorker = workers[appointmentCounter];
    }
    

    appointmentCounter++;

    if (appointmentCounter >= workers.size())
    {
        appointmentCounter = 0;
    }

    return selectedWorker;
}

Worker* Department::getSurgeon()
{
    if (workers.size() == 0) return nullptr;

    for (int i = 0; i < workers.size(); i++)
    {
        int index = (appointmentCounter + i) % workers.size();
        if (dynamic_cast<Surgeon*>(workers[index]))
        {
            appointmentCounter = (index + 1) % workers.size();
            return workers[index];
        }
    }
    return getNextWorker();
}

ostream& operator<<(ostream& os, const Department& department)
{
    os << "Department: "<< department.name << " ";
    
    return os;
}



Department::~Department ()
{
    for (Worker* wor : workers)
        delete wor;
}
