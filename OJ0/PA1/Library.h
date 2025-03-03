#ifndef _LIBRARY_H_
#define _LIBRARY_H_
#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;
template <typename T>
class Library
{
private:
    vector<Book<T>> books;

public:
    Library() {}
    void addBook(Book<T> book)
    {
        books.push_back(book);
    }
    void show() const
    {
        for (const auto &book : books)
        {
            book.show();
        }
    }
    void borrowBook(const std::string &title)
    {
        bool found = false;
        for (const auto &book : books)
        {
            if (book.getTitle() == title)
            {
                cout << "Books Checked out " << title << "." << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Book title does not exist." << endl;
        }
    }
    ~Library() {}
};
#endif // _LIBRARY_H_