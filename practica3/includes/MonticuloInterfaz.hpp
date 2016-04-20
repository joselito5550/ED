#ifndef __MONTICULOINTERFAZ__
#define __MONTICULOINTERFAZ__
#include "librerias.hpp"

/*!
	\brief Espacio de nombres ED
*/
namespace ed{
/*!
	\brief Clase MonticuloInterfaz
*/
  class MonticuloInterfaz{
  public:

	//! \name Observadores
      //Getter
	/*!
		\brief Devuelve True si no hay donantes
		\return Bool
	*/
      virtual bool empty()const = 0;

	/*!
		\brief Devuelve el donante que se encuentre en la cima
		\return Donante
	*/
      virtual Donante cima()const = 0;

	//! \name Modificadores
      //Setter
	/*!
		\brief Inserta un Donante en el monticulo siguiendo el criterio de ordenacion
		\param Donante d
	*/
      virtual void insertar(const Donante &d) = 0;

	/*!
		\brief Elimina el donante que se encuentre en la cima
	*/
      virtual void deleteCima() = 0;
  };

}
#endif
