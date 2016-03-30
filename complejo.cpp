#include "complejo.hpp"
#include "racional.hpp"



complejo::complejo(void):
r(),
i(),
m()
{}

complejo::complejo(real re, real im):
r(re),
i(im)
{
  m = r*r+i*i;
}

complejo::complejo(const complejo& n) 
{
  *this = n;
}

complejo::complejo(float re, float im):
r(real(re)),
i(real(im))
{
  m = r*r+i*i;
}

complejo::~complejo(void)
{}

real complejo::get_r(void) const
{
  return r;
}

real complejo::get_i(void) const
{
  return i;
}

real complejo::get_m(void) const
{
  return m;
}

const entero complejo::toEntero(void) const
{
  real parte_real(get_r());
  entero entero_from_complejo(parte_real.get_numero());
  return entero_from_complejo;
}

const real complejo::toReal(void) const
{
  real real_from_complejo(get_r());
  return real_from_complejo;
}

const racional complejo::toRacional(void) const
{
  real parte_real(get_r());
  racional racional_from_complejo(parte_real.get_numero(),1);
  return racional_from_complejo;
}

const complejo complejo::toComplejo(void) const
{
    complejo complejo_from_complejo(get_r(),get_i());
    return complejo_from_complejo;
}


complejo& complejo::operator=(const complejo& a)
{
  i = a.get_i();
  r = a.get_r();
  
  return *this;
}

complejo& complejo::operator=(const string a)
{
  size_t found = a.find("+");
  
  string b,c;
  b.resize(found);
  c.resize((a.size() - found)-2);
  for(unsigned int k=0;k<found;k++) {
  
   b[k] = a[k];
  }
  for(unsigned int j=0;j<c.size();j++) {
  
    c[j] = a[j+1+found];
  }
  
  r = atof(b.c_str());
  i = atof(c.c_str());
}

ostream& complejo::toStream(ostream& sout) const
{
  r.toStream(cout);
  i.toStream(cout << "+");
  cout << "i";
  return sout;
}

istream& complejo::fromStream(istream& sin)
{
  string a;
  sin >> a;
  
  size_t found = a.find("+");
  
  string b,c;
  b.resize(found);
  c.resize((a.size() - found)-2);
  for(unsigned int k=0;k<found;k++) {
  
   b[k] = a[k];
  }
  for(unsigned int j=0;j<c.size();j++) {
  
    c[j] = a[j+1+found];
  }
  
  r = atof(b.c_str());
  i = atof(c.c_str());
  
  return sin;
}


//----------------------------OPERADORES SOBRECARGADOS AMIGOS----------------------------------------

//Aritméticos
complejo operator+(const complejo& a, const complejo& b)
{
  return complejo(a.get_r() + b.get_r(), a.get_i() + b.get_i());
}

complejo operator-(const complejo& a, const complejo& b)
{ 
  return complejo(a.get_r() - b.get_r(), a.get_i() - b.get_i());
}

complejo operator*(const complejo& a, const complejo& b)
{
  return complejo((a.get_r() * b.get_r()) - (a.get_i() * a.get_i()), a.get_r()*b.get_i() + a.get_i()*b.get_r());//(a + bi) * (c + di) = (ac − bd) + (ad + bc)i
}

complejo operator/(const complejo& a, const complejo& b)
{
  return complejo((a.get_r()*b.get_r() + a.get_i()*b.get_i())/(b.get_r()*b.get_r()+b.get_i()*b.get_i()), (a.get_i()*b.get_r()-a.get_r()*b.get_i())/(b.get_r()*b.get_r()+b.get_i()*b.get_i()));
}

//comparación
bool operator==(const complejo& a, const complejo& b)
{
  return(fabs(((a.get_m()-b.get_m()).get_numero())) < EPSILON ? true:false);
}

bool operator!=(const complejo& a, const complejo& b)
{
  return(a==b ? false:true);
}

bool operator<(const complejo& a, const complejo& b)
{
  return((a.get_m()-b.get_m()) < -EPSILON ? true:false);
}

bool operator>(const complejo& a, const complejo& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const complejo& a, const complejo& b)
{
  return(a>b ? false:true);
}

bool operator>=(const complejo& a, const complejo& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const complejo& a)
{
  os << "[" << a.get_r() << "+" << a.get_i() << "i]";
  return os;
}

istream& operator>>(istream& is, complejo& a)
{
  float re, im;
  cout << "Parte real:";
  is >> re;
  
  cout << "Parte imaginaria:";
  is >> im;
  cout << endl;
  
  a = complejo(re, im);
  return is;
}