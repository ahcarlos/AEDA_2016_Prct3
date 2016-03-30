#include "entero.hpp"
#include "racional.hpp"
#include "complejo.hpp"

//#include <cstdlib>



entero::entero(void):
numero_(0)
{}

entero::entero(int n):
numero_(n)
{}

entero::~entero(void)
{}

int entero::get_numero(void) const
{
    return numero_;
}

/////////////////////////////////////////////////////////////////////////////////////////////////
//practica 3
const entero entero::toEntero(void) const
{
    return numero_;   
}

const real entero::toReal(void) const
{
    real real_from_entero(get_numero());
    return real_from_entero;
}

const racional entero::toRacional(void) const
{
    racional racional_from_entero(get_numero(), 1);
    return racional_from_entero;
}

const complejo entero::toComplejo(void) const //de entero a complejo igualamos la parte real al entero, ya que los numeros reales los engloban
{
    real parte_real(get_numero());
    real imaginaria(0.0);
    complejo complejo_from_entero(parte_real,imaginaria);
    return complejo_from_entero;
}
////////////////////////////////////////////////////////////////////////////////////////////////

entero& entero::operator=(const entero& n)
{
    numero_ = n.get_numero();
    return *this;
}

entero& entero::operator=(const int& n)
{
    numero_ = n;
    return *this; 
}
////////////////////////////////////////////////////////////////////
//practica 3
ostream& entero::toStream(ostream& sout) const
{
  sout << numero_;
  
  return sout;
}

istream& entero::fromStream(istream& sin)
{
  sin >> numero_;
  
  return sin;
}
//////////////////////////////////////////////////////////////
entero operator+(const entero& a, const entero& b)
{
    return a.get_numero() + b.get_numero();
}

entero operator-(const entero& a, const entero& b)
{
    return a.get_numero() - b.get_numero();
}

entero operator*(const entero& a, const entero& b)
{
    return a.get_numero() * b.get_numero();
}

entero negar(const entero& a)
{
    entero b(-1);
    return a.get_numero() * b.get_numero();
}

entero operator/(const entero& a, const entero& b)
{
    return a.get_numero() / b.get_numero();   
    
    try {
    if(!b.get_numero()) throw ("Error: No se puede efecturar una división por 0");
    
    return entero(a.get_numero()/b.get_numero());
    } 
  catch(const char* error)
    {
        cerr << error<< endl;
        exit(1);
    }
}

bool operator==(const entero& a, const entero& b)
{
    if(a.get_numero() == b.get_numero())
        return true;
    else
        return false;
}

bool operator!=(const entero& a, const entero& b)
{
    if(a.get_numero() != b.get_numero())
        return true;
    else
        return false;
}

bool operator<(const entero& a, const entero& b)
{
    if(a.get_numero() < b.get_numero())
        return true;
    else
        return false;
}

bool operator>(const entero& a, const entero& b)
{
    if(a.get_numero() > b.get_numero())
        return true;
    else
        return false;
}

bool operator<=(const entero& a, const entero& b)
{
    if(a.get_numero() <= b.get_numero())
        return true;
    else
        return false;
}

bool operator>=(const entero& a, const entero& b)
{
    if(a.get_numero() >= b.get_numero())
        return true;
    else
        return false;   
}

ostream& operator<<(ostream& os, const entero& a)
{
  os << a.get_numero();
  return os;
}

istream& operator>>(istream& is, entero& a)
{
  int n;
  is >> n;
  entero aux(n);
  a = aux;
  return is;
}
