#include "Monomio.hpp"
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

Monomio& Monomio::operator=(const Monomio& monomio){
	this->_coef=monomio.getCoef();
	this->_exp=monomio.getExp();
	return *this;
}

int Monomio::calcular_monomio(const int& x){
	int aux = x;
	aux = pow(aux,_exp);	
	aux = aux*(int)_coef;
	return aux;
}
