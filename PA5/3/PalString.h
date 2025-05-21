#ifndef PALSTRING_H
#define PALSTRING_H
#include <iostream>
#include <cstring>
class PalString {
public:
    char* data_;    

    PalString(const char* pStr) {
        if (pStr == nullptr) {
            data_ = new char[1];
            data_[0] = '\0';
            return;
        }
        
        int len = strlen(pStr);
        data_ = new char[2 * len + 1];
        
        strcpy(data_, pStr);
        
        for (int i = 0; i < len; i++) {
            data_[len + i] = pStr[len - 1 - i];
        }
        
        data_[2 * len] = '\0';
    }

    ~PalString() {
        delete[] data_;
    }

    char* getString() {
        return data_;
    }

    void changeString(const char* pStr) {
        if (pStr == nullptr) {
            delete[] data_;
            data_ = new char[1];
            data_[0] = '\0';
            return;
        }
        
        delete[] data_;
        
        int len = strlen(pStr);
        data_ = new char[2 * len + 1];
        
        strcpy(data_, pStr);
        
        for (int i = 0; i < len; i++) {
            data_[len + i] = pStr[len - 1 - i];
        }
        
        data_[2 * len] = '\0';
    }
 
    PalString(const PalString& rhs) {
        int len = strlen(rhs.data_);
        data_ = new char[len + 1];
        strcpy(data_, rhs.data_);
    }

    friend std::ostream& operator<<(std::ostream& os, const PalString& ps) {
        os << ps.data_;
        return os;
    }
};

#endif // #ifndef PALSTRING_H