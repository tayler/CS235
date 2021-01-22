#include "Book.h"

// two constructor options: same end result, but
// 1) assignment statements
//Book::Book(string t, string a) {
//    title = t;
//    author = a;
//}
// 2) initializers - more "efficient" (not sure if that means less code or faster)
Book::Book(string t, string a) : title(t), author(a) {}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

void Book::setTitle(string title) {
    this->title = title;
}

void Book::setAuthor(string author) {
    this->author = author;
}