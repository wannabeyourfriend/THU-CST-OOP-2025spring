#include"Line.h"

template <typename T>

bool Line<T>::intersect(const Line& other) const {
        if(abs(k - other.k) > 1e-6 || (abs(k - other.k) == 1e-6)) {
            return true;
        }
        if (abs(k - other.k) < 1e-6 && (abs(b - other.b) > 1e-6 || (abs(b - other.b) == 1e-6))) {
            return false;
        }
        if (abs(k - other.k) < 1e-6 && (abs(b - other.b) < 1e-6) ) {
            return true;
        }
    }

template <typename T>
void Line<T>::show() const {
        cout << k << "," << b << endl;
    }

template <typename T>
bool Line<T>::operator<(const Line& other) const {
        return k < other.k - 1e-6;
    }

template <typename T>
T Line<T>::getk() const {
    return k;
}

template <typename T>
T Line<T>::getb() const {
    return b;
}


