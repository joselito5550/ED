#ifndef __POLINOMIOINTERFAZ__
#define __POLINOMIOINTERFAZ__

#include "librerias.hpp"
#include "Monomio.hpp"

namespace ed{
	class PolinomioInterfaz{
	public:
		//getter
		virtual int getNumMon() const = 0;
		virtual int getGrado() const = 0;
		virtual void setNumMon( int NumMon) = 0;
		virtual void setGrado(int grado_aux) =0;
		//virtual Monomio getMon(int pos) const = 0;
		virtual void add_monomio(Monomio &m) = 0;
		virtual bool is_empty() const = 0;
	};
}

#endif
