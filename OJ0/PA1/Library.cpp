#include "Library.h"
template <typename T>
void Library<T>::addBook(Book<T> book)
{
    books.push_back(book);
}
template <typename T>
void Library<T>::show() const
{
    
}
template <typename T>
void Library<T>::borrowBook(const std::string &title)
{
    for (const auto &book : books)
    {
        if (book.getTitle() == title)
        {
            cout << "Books Checked out " << title << "." << endl;
            return;
        }
        else
        {
            cout << "Book title does not exist." <<endl;
        }
    }
}
