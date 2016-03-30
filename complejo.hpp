#pragma once

#include "real.hpp"
#include "numero.hpp"
#include <cstdlib>
#include <cmath>



class complejo:public Numero {

private:
  real r;  //parte real
  real i;  //parte imaginaria
  real m;   //modulo                                             
     
public:
  
  complejo(void);                 //constructor por defecto
  complejo(real re, real im);    //constructor de asignación
  complejo(float re, float im);  //constructor de asignación
  complejo(const complejo& n);    //constructor de copia
  ~complejo(void);                 //destructor
  
  real get_r(void) const;
  real get_i(void) const;
  real get_m(void) const;
  
  virtual const entero toEntero(void) const;
  virtual const real toReal(void) const;
  virtual const racional toRacional(void) const;
  virtual const complejo toComplejo(void) const;
  
  virtual ostream& toStream(ostream& sout) const;       // Escribe un Numero al flujo sout
  virtual istream& fromStream(istream& sin);             // Lee un Numero desde flujo sin
  
  //SOBRECARGA DE OPERADORES
  complejo& operator=(const complejo&);
  complejo& operator=(const string a);          //operador de asignación para darle un valor desde una cadena del tipo X+Yi
  
  
  //aritméticos
  friend complejo operator+(const complejo&, const complejo&);
  friend complejo operator-(const complejo&, const complejo&);
  friend complejo operator*(const complejo&, const complejo&);
  friend complejo operator/(const complejo&, const complejo&);
  
  //comparación
  friend bool operator==(const complejo&, const complejo&);
  friend bool operator!=(const complejo&, const complejo&);
  friend bool operator<(const complejo&, const complejo&);
  friend bool operator>(const complejo&, const complejo&);
  friend bool operator<=(const complejo&, const complejo&);
  friend bool operator>=(const complejo&, const complejo&);
  
  //Entrada-Salida
  friend ostream& operator<<(ostream&, const complejo&);
  friend istream& operator>>(istream&, const complejo&);
  
};