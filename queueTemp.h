#pragma once

#include "sllTemp.h"

#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <exception>

using namespace std;

template <class T>
class queueTemp{
    private:
        sllTemp<T> list_;
    
    public:
        queueTemp(void);
        ~queueTemp(void);
        
        void put(T dato);
        T get(void);
        
        bool empty(void);
        void release_queue(void);
        
        ostream& imprime_numero(ostream& os);
        ostream& write(ostream& os);
    
};

template <class T>
queueTemp<T>::queueTemp(void):
list_()
{}


template <class T>
queueTemp<T>::~queueTemp(void)
{
    release_queue();
}


template <class T>
void queueTemp<T>::put(T dato)
{
    list_.insert_beginning(new nodeTemp<T>(dato));
}


template <class T>
T queueTemp<T>::get(void)
{
    try{
        if(empty()){
            throw("Error al hacer get en la cola: La cola etá vacía");
        }
        
        nodeTemp<T>* n_aux= (nodeTemp<T>*)(list_.extract_end());
        T aux= n_aux->get_dato();
        delete n_aux;
        return aux;
    }
    catch(const char* error)
    {
        cerr << error<< endl;
        exit(1);
    }
    
}


template <class T>
bool queueTemp<T>::empty(void)
{
    return list_.empty();
}


template <class T>
void queueTemp<T>::release_queue(void)
{
    list_.release_list();
}


template <class T>
ostream& queueTemp<T>::write(ostream& os)
{
    list_.write(os);
    return os;
}

template <>
ostream& queueTemp<Numero*>::imprime_numero(ostream& os)
{
    list_.imprime_numero(os);
}
