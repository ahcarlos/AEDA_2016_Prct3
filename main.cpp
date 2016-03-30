#include <iostream>
#include <cstdlib>
#include <cmath>

//plantillas
#include "vectorTemp.h" //plantilla vector
#include "sllTemp.h" //plantilla lista
#include "stackTemp.h" //plantilla pila
#include "queueTemp.h" // plantilla cola


// clases de los numeros
#include "numero.hpp"
#include "entero.hpp"
#include "racional.hpp"
#include "real.hpp"
#include "complejo.hpp"



using namespace std;

int main (void)
{
    vectorTemp<Numero*> vector(4);
   	sllTemp<Numero*> 	lista;
   	stackTemp<Numero*> 	pila; 
	queueTemp<Numero*> 	cola;
   	
   	vector[0] = new entero(1);
	lista.insert_beginning(new nodeTemp<Numero*>(new entero(1)));
	pila.push(new entero(1));
	cola.put(new entero(1));

	vector[1] = new racional(3,4);
	lista.insert_beginning(new nodeTemp<Numero*>(new racional(3,4)));
	pila.push(new racional(3,4));
	cola.put(new racional(1,2));


	vector[2] = new real(8.0);
	lista.insert_beginning(new nodeTemp<Numero*>(new real(8.0)));
	pila.push(new real(8.0));
	cola.put(new real(8.0));
		
	vector[3] = new complejo(3.4,0.5);
	lista.insert_beginning(new nodeTemp<Numero*>(new complejo(3.4,0.5)));
	pila.push(new complejo(3.4,0.5));
	cola.put(new complejo(3.4,0.5));
   	
   	
   	Numero* n_entero = new entero(1);           //ejemplo de numero entero
   	Numero* n_racional = new racional(30,9);    // ejeplo de numero racional
   	Numero* n_real = new real(sqrt(2));         //ejemplo de numero real (raiz de 2)
   	Numero* n_complejo = new complejo(5.5,3);   //ejemplo de numero complejo
   	
   	
    cout << "************************************************************"<< endl;
    cout << "*-------------AyEDA: Polimorfismo y Excepciones------------*" << endl;
    cout << "************************************************************" << endl;
	cout<< endl;
   	cout << "Método toEntero" << endl;
   	cout << n_racional->toEntero() << endl;
   	cout << n_real->toEntero() << endl;
   	cout << n_complejo->toEntero() << endl;
   	cout << n_entero->toEntero() << endl;
   	
   	cout << endl;
   	
   	cout << "Método toReal" << endl;
   	cout << n_racional->toReal() << endl;
   	cout << n_real->toReal() << endl;
   	cout << n_complejo->toReal() << endl;
   	cout << n_entero->toReal() << endl;
   	
   	cout << endl;
   	
   	cout << "Método toRacional" << endl;
   	cout << n_racional->toRacional() << endl;
   	cout << n_real->toRacional() << endl;
   	cout << n_complejo->toRacional() << endl;
   	cout << n_entero->toRacional() << endl;
   	
   	cout << endl;
   	
   	cout << "Método toComplejo" << endl;
   	cout << n_racional->toComplejo() << endl;
   	cout << n_real->toComplejo() << endl;
   	cout << n_complejo->toComplejo() << endl;
   	cout << n_entero->toComplejo() << endl;
   	
   	cout << endl;

	
	cout << "Vector de números" << endl;
	vector.imprime_numero(cout);
	cout << endl;
	cout << "Lista de números" << endl;
	lista.imprime_numero(cout);
	cout << endl;
	cout << "Pila de números" << endl;
	pila.imprime_numero(cout);
	cout << endl;
	cout << "Cola de números" << endl;
	cola.imprime_numero(cout);
	cout << endl;
}