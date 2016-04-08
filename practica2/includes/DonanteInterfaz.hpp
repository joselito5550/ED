/*!
	\file DonanteInterfaz.hpp
	\brief Interfaz de la clase donante
	\author Jose Manuel Marquez Matarin
*/

#ifndef __DONANTEINTERFAZ__
#define __DONANTEINTERFAZ__
#include "librerias.hpp"
/*!
	\brief Espacio de nombres ed
*/
namespace ed{
/*!
	\brief Clase DonanteInterfaz usada por Donante
*/
  class DonanteInterfaz{
  public:
//! \name Observadores
	
	
      //Getter
	/*!
		\brief Devuelve el nombre del Donante
		\return String, nombre del donante
	*/
      virtual std::string getName()const = 0;

	/*!
		\brief Devuelve el apellido del Donante
		\return String, apellido del donante
	*/
      virtual std::string getSecondName()const = 0;

	/*!
		\brief Devuelve el grupo sanguineo del donante
		\return String, grupo sanguineo del donante	
	*/
      virtual std::string getGroup()const = 0;

	/*!
		\brief Devuelve el factorRH del donante
		\return BOOl, factorRH del donante	
	*/
      virtual bool getRH()const = 0;

	//! \name Modificadores
      //Setter
	/*!
		\brief Establece como nombre el string pasado por parametro
		\param String Name
		\post El donante debera de tener el nombre de la variable Name
	*/	
      virtual void setName(const std::string& Name) = 0;

	/*!
		\brief Establece como apellido el string pasado por parametro
		\param String SecondName
		\post El donante debera de tener el apellido de la variable SecondName
		
	*/	
      virtual void setSecondName(const std::string& SecondName) = 0;

	/*!
		\brief Establece como grupo Sanguineo el string pasado por parametro
		\param String Group
		\post El donante debera de tener el grupo de la variable Group
		
	*/
      virtual void setGroup(const std::string& Group) = 0;

	/*!
		\brief Establece como apellido el string pasado por parametro
		\param String SecondName
		\post El donante debera de tener el apellido de la variable SecondName
		
	*/
      virtual void setRH(const bool& RH) = 0;
  };

}
#endif
