#ifndef __MONOINTERFAZ__
#define __MONOINTERFAZ__

#include "iostream"

namespace ed{
	class MonomioInterfaz{
	public:
		virtual double getCoef() const = 0;
		virtual int getExp() const = 0;
		virtual void setCoef(const double& coef)  = 0;
		virtual void setExp(const int& exp) = 0;
	};
}

#endif