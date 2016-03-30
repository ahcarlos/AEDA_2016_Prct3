#pragma once



#include <iostream>
#include <cmath>

#include "entero.hpp"
#include "numero.hpp"
class racional;
class complejo;

#define EPSILON 0.001



using namespace std;

class real:public Numero {

private:
  float numero;
     
public:
  
  real(void);
  real(float n);
  real(const real& n);
  ~real(void);
  
  float get_numero(void) const;
  
  //--------Heredados de la clase Numero------
  virtual const entero toEntero(void) const;
  virtual const real toReal(void) const;
  virtual const racional toRacional(void) const;
  virtual const complejo toComplejo(void) const;
 
  virtual ostream& toStream(ostream& sout) const;  
  virtual istream& fromStream(istream& sin);
   //-------------------------------------------
  
  //SOBRECARGA DE OPERADORES
  real& operator=(const real&);
  real& operator=(const float& n);
  
  //aritméticos
  friend real operator+(const real&, const real&);
  friend real operator-(const real&, const real&);
  friend real operator*(const real&, const real&);
  friend real operator/(const real&, const real&);
  
  //comparación
  friend bool operator==(const real&, const real&);
  friend bool operator!=(const real&, const real&);
  friend bool operator<(const real&, const real&);
  friend bool operator>(const real&, const real&);
  friend bool operator<=(const real&, const real&);
  friend bool operator>=(const real&, const real&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const real&);
  friend istream& operator>>(istream&, const real&);
  
};