#pragma once
#include <cstring>
#include <iostream>
using namespace std;

template<typename T>
class Book {
private:
    string name;
    string author;
    T pages;
public:

    Book (string name, string author, T pages) : name(name), author(author), pages(pages)  
    {
        //
    }
    void show() const {
        cout << "Book name: " << name << ", Author: " << author << ", Pages: " << pages << endl;
    }
    bool operator<(const Book<T>& other) const {
        return pages < other.pages;
    }
    string getName() const {
        return name;
    }
};