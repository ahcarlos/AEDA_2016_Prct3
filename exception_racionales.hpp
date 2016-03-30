#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <exception>
#include <cstring>

using namespace std;

class racional_exception: public exception
{
};

class cero_division_exception : public racional_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'racional': No es posible la division por 0";
  }
};