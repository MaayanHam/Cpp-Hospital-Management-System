#include "DoctorResearcher.h"

DoctorResearcher::DoctorResearcher(const string& name, int id, const Date& birthDate, Person::eGender gender, const string& expertise)
    : Worker(name, id, birthDate, gender),
    Researcher(name, id, birthDate, gender),
    Doctor(name, id, birthDate, gender, expertise)
{
}

void DoctorResearcher::toOs(ostream& os) const
{

    Doctor::toOs(os);
    os << endl<<" --- Also a Researcher ---" << endl;
    os << endl << "Researcher details:" << endl;
    os << "Number of articles: " << articles.size() << endl;
    for (Article* article : articles)
    {
        os << *article << endl;
    }
}
