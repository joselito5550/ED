/*!
	\file Polinomio.cpp
	\brief Funciones Polinomio
	\author Jose M. Márquez Matarín
*/
#include "../includes/librerias.hpp"
using namespace ed;

void Polinomio::leerPolinomio(){
	Monomio m;
	int grado_aux, aux;
	std::list<Monomio> list;

	std::cout<<"Introduce el grado del polinomio\n";
	std::cin>>grado_aux;
	for(int i=0;i<grado_aux+1;i++){
		std::cout << "Introduce el coeficiente de exponente "<< i << std::endl;
		std::cin >> aux;
		m.setCoef(aux);
		m.setExp(i);
		list.push_back(m);
	}
	monomios = list;
	grado = grado_aux;
	NumMon = monomios.size();
}

void Polinomio::escribirPolinomio(){
	std::list<Monomio>::iterator it;
	it = monomios.begin();
	while(it!=monomios.end()){
		std::cout<<*it<<" + ";
	}
}



Polinomio Polinomio::operator+(Polinomio polinomio){
	std::list<Monomio>::iterator it;
	Polinomio aux = *this;
	Polinomio aux2;
	it = polinomio.monomios.begin();
	while(it!=polinomio.monomios.end()){
		if(it->getExp()>grado){
			aux.grado = it->getExp();
		}
		aux.add_monomio(*it);
		it++;
	}
	//Recorremos el vector y buscamos los monomios de mismo grado y sumamos
	//sus coeficientes
	for(int i = aux.getGrado(); i >= 0; i--){
		 Monomio mAux(i,0);
		 for(it = aux.monomios.begin(); it != aux.monomios.end(); it++){
			 if( it->getExp() == i)
				 if(it->getCoef() != 0)
					 mAux.setCoef(mAux.getCoef()+it->getCoef());
		 }
		 if(mAux.getCoef() != 0)
			 aux2.add_monomio(mAux);
	 }
	aux2.setGrado(aux.getGrado());
 	return aux2;

}

Monomio Polinomio::getMon(int pos){
  std::list<Monomio>::iterator it;
  it = monomios.begin();
  Monomio m;
  if(pos>=0 && pos<monomios.size()){
    for(int i=0;i<pos;i++){
      it++;
    }
    m.setExp(it->getExp());
    m.setCoef(it->getCoef());
  }
  return m;
}

/*
Monomio Polinomio::getMon(int pos)
*/
void Polinomio::add_monomio(Monomio &m){
	this->monomios.push_back(m);
	if(m.getExp()>grado){
		grado = m.getExp();
	}
	NumMon++;
	//Error
	//simplificar_mon();
}

Polinomio Polinomio::operator*(Polinomio polinomio){
	std::list<Monomio>::iterator i1, i2;
	Polinomio auxiliar, auxiliar2;
  for(i1 = this->monomios.begin(); i1 != this->monomios.end(); i1++){
    for(i2 = polinomio.monomios.begin(); i2 != polinomio.monomios.end(); i2++){
      auxiliar.add_monomio((*i1)*(*i2));
      }
  }
	//Recorremos el vector y buscamos los monomios de mismo grado y sumamos
	//sus coeficientes
	for(int i = auxiliar.getGrado(); i > 0; i--){
		Monomio mAux(i,0);
	 	for(i1 = auxiliar.monomios.begin(); i1 != auxiliar.monomios.end(); i1++){
		 if( i1->getExp() == i)
		 	if(i1->getCoef() != 0)
			 mAux.setCoef(mAux.getCoef()+i1->getCoef());
		}
		if(mAux.getCoef() != 0)
		 auxiliar2.add_monomio(mAux);
	}
	return auxiliar2;
}

namespace ed{
std::ostream& operator<<(std::ostream &stream,Polinomio& p){
	std::list<Monomio>::iterator it;
	it = p.monomios.begin();
	for(int i = 0; i<p.monomios.size();i++){
		if(i!=p.monomios.size()-1)
		stream<<*it<<"+";
		else stream<<*it;
		it++;
	}
	return stream;
}

std::istream& operator>>(std::istream &stream, Polinomio& p){
	p.leerPolinomio();
}
}

int Polinomio::calcular_monomio(const int& x){
	int resultado = 0;
	std::list<Monomio>::iterator it;
	for(it = monomios.begin(); it != monomios.end() ; it++){
		resultado+=it->calcular_monomio(x);
	}
	return resultado;
}

Polinomio& Polinomio::operator=(Polinomio polinomio){
	this->monomios = polinomio.monomios;
	this->grado = polinomio.grado;
	this->NumMon = polinomio.NumMon;
	return *this;
}
