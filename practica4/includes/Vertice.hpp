/*!
	\file Vertice.hpp
	\brief Clase Vertice
	\author Jose Manuel Marquez Matarin
*/
#ifndef __VERTICE__
#define __VERTICE__
#include "librerias.hpp"
/*!
    \brief Espacio de nombres ed
*/
namespace ed{
/**Clase Vertice.*/
	class Vertice{
	//! \name Atributos privados de la clase Vertice
	private:
		    /*! Etiqueta del vertice*/
		int _label;

		    /*! Nombre del vertice*/
		std::string _data;

		//! \name Funciones publicas de la Clase Monticulo
	public:
		//Observadores
		//! \name Observadores
	
		/*!
		\brief Devuelve el valor de _Data
		\return Valor de _data
		*/
		std::string getData()const {
			return _data;
		}

		/*!
		\brief Devuelve la etiqueta del vertice
		\return Valor de _label
		*/
		int getLabel()const {
			return _label;
		}

		//Modificadores
		//! \name Modificadores

		/*!
		\brief Establece el vaor de _data
		\param Data std::string
		*/
		void setData(const std::string &Data){
			this->_data = Data;
		}
		/*!
		\brief Establece el vaor de _label
		\param Label int
		*/
		void setLabel(const int &Label){
			this->_label = Label;
		}


	};
}

#endif