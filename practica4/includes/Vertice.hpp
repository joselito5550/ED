#ifndef __VERTICE__
#define __VERTICE__
#include "librerias.hpp"

namespace ed{

	class Vertice{
	private:
		int _label;
		std::string _data;
	public:
		//Observadores

		std::string getData()const {
			return _data;
		}

		int getLabel()const {
			return _label;
		}

		//Modificadores

		void setData(const std::string &Data){
			this->_data = Data;
		}

		void setLabel(const int &Label){
			this->_label = Label;
		}


	};
}

#endif