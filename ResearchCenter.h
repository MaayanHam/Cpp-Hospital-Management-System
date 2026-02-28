#ifndef __RESEARCHCENTER_H
#define __RESEARCHCENTER_H
#include <iostream>
using namespace std;
#include <vector>

#include "Researcher.h"
class ResearchCenter
{
private:
	string name;
    vector <Researcher*> researchers;
public:
    ResearchCenter (const string& name);
    ResearchCenter (const ResearchCenter& other) = delete;
    ResearchCenter (ResearchCenter&& other) noexcept;
    ~ResearchCenter ();
    const ResearchCenter& operator=(const ResearchCenter& other) = delete;
    const ResearchCenter& operator=(ResearchCenter&& other);
    const ResearchCenter& operator+=(const Researcher& researcher);
    void sortResearchers ();
    Researcher* getResearcherByID(int id) const;
    friend std::ostream& operator<<(std::ostream& os, const ResearchCenter& researchCenter);
    void setName(const string& name);
    
};

#endif // !__RESEARCHCENTER_H
