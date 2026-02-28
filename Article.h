#ifndef __ARTICLE_H
#define __ARTICLE_H
#include <iostream>
using namespace std;
#include "Date.h"
#include <string>


class Article
{
private:
    string articleName;
    string magazineName;
    Date publicationDate;
public:
    Article(const string& articleName, const string& magazineName, const Date& publicationDate);
    friend std::ostream& operator<<(std::ostream& os, const Article& article);
    void setArticleName(const string& articleName);
    void setMagazineName(const string& magazineName);
};

#endif // !__ARTICLE_H
