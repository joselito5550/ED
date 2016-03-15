#ifndef __MONOINTERFAZ__
#define __MONOINTERFAZ__

#include "librerias.hpp"


namespace ed{
	class MonomioInterfaz{
	public:
		//getter
		virtual double getCoef() const = 0;
		virtual int getExp() const = 0;

		//setter
		virtual void setCoef(const double& coef)  = 0;
		virtual void setExp(const int& exp) = 0;
	};
}

#endif
