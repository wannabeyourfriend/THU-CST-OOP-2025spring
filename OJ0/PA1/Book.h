#ifndef _BOOK_H_
#define _BOOK_H_
#include <string>
#include <iostream>
using namespace std;
template <typename T>
class Book
{
private:
    string title;
    string author;
    T pages;

public:
    Book(const string &t, const string &a, const T &p) : title(t), author(a), pages(p) {}
    void show() const
    {
        // const 表明show()不会修改Book类的任何数据成员
        cout << "Book Name: " << title << ", "
             << "Author: " << author << ", "
             << "Pages: " << pages << endl;
    }
    bool operator<(const Book<T> &other)
    {
        return pages < other.pages;
    }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    T getPages() const { return pages; }
    ~Book() {}
};
#endif // _BOOK_H_