#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "ResearchCenter.h"
#include "DoctorResearcher.h"

void ResearchCenter::setName(const string& name)
{
    this->name = name;
}


ResearchCenter::ResearchCenter(const string& name) : name(name)
{
}

const ResearchCenter& ResearchCenter::operator=(ResearchCenter&& other)
{
    if (this != &other)
    {
        for (Researcher* r : researchers) delete r;
        researchers.clear();
        name = std::move(other.name);
        researchers = std::move(other.researchers);
    }
    return *this;
}

ResearchCenter::ResearchCenter(ResearchCenter&& other) noexcept
    : name(std::move(other.name)), researchers(std::move(other.researchers))
{
}



const ResearchCenter& ResearchCenter::operator+=(const Researcher& researcher)
{
    if (researchers.size() == researchers.capacity())
    {
        researchers.reserve(researchers.capacity() * 2);
    }

    Researcher* temp = dynamic_cast<Researcher*>(researcher.clone());
    researchers.push_back(temp);
    return *this;
}

Researcher* ResearchCenter::getResearcherByID(int id) const
{
    for (Researcher* res : researchers)
    {
        if (res->getIdNum() == id)
            return res;
    }
    return nullptr;
}

std::ostream& operator<<(std::ostream& os, const ResearchCenter& researchCenter)
{
    os << "Research Center: " << researchCenter.name << endl;
    os << "Number of researchers: " << researchCenter.researchers.size() << endl;
    for (Researcher* res : researchCenter.researchers)
    {
        os << *res << endl;
    }

    return os;
}

void ResearchCenter::sortResearchers ()
{
    sort(researchers.begin(), researchers.end(), [](Researcher* res1, Researcher* res2) {return *res1 < *res2;});
}

ResearchCenter::~ResearchCenter()
{
    for (Researcher* res : researchers)
    {
        delete res;
    }
}


