/*!
	\file Polinomio.hpp
	\brief Clase polinomio
	\author Jose M. Márquez Matarín

*/

#ifndef __POLINOMIO__
#define __POLINOMIO__
#include "../includes/librerias.hpp"

namespace ed{

/*!
	\brief Clase Polinomio hereda de PolinomioInterfaz
*/
	class Polinomio: public PolinomioInterfaz{
private:
  std::list<Monomio> monomios;
  int NumMon;
  int grado;
public:

	// ! \name Constructores

	/*!
		\brief Constructor usado cuando se crea un nuevo polinomio
		\post Valores a 0 y lista vacia
	*/
  Polinomio(){
		NumMon = 0;
		grado = 0;
  }

	/*!
	\brief Constructor usado cuando se crea un nuevo polinomio
	\param Polinomio pasado por referencia
	\post Sera una copia del polinomio pasado por referencia
	*/
  Polinomio(const Polinomio& pol){
    this->monomios = pol.monomios;
    this->NumMon = pol.NumMon;
    this->grado = pol.grado;
  }

	/*!
		\brief Constructor usado cuando se crea un nuevo polinomio
		\param Monomio pasado por referencia
		\post La lista estará compuesta solo por este monomio
	*/
  Polinomio(Monomio &m){
    monomios.push_back(m);
    NumMon = 1;
  }
	// ! \name Observadores

	/*!
		\brief Devuelve el grado
		\return grado
	*/
	inline int getGrado()const{
		return grado;
	}

	/*!
		\brief Devuelve el numero de monomios
		\return NumMon
	*/
	inline int getNumMon()const{
		return NumMon;
	}

	/*!
		\brief Devuelve el monomio iesimo
		\return Monomio iesimo
	*/
	Monomio getMon(int pos);

	/*!
		\brief Establece el grado pasado por parametro
		\param Grado que se desea establecer
		\post El polinomio debe de ser de dicho grado
	*/
	inline void setGrado(int grado_aux){
		grado = grado_aux;
	}

	/*!
		\brief Esteblece el numero de monomios del polinomio
		\param Numero de monomios
		\post El polinomio debe de tener dicho numero de monomios
	*/
	inline void setNumMon( int NumMon){
		this->NumMon = NumMon;
	}

	// ! \name Funciones de la clase
	/*!
		\brief Funcion para leer un polinomio por teclado
		\post El polinomio debe ser el introducido por teclado
	*/
  void leerPolinomio();

	/*!
		\brief Funcion para sacar el Polinomio por pantalla
	*/
  void escribirPolinomio();

	/*!
		\brief Funcion para añadir un monomio al monomio
		\param Monomio que se desea introducir
		\post El monomio introducido debe de estar en el polinomio
	*/
  void add_monomio(Monomio &m);

	/*!
		\brief Funcion para calcular el polinomio segun un valor de x
		\param Valor de x
		\return Valor del polinomio para dicho valro de x
	*/
	int calcular_monomio(const int& x);

	/*!
		\brief Sobrecarga del operador + para suma de polinomios
		\param polinomio
		\return suma de ambos polinomios
		\post Ambos polinomios no deben de ser alterados
	*/
  Polinomio operator+(Polinomio polinomio);

	/*!
		\brief Sobrecarga del operador =
		\param Polinomio
		\return polinomio
	*/
  Polinomio& operator=(Polinomio polinomio);

	/*!
		\brief Sobrecarga del operador *
		\param Polinomio
		\return Multiplicacion de ambos polinomios
	*/
  Polinomio operator*(Polinomio polinomio);

	/*!
		\brief ¿Esta vacio el polinomio?
		\return True si esta vacia, False en caso contrario
	*/
  inline bool is_empty()const{
    return monomios.empty();
  }

	/*!
		\brief Funcion amiga, sobrecarga del operador <<
		\param Stream, Polinomio
		\return Stream
	*/
	friend std::ostream& operator<<(std::ostream &stream,Polinomio& p);

	/*!
		\brief Funcion amiga, sobrecarga del operador >>
		\param Stream, Polinomio
		\return Stream
	*/
	friend std::istream& operator>>(std::istream &stream, Polinomio& p);

};
}
#endif
