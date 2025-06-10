#include <iostream>
#include <string>
#include <vector>
#include "Book.h"
using namespace std;

template <typename T>
class Library {
private:
    vector<Book<T>> books;
public:
    void addBook(const Book<T>& book) {
        books.push_back(book);
        return;
    }
    void show() {
        for(const auto& book : books) {
            book.show();
        }
        return;
    }
    void borrowBook(const std::string& title) {
        for(const auto& book : books) {
            if(book.getName() == title) {
                cout << "Books Checked out " << title << "." << endl;
                return;
            }
        }
        cout << "Book " << title <<" does not exist." << endl;
        return;
    }
};