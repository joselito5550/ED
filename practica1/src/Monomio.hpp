#ifndef __MONOMIO__
#define __MONOMIO__
#include "../includes/librerias.hpp"

namespace ed{
	class Monomio: public MonomioInterfaz {
private:
	double _coef;
	int _exp;
public:
	inline Monomio(){
		_coef=1;
		_exp=1;
	}

	inline Monomio(const int& exp, const double& coef){
		_coef= coef;
		_exp= exp;
	}

	inline int getExp()const{
		return _exp;
	}

	inline double getCoef()const{
		return _coef;
	}
	inline void setExp(const int& exp){
		_exp=exp;
	}
	inline void setCoef(const double& coef){
		_coef=coef;
	}

	void leerMonomio();
	void escribirMonomio();

	Monomio& operator=(const Monomio& monomio);
	int calcular_monomio(const int& x);
};
}
#endif
