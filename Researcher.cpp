#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Researcher.h"


Researcher::Researcher(const string& name, int idNum, const Date& birthDate, const eGender gender)
    : Worker(name, idNum, birthDate, gender)
{
}

Researcher::Researcher(const Researcher& other)
    : Worker(other)
{
    for (Article* art : other.articles)
    {
        this->articles.push_back(new Article(*art));
    }
}


Researcher::Researcher(Researcher&& other) noexcept
    : Worker(std::move(other)),
    articles(std::move(other.articles))
{
}


Researcher::~Researcher()
{
    for (Article* art : articles)
            delete art;
}


const Researcher& Researcher::operator+=(const Article& article)
{
    if (articles.size() == articles.capacity())
    {
        articles.reserve(articles.capacity() * 2);
    }

    articles.push_back(new Article(article));

    return *this; 
}

bool Researcher::operator<(const Researcher& other) const
{
    return this->articles.size() < other.articles.size();
}

void Researcher::toOs(ostream& os) const
{
    
    Worker::toOs(os);
    os << endl << "Researcher details:" << endl;
    os << "Number of articles: " << articles.size() << endl;
    for (Article* article : articles)
    {
        os << *article << endl;
    }
}
