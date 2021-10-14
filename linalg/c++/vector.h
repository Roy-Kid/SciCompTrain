// author: Roy Kid
// contact: lijichen365@126.com
// date: 2021-10-14
// version: 0.0.1
#include <iostream>

template <typename T>
class Vector
{

private:
    int len; // dimension of vector. upper index is len-1
    T *v;

public:
    Vector();                             //default constructor
    Vector(int n);                        // Zero-based array
    Vector(int n, const T &a);            // init to const value in c++ style
    Vector(int n, const T *a);            // init to const value in c style
    Vector(const Vector &rhs);            // copy constructor
    Vector &operator=(const Vector &rhs); // assignment
    typedef T value_style;                // make T avaiable externally
    inline T &operator[](const int i);    //i'th element
    inline const T &operator[](const int i) const;
    inline int size() const;
    ~Vector();
};

template <typename T>
Vector<T>::Vector() : len(0), v(NULL) {}

template <typename T>
Vector<T>::Vector(int n) : len(n), v(n > 0 ? new T[n] : NULL) {}

template <class T>
Vector<T>::Vector(int n, const T &a) : len(n), v(n > 0 ? new T[n] : NULL)
{
    for (int i = 0; i < n; i++)
        v[i] = a;
}

template <class T>
Vector<T>::Vector(int n, const T *a) : len(n), v(n > 0 ? new T[n] : NULL)
{
    for (int i = 0; i < n; i++)
        v[i] = *a;
}
template <typename T>
Vector<T>::Vector(const Vector<T> &rhs) : len(rhs.len), v(len > 0 ? new T[len] : NULL)
{
    for (int i; i < len; i++)
        v[i] = rhs[i];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &rhs)
// postcondition: normal assignment via copying has been performed;
//		if vector and rhs were different sizes, vector
//		has been resized to match the size of rhs
{
    if (this != &rhs)
    {
        if (len != rhs.len)
        {
            if (v != NULL)
                delete[](v);
            len = rhs.len;
            v = len > 0 ? new T[len] : NULL;
        }
        for (int i = 0; i < len; i++)
            v[i] = rhs[i];
    }
    return *this;
}

template <typename T>
inline T &Vector<T>::operator[](const int i) //subscripting
{

    if (i < 0 || i >= len)
    {
        throw("Vector subscript out of bounds");
    }
    return v[i];
}

template <typename T>
inline const T &Vector<T>::operator[](const int i) const //subscripting
{

    if (i < 0 || i >= len)
    {
        throw("Vector subscript out of bounds");
    }

    return v[i];
}

template <typename T>
inline int Vector<T>::size() const
{
    return len;
}

template <class T>
Vector<T>::~Vector()
{
    if (v != NULL)
        delete[](v);
}
