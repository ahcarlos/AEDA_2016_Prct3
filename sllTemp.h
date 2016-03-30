#pragma once

#include "numero.hpp"
#include "nodeTemp.h"

#include <iostream>

template <class T>
class sllTemp {
    
    private:
        nodeTemp<T>* beginning_;
        nodeTemp<T>* end_;

    public:
        sllTemp(void);
        ~sllTemp(void);

        void insert_beginning(nodeTemp<T>* n);
        nodeTemp<T>* extract_beginning(void);

	    void insert_end(nodeTemp<T>* aux);
	    nodeTemp<T>* extract_end(void);
	   
        bool empty(void) const;
        void release_list(void);
        
        ostream& imprime_numero(ostream& os);
	    ostream&  write(ostream& os) const;
};

template <class T>
sllTemp<T>::sllTemp(void):
beginning_(NULL), 
end_(NULL)
{}

template <class T>
sllTemp<T>::~sllTemp(void)
{
    while (beginning_ != NULL) 
    {
       	nodeTemp<T>* aux = beginning_;
        beginning_ = beginning_->get_next();
        delete aux;
    }
}

template <class T>
void sllTemp<T>::release_list(void)
{
	try{
	  while (beginning_ != NULL) 
	    {
	       	nodeTemp<T>* aux = beginning_;
	        beginning_ = beginning_->get_next();
	        delete aux;
	    } 
	    
	    if(beginning_ != NULL){
	    	throw ("Error al liberar memoria de la lista.");
	    }
	}
	catch(const char* error)
    {
        cerr << error<< endl;
        exit(1);
    }
}

template <class T>
bool sllTemp<T>::empty(void) const
{
   return (beginning_ == NULL); 
}


template <class T>
void sllTemp<T>::insert_beginning(nodeTemp<T>* aux)
{
    if(empty())
	{
        beginning_ = aux;
        end_ = aux;
	}
	else 
	{ 
        aux->set_next(beginning_);
	    beginning_=aux;
	}
}

template <class T>
nodeTemp<T>* sllTemp<T>::extract_beginning(void)
{
	try{
		if(empty()){
			throw ("Error al extraer por el principio en la lista: La lista está vacía ");
		}
		
	    if(beginning_==end_)
		{
			nodeTemp<T>* aux=beginning_;
			beginning_=NULL;
			end_=NULL;
			return aux;
		}
		else
		{
			nodeTemp<T>* aux = beginning_;
			beginning_=beginning_->get_next();
			return aux;
		}
	}
	catch(const char* error)
    {
        cerr << error<< endl;
        exit(1);
    }
}

template <class T>
void sllTemp<T>::insert_end(nodeTemp<T>* aux)                                                                     
{
    if(empty()){
	    end_= aux;
	    beginning_= aux;
	}
	
	else{
	  end_->set_next(aux);
	  end_ = aux;
	}   
}

template <class T>
nodeTemp<T>* sllTemp<T>::extract_end(void)
{
	try{
		if(empty()){
			throw ("Error al extraer por el final en la lista: La lista está vacía ");
		}
			if(beginning_== end_){
		   nodeTemp<T>* aux= beginning_;
		    beginning_= NULL;
		    end_= NULL;
	
		    return aux;
		}
		else{
		   nodeTemp<T>* aux= beginning_;
		   
		   while(aux->get_next()!= end_){
		       
		    	aux= aux->get_next();
		   }
		   
		    end_= aux;
	
		    aux= aux->get_next();
		    end_->set_next(NULL);
		    return aux;
		}
	}
	catch(const char* error)
    {
        cerr << error<< endl;
        exit(1);
    }
    
}

template <class T>
ostream& sllTemp<T>::write(ostream& os) const
{
     nodeTemp<T>* aux = beginning_;

    while (aux != NULL) {
        aux->write(os);
        aux = aux->get_next();
    }

}

template <>
ostream& sllTemp<Numero*>::imprime_numero(ostream& os)
{
	nodeTemp<Numero*>* aux = beginning_;
  
  	while(aux != NULL) 
  	{
  		aux->get_dato()->toStream(os);
    	cout<< " ";
    	aux= aux->get_next();
  	}
  
}