#pragma once

#include <iostream>

using namespace std;



template <class T>
    class nodeTemp
    {
        private:
            T data_; 
            nodeTemp<T>* next_;
            
        public:
            nodeTemp(void);
            nodeTemp(T dato);
            ~nodeTemp(void);
            
            nodeTemp<T>* get_next(void);
            T get_dato(void);
            
            void set_next(nodeTemp<T>* next);
            void set_dato(T dato);
            
            ostream& write(ostream& os);
    };
    
    template <class T>
    nodeTemp<T>::nodeTemp(void):
        next_(NULL), 
        data_(0)
        {}
        
    template <class T>    
    nodeTemp<T>::nodeTemp(T dato):
    next_(NULL), 
    data_(dato)
    {}
    
    template <class T> 
    nodeTemp<T>::~nodeTemp(void)
    {}
    
    template <class T>
    nodeTemp<T>* nodeTemp<T>::get_next(void)
    {
        return next_;
    }
    
    template <class T>
    T nodeTemp<T>::get_dato(void)
    {
        return data_;
    }
    
    template <class T>
    void nodeTemp<T>::set_next(nodeTemp<T>* next)
    {
        next_= next;
    }
    
    template <class T>
    void nodeTemp<T>::set_dato(T dato)
    {
        data_= dato;
    }
    
    template <class T>
    ostream& nodeTemp<T>::write(ostream& os)
    {
        os << data_ << " ";
    }