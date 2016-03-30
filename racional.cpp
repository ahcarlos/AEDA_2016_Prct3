#include "racional.hpp"
#include "complejo.hpp"

#include  <cmath>

//#include "exception_racionales.hpp"



//En los constructores cada numero racional se expresa en su forma mínima, dividiendo tanto numerador como denominador por el maximo común divisor
racional::racional(void):
numerador(),
denominador()
{}

racional::racional(double n):
numerador(n),
denominador(1)
{}

racional::racional(entero dio, entero dir):
numerador(dio),
denominador(dir),
mcd(m_d())
{
  
  try{
    numerador = numerador/mcd;
    denominador = denominador/mcd;
    if(denominador== 0){
      throw("El denominador es 0, se cancela la creacion del numero racional para evitar divisiones por 0");
    }
    
  }
  catch(const char* error)
  {
    cerr << error << endl;
    exit(1);
  }
  
  
  /*
  if(denominador == 0){
    throw cero_division_exception();
    exit(1);
  }
  numerador = numerador/mcd;
  denominador = denominador/mcd;
  */
  
}


racional::racional(int dio, int dir):
numerador(entero(dio)),
denominador(entero(dir)),
mcd(m_d())
{
  try
  {
      if(!denominador.get_numero()) throw("Error: No se puede crear un número racional con denominador 0");

      mcd = m_d();
      numerador = numerador/mcd;
      denominador = denominador/mcd;
  } 
  catch(const char* error)
  {
      cerr << error << endl;
      exit(1);
  }

}


racional::racional(const racional& n) 
{
  *this = n;
}

racional::~racional(void){}

entero racional::get_numerador(void) const
{
  return numerador;
}

entero racional::get_denominador(void) const
{
  return denominador;
}

racional& racional::operator=(const racional& a)
{
  numerador = a.get_numerador();
  denominador = a.get_denominador();
  mcd=a.m_d();
  
  return *this;
}

racional& racional::operator=(const string a)
{
  size_t found = a.find("/");
  
  string b,c;
  b.resize(found);
  c.resize((a.size() - found)-1);
  for(unsigned int i=0;i<found;i++) {
  
   b[i] = a[i];
  }
  for(unsigned int j=0;j<c.size();j++) {
  
    c[j] = a[j+1+found];
  }
  
  numerador = atoi(b.c_str());
  denominador = atoi(c.c_str());
  mcd=m_d();
  numerador = numerador/mcd;
  denominador = denominador/mcd;
  
}

entero racional::m_d(void) const //calculo del maximo comun divisor
{
  //algoritmo de Euclides
  entero resto, numerador_aux, resto_aux;
  
  resto = numerador.get_numero()%denominador.get_numero();
  numerador_aux = denominador;
  
  while(resto!=0)
  {
   resto_aux = resto;
   resto = numerador_aux.get_numero()%resto.get_numero();
   numerador_aux = resto_aux;
  }
  
  return numerador_aux;
}

racional operator+(const racional& a, const racional& b)
{  
  return racional(a.get_numerador()*b.get_denominador() + b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

racional operator-(const racional& a, const racional& b)
{ 
  return racional(a.get_numerador()*b.get_denominador() - b.get_numerador()*a.get_denominador(),a.get_denominador()*b.get_denominador());
}

racional operator*(const racional& a, const racional& b)
{ 
  return racional(a.get_numerador()*b.get_numerador(),a.get_denominador()*b.get_denominador());
}

racional operator/(const racional& a, const racional& b)
{
  return racional(a.get_numerador()*b.get_denominador(),a.get_denominador()*b.get_numerador());
}

//comparación
bool operator==(const racional& a, const racional& b)
{
  if((a.get_numerador()==b.get_numerador())&&(a.get_denominador()==b.get_denominador())) {
    return true;
  } else {
    return false;
  }
}

bool operator!=(const racional& a, const racional& b)
{
  return(a==b ? false:true);
}

bool operator<(const racional& a, const racional& b)
{
  if(a.get_numerador()==b.get_denominador())
  {
    return(a.get_denominador()<b.get_denominador() ? false:true);
    
  } else {
    
      if((a.get_numerador()*b.get_denominador())<(b.get_numerador()*a.get_denominador())) {
	return true;
      } else {
	return false;
      }
  }
  
}

bool operator>(const racional& a, const racional& b)
{
  if(a!=b) {
    return(a<b ? false:true);
  } else {
    return false;
  }
}

bool operator<=(const racional& a, const racional& b)
{
  return(a>b ? false:true);
}

bool operator>=(const racional& a, const racional& b)
{
  return(a<b ? false:true);
}

//Entrada-Salida
ostream& operator<<(ostream& os, const racional& a)
{
  os << a.get_numerador() << "/" << a.get_denominador();
  return os;
}

istream& operator>>(istream& is, racional& a)
{
  string n;
  is >> n;
  a = n;
  return is;
}

//-----------Heredados de la clase numero---------
ostream& racional::toStream(ostream& sout) const
{
    numerador.toStream(cout);
    cout << "/";
    denominador.toStream(cout);
  
    return sout;
}

 istream& racional::fromStream(istream& sin)
 {
    string a;
    sin >> a;
  
    try
    {
      size_t found = a.find("/");
    
      string b,c;
      b.resize(found);
      c.resize((a.size() - found)-1);
      for(unsigned int i=0;i<found;i++) 
      {
        b[i] = a[i];
      }
      for(unsigned int j=0;j<c.size();j++) 
      {
        c[j] = a[j+1+found];
      }
    
      numerador = atoi(b.c_str());
      denominador = atoi(c.c_str());
    
      if(!denominador.get_numero()||!numerador.get_numero())  throw("Error: no es posible introducir un número racional con denominador 0" ); //Si es igual a 0
      mcd = m_d();
      numerador = numerador/mcd;
      denominador = denominador/mcd;
     }
      catch(const char* error)
      {
        cerr << error<< endl;
        exit(1);
      }
    
  return sin;
  }
  
  
  
const entero racional::toEntero(void) const
{
  entero res( get_numerador() / get_denominador());
  int res2= res.get_numero();
  entero entero_from_racional= nearbyint(res2); //redondea al entero mas cercano
  
  return entero_from_racional;
}


 const real racional::toReal(void) const
{

  entero num(get_numerador());
  entero den(get_denominador());
  
  real real_from_racional(num.get_numero() / den.get_numero());
  
  return real_from_racional;
  
}

 const racional racional::toRacional(void) const
 {
   racional racional_from_racional(get_numerador(), get_denominador());
   
   return racional_from_racional;
 }
 
 
 const complejo racional::toComplejo(void) const
 {
   entero a(get_numerador());
   entero b(get_denominador());
   
   real parte_real(a.get_numero() / b.get_numero());
   real imaginaria(0.0);
   
   complejo complejo_from_racional(parte_real, imaginaria);
   
   return complejo_from_racional;
 }


 