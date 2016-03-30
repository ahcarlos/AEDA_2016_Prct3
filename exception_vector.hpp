#include <cstdio>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <exception>
#include <cstring>

using namespace std;

class vector_exception: public exception
{
};


class overflow_index_exception : public vector_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': El índice especificado es mayor que el tamaño del vector";
  }
};



class underflow_index_exception : public vector_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Índice incorrecto (el índice no puede ser negativo)";
  }
};

class over_size_exception : public vector_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Tamaño máximo de vector excedido";
  }
};

class bad_size_exception : public vector_exception
{
public:
  virtual const char * what () const throw ()
  {
    return "Error en tiempo de ejecución en clase 'vector_t': Tamaño de vector incorrecto";
  }
};