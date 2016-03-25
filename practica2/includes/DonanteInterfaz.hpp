#ifndef __DONANTEINTERFAZ__
#define __DONANTEINTERFAZ__
#include "librerias.hpp"

namespace ed{
  class DonanteInterfaz{
  public:
      //Getter
      virtual std::string getName()const = 0;
      virtual std::string getSecondName()const = 0;
      virtual std::string getGroup()const = 0;
      virtual bool getRH()const = 0;

      //Setter
      virtual void setName(const std::string& Name) = 0;
      virtual void setSecondName(const std::string& SecondName) = 0;
      virtual void setGroup(const std::string& Group) = 0;
      virtual void setRH(const bool& RH) = 0;
  };

}
#endif
