#ifndef __DONANTESINTERFAZ__
#define __DONANTESINTERFAZ__
#include "librerias.hpp"

namespace ed{
  class DonantesInterfaz{
  public:
      //Getter
      virtual bool empty()const = 0;
      virtual Donante findItem(std::string name, std::string secondName)const = 0;

      //Setter
      virtual void insertDonante(const Donante& d) = 0;
      virtual void deleteDonante(const Donante& d) = 0;
  };

}
#endif
