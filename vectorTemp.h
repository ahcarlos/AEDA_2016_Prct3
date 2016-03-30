#pragma once

#include <iostream>
#include <cstdio>
#include<cstdlib>
#include <cmath>
#include <iomanip>

#include <cassert>
#include <exception>

#include "numero.hpp"
#include "exception_vector.hpp" //fichero donde se encuentran las excepciones que puede generar un vector
using namespace std;

template <class T>
class vectorTemp{
    private:
    T* datos_;
    int     sz_;
  public:
    vectorTemp(void);
    vectorTemp(int n);
    vectorTemp(const vectorTemp& v);
    ~vectorTemp(void);
    
    int get_sz(void) const;
    T& get_val(int i);
    T get_val(int i) const;
    
    ostream& imprime_numero(ostream& os);
    ostream& write(ostream& os);

    
    
    
    T& operator[](int i);
    T operator[](int i) const;
    
    void release_vector(void);
    
    
    //ostream& operator<<(ostream& os, const vectorTemp<T>& v);
};

template <class T>
vectorTemp<T>::vectorTemp(void):
datos_(NULL),
sz_(0)
{}

template <class T>
vectorTemp<T>::vectorTemp(int n):
datos_(NULL),
sz_(n)
{
    datos_ = new T [sz_];
    
    if(datos_ == NULL){
        throw std::bad_alloc();
        exit(1);
    }
}



template <class T>
vectorTemp<T>::vectorTemp(const vectorTemp<T>& v):
datos_(NULL),
sz_(v.get_sz())
{
    
    for(int i = 0; i < sz_; i++)
        datos_[i] = v.get_val(i);
}

template <class T>
vectorTemp<T>::~vectorTemp(void)
{
    if (datos_ != NULL){
        delete [] datos_;
        datos_ = NULL;
    }
}



template <class T>
void vectorTemp<T>::release_vector(void)
{
    if (datos_ != NULL){
        delete [] datos_;
        datos_ = NULL;
    }
}


template <class T>
int vectorTemp<T>::get_sz(void) const
{
    return sz_;
}


template <class T>
T& vectorTemp<T>::get_val(int i)
{
    if(i > sz_){
        throw overflow_index_exception();
        exit(1);
    }
    else
    return datos_[i];
}


template <class T>
T vectorTemp<T>::get_val(int i) const
{
    if(i > sz_){
        throw overflow_index_exception();
        exit(1);
    }
    else 
    return datos_[i];
}

template <class T>
ostream& vectorTemp<T>::write(ostream& os)
{
    os << setw(2)<<"Numero de elementos en el vector:" << sz_ << endl;
    
    for(int i = 0; i < sz_; i++)
        os << setw(2) << fixed << setprecision(4) << datos_[i] << " ";
        
    os << endl;
}




template <class T>
T& vectorTemp<T>::operator[](int i)
{
    if(i >sz_){
        throw overflow_index_exception();
        exit(1);
    }
    else if(i < 0){
        throw underflow_index_exception();
        exit(1);
    }
    else 
    return get_val(i);
}


template <class T>
T vectorTemp<T>::operator[](int i) const
{
    if(i >sz_){
        throw overflow_index_exception();
        exit(1);
    }
    else if(i < 0){
        throw underflow_index_exception();
        exit(1);
    }
    else
    return get_val(i);
}

template <>
ostream& vectorTemp<Numero*>::imprime_numero(ostream& os)
{
    for(int i = 0; i<sz_;i++) 
    {
        datos_[i]->toStream(os);
        cout << " ";
    }
	return os;
}


