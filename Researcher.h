#ifndef __RESEARCHER_H
#define __RESEARCHER_H

#include "Worker.h"
#include "Article.h"
#include <vector>
using namespace std;

class ResearchCenter;

class Researcher : virtual public Worker
{
protected:
    vector <Article*> articles;

    Researcher(const Researcher& other);
    Researcher(Researcher&& other) noexcept;

public:
    Researcher(const string& name, int idNum, const Date& birthDate, const eGender gender);
    ~Researcher();
    const Researcher& operator=(const Researcher& other) = delete;
    const Researcher& operator=(Researcher&& other) = delete;
    const Researcher& operator+=(const Article& article);
    bool operator<(const Researcher& other) const;
    void toOs(ostream& os) const override;
    virtual Worker* clone() const override { return new Researcher(*this); }

    friend class ResearchCenter;
};

#endif// !__RESEARCHER_H
