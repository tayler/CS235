#pragma once
#include <string>

using namespace std;

class Book
{
private:
    string author;
    string title;
public:
    Book(string t, string a);
    // can use `const` if the method doesn't modify member variables. also needed in Book.cpp
    string getTitle() const;
    string getAuthor() const;
    void setTitle(string title);
    void setAuthor(string author);
};