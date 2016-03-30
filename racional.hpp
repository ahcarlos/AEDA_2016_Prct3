#pragma once

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>

#include "entero.hpp"
#include "numero.hpp"




class racional: public Numero {

private:
  entero numerador;
  entero denominador;
  entero mcd;
     
public:
  
  racional(void);//constructor por defecto
  racional(entero num, entero den);
  racional(int num, int den);//constructor de asignación
  racional(const racional& n);//constructor de copia
  racional(double n);
  ~racional(void);//destructor
  
  entero get_numerador(void) const;
  entero get_denominador(void) const;
  entero m_d(void) const; //máximo común divisor
  
  //SOBRECARGA DE OPERADORES
  racional& operator=(const racional&);
  racional& operator=(const string cad);
  
  //aritméticos
  friend racional operator+(const racional&, const racional&);
  friend racional operator-(const racional&, const racional&);
  friend racional operator*(const racional&, const racional&);
  friend racional operator/(const racional&, const racional&);
  
  //comparación
  friend bool operator==(const racional&, const racional&);
  friend bool operator!=(const racional&, const racional&);
  friend bool operator<(const racional&, const racional&);
  friend bool operator>(const racional&, const racional&);
  friend bool operator<=(const racional&, const racional&);
  friend bool operator>=(const racional&, const racional&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const racional&);
  friend istream& operator>>(istream&,  racional&);
  
  //--------Heredados de la clase Numero----------------
  virtual ostream& toStream(ostream& sout) const;  
  virtual istream& fromStream(istream& sin);
  
  virtual const entero toEntero(void) const;
  virtual const real toReal(void) const;        
  virtual const racional toRacional(void) const;
  virtual const complejo toComplejo(void) const;
  
};