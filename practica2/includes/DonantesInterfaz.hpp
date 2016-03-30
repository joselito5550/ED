#ifndef __DONANTESINTERFAZ__
#define __DONANTESINTERFAZ__
#include "librerias.hpp"

namespace ed{
  class DonantesInterfaz{
  public:
      //Getter
      virtual bool empty()const = 0;
      virtual Donante findItem(std::string name, std::string secondName) = 0;
      virtual int getNumDon()const = 0;

      //Setter
      virtual void setNumDon(const int numDonantes) = 0;
      virtual void insertDonante(const Donante& d) = 0;
      virtual void deleteDonante(const Donante& d) = 0;
  };

}
#endif
