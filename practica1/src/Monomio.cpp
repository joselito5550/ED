/*!
	\file Monomio.cpp
	\brief Funciones Monomio
	\author Jose M. Márquez Matarín
*/
#include "../includes/librerias.hpp"
using namespace ed;
void Monomio::leerMonomio(){
      int exponente;
      double coeficiente;
      std::cout<<OKGREEN<<"Introduce el coeficiente"<<std::endl;
      std::cin>>coeficiente;
      std::cout<<OKGREEN<<"Introduce el exponente"<<std::endl;
      std::cin>>exponente;
      setExp(exponente);
      setCoef(coeficiente);
}


void Monomio::escribirMonomio(){
	  if(_exp==1 ){
	  	std::cout<<OKGREEN<<"Monomio: "<<_coef<<"x"<<std::endl;
	  }else if(_exp==0){
	  	std::cout<<OKGREEN<<"Monomio: "<<_coef<<std::endl;
	  }else if(_coef==0){
		std::cout<<OKGREEN<<"Monomio: 0"<<std::endl;
	  }
	  else{
	  	std::cout<<OKGREEN<<"Monomio: "<< _coef<<"x^"<<_exp<<std::endl;
	  }
}

int Monomio::calcular_monomio(const int& x){
  int aux = x;
  aux = pow(aux,_exp);
  aux = aux*(int)_coef;
  return aux;
}

//Overloaded function

Monomio& Monomio::operator=(const Monomio& monomio){
	this->_coef=monomio.getCoef();
	this->_exp=monomio.getExp();
	return *this;
}

Monomio& Monomio::operator*(const Monomio& monomio){
  this->_coef=(this->_coef)*monomio._coef;
  this->_exp=(this->_exp)+monomio._exp;
  return *this;
}

//friends function
namespace ed{
std::istream& operator>>(std::istream &stream,ed::Monomio &m){
	std::cout << "(Coeficiente, Exponente)";
	stream >> m._coef >> m._exp;
	stream.ignore();
	return stream;
}
std::ostream& operator<<(std::ostream &stream,ed::Monomio const &m){
  if(m._exp!=0){
	   stream<<m._coef<<"x^"<<m._exp;
  }
  else stream<<m._coef;
  	return stream;
}
}
