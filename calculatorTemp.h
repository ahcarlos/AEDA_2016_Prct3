#pragma once 
#include <cstring>
#include <cstdlib>
#include <sstream>

#include "stackTemp.h"

using namespace std;

template <class T>
class calculator
{
    private:
        stackTemp<T> stack_;
    public:
        calculator(void);
        ~calculator(void);
        T compute(istream& expresion);
        
        bool is_operator(basic_istream<char>::int_type caracter);
        bool is_complex(basic_istream<char>::int_type caracter);
        bool is_rational(basic_istream<char>::int_type caracter);
};

template <class T>
calculator<T>::calculator(void):
stack_()
{}

template <class T>
calculator<T>::~calculator(void)
{}

template <class T>
T calculator<T>::compute(istream& input)
{
    T aux;
    T operand1;
    T operand2;
    T operando; //almacena los digitos para meter en la pila
    char operacion;
    char parentesis, comillas, fac;
    
    while(input.peek() != '=')
    {
        if(isdigit(input.peek())){ //en caso de ser un digito, es un operando, metemos en la pila
            input >> operando;
            stack_.push(operando);
        }
        else if(((is_complex(input.peek())) && (!isdigit(input.peek())))) //reconocemos parentesis para indicar numero complejo
        {
            input >> parentesis;
        }
        else if((is_rational(input.peek())) && (!isdigit(input.peek()))) //reconocemos comillas para indicar numero racional
        {
            input >> comillas;
        }
        else if(isblank(input.peek()))
        {
            input.ignore(1);
        }
        else
        {
            input >> operacion;
            switch(operacion)
            {
                case '+':
                    operand2= stack_.pop();
                    operand1= stack_.pop();
                    stack_.push(operand1 + operand2);
                break;
                
                case '-':
                    if(isdigit(input.peek())) //en caso de encontrar un simbolo '-' y que el elemento siguiente sea un digito, no es una operacion, sera un numero negativo
                    {
                        T negativo= -1;
                        input >> operando;
                        operando= operando * negativo;
                        stack_.push(operando);
                    }
                    else
                    {
                        operand2= stack_.pop();
                        operand1= stack_.pop();
                        stack_.push(operand1 - operand2);
                    }
                break;
                
                case '/':
                    operand2= stack_.pop();
                    operand1= stack_.pop();
                    stack_.push(operand1 / operand2);
                break;
                
                case '*':
                    operand2= stack_.pop();
                    operand1= stack_.pop();
                    stack_.push(operand1 * operand2);
                break;
            }
        }
    }
    
    return stack_.pop();
    
}

template <class T>
bool calculator<T>::is_operator(basic_istream<char>::int_type caracter)
{
    if((caracter == ' ') || (caracter == '(') || (caracter == ')') || (caracter == '"') )
    {
        return false;
    }
    else
    {
        return true;
    }
}

template <class T>
bool calculator<T>::is_complex(basic_istream<char>::int_type caracter)
{
    if( (caracter == '(') || (caracter == ')') )
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
bool calculator<T>::is_rational(basic_istream<char>::int_type caracter)
{
    if( caracter == '"' )
    {
        return true;
    }
    else
    {
        return false;
    }
}

