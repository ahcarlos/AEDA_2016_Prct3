#include "real.hpp"
#include "racional.hpp"
#include "complejo.hpp"




real::real(void):
numero(0)
{}

real::real(float n):
numero(n)
{}

real::real(const real& n) 
{
  *this = n;
}

real::~real(void){}


const entero real::toEntero(void) const
{
  int numero = get_numero();
  entero entero_from_real(numero);
  return entero_from_real;
}

const real real::toReal(void) const
{
  real real_from_real(get_numero());
  return real_from_real;
}

const racional real::toRacional(void) const
{
    float num = get_numero();
    num = num * 10000; 
    racional a(num,10000);
    
    return a;
}

const complejo real::toComplejo(void) const
{
  real parte_real(get_numero());
  real imaginaria(0.0);
  complejo complejo_from_real(parte_real, imaginaria);
  
  return complejo_from_real;
}


float real::get_numero(void) const
{
  return numero;
}

real& real::operator=(const real& a)
{
  numero = a.get_numero();
  
  return *this;
}

real& real::operator=(const float& n)
{
  numero = n;
  return *this;
}

ostream& real::toStream(ostream& sout) const
{
  sout << numero;
  
  return sout;
}

istream& real::fromStream(istream& sin)
{
  sin >> numero;
  
  return sin;
}


real operator+(const real& a, const real& b)
{
  return real(a.get_numero() + b.get_numero());
}

real operator-(const real& a, const real& b)
{ 
      return real(a.get_numero() - b.get_numero());
}

real operator*(const real& a, const real& b)
{
  return real(a.get_numero() * b.get_numero());
}

real operator/(const real& a, const real& b)
{
  try {
    if(!b.get_numero()) throw ("Error: no se puede llevar a cabo una division por 0");
    
    return real(a.get_numero()/b.get_numero());
    } 
 catch(const char* error)
  {
    cerr << error << endl;
    exit(1);
  }
}

//comparación
bool operator==(const real& a, const real& b)
{
  return(fabs(a.get_numero()-b.get_numero()) < EPSILON ? true:false);
}

bool operator!=(const real& a, const real& b)
{
  return(a==b ? false:true);
}

bool operator<(const real& a, const real& b)
{
  return((a.get_numero()-b.get_numero()) < -EPSILON ? true:false);
}

bool operator>(const real& a, const real& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const real& a, const real& b)
{
  return(a>b ? false:true);
}

bool operator>=(const real& a, const real& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const real& a)
{
  os << a.get_numero();
  return os;
}

istream& operator>>(istream& is, real& a)
{
  float n;
  is >> n;
  a = real(n);
  return is;
}