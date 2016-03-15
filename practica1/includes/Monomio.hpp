/*!
	\file Monomio.hpp
	\brief Clase Monomio
	\author Jose M. Márquez Matarín
*/

#ifndef __MONOMIO__
#define __MONOMIO__
#include "../includes/librerias.hpp"

namespace ed{
	/*!
		\brief Clase Monomio hereda de MonomioInterfaz
	*/
	class Monomio: public MonomioInterfaz {
private:
	double _coef;
	int _exp;
public:

	// ! \name Constructores

	/*!
		\brief Constructor usado cuando se crea un nuevo monomio
		\post Valores a 1
	*/
	inline Monomio(){
		_coef=1;
		_exp=1;
	}

	/*!
		\brief Constructor usado cuando se crea un nuevo polinomio
		\param Exponente y Coeficiente
		\post El monomio tendra los valores pasados por parametro
	*/
	inline Monomio(const int& exp, const double& coef){
		_coef= coef;
		_exp= exp;
	}

	/*!
		\brief Constructor usado cuando se crea un nuevo polinomio
		\param Monomio
		\post El monomio sera una copia del parametro
	*/
	inline Monomio(const Monomio& m){
		_coef = m._coef;
		_exp = m._exp;
	}

	// ! \name Observadores
	/*!
		\brief Devuelve el exponente del monomio
		\return Exponente
	*/
	inline int getExp()const{
		return _exp;
	}

	/*!
		\brief Devuelve el coeficiente del monomio
		\return coeficiente
	*/
	inline double getCoef()const{
		return _coef;
	}
	// ! \name Modificadores
	/*!
		\brief Establece el exponente pasado por parametro al monomio
		\param Exponente
		\post El monomio debera de tener dicho Exponente
	*/
	inline void setExp(const int& exp){
		_exp=exp;
	}

  /*!
		\brief Establece el coeficiente al monomio
		\param Coeficiente
		\post El monomio debera de tener dicho Coeficiente
	*/
	inline void setCoef(const double& coef){
		_coef=coef;
	}


	// ! \name Funciones de la clase

	/*!
		\brief Leer Monomio por teclado
		\post El monomio sera el leido por teclado
	*/
	void leerMonomio();

	/*!
		\brief Escribir el monomio por pantalla
		\post El monomio debera de aparecer por pantalla
	*/
	void escribirMonomio();

	//Overloaded function

	// ! \name Operadores sobrecargados

	/*!
		\brief Sobrecarga del operador =
		\param Monomio
		\return Monomio
	*/
	Monomio& operator=(const Monomio& monomio);

	/*!
		\brief Sobrecarga del operador *
		\param Monomio
		\return Devuelve el producto de los monomios
	*/
	Monomio& operator*(const Monomio& monomio);

	/*!
		\brief Calcular Monomio para un valor de x
		\param Valor de x
		\return Valor del monomio para un valro de x
	*/
	int calcular_monomio(const int& x);



	//friends function

	// ! \name Funciones amigas

	/*!
		\brief Sobrecarga del operador >>
		\param istream, monomio
		\return Stream
	*/
	friend std::istream& operator>>(std::istream &stream,ed::Monomio &m);

	/*!
		\brief Sobrecarga del operador <<
		\param Ostream, Monomio
		\return Stream
	*/
	friend std::ostream& operator<<(std::ostream &stream,ed::Monomio const &m);
};
}
#endif
