#include "Book.h"
template <typename T>
void Book<T>::show() const
{ // const 表明show()不会修改Book类的任何数据成员
    cout << "Title: " << title << ", " << endl;
    cout << "Author: " << author << ", " << endl;
    cout << "Pages: " << pages << endl;
}
template <typename T>
bool Book<T>::operator<(const Book<T> &other)
{
    return pages < other.pages;
}