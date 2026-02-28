#pragma warning (disable: 4996)
#include <iostream>
using namespace std;
#include "Article.h"


void Article::setArticleName(const string& articleName)
{
    this->articleName = articleName;
}

void Article::setMagazineName(const string& magazineName)
{
    this->magazineName = magazineName;
}

Article::Article(const string& articleName, const string& magazineName, const Date& publicationDate):
    articleName(articleName), magazineName(magazineName),
    publicationDate(publicationDate)
{
}
std::ostream& operator<<(std::ostream& os, const Article& article)
{
    os << article.articleName << " published in " << article.publicationDate << " at the magazine " << article.magazineName<<endl;
    return os;
}
