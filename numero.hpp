#pragma once

#include <cstdio>
#include <cstdlib>
#include <iostream>

class entero;
class racional;
class real;
class complejo;

using namespace std;



class Numero{

public:


	virtual const entero toEntero(void) const = 0; //Convertir a entero
    virtual const racional toRacional(void) const = 0; //Convertir a racional
    virtual const real toReal(void) const = 0; //Convertir a real
    virtual const complejo toComplejo(void) const = 0; //Convertir a complejo
    
	
	virtual ostream& toStream(ostream& sout)const = 0; //flujo entrada
	virtual istream& fromStream(istream& sin) = 0;	//flujo salida
	
};