#ifndef __DONANTES__
#define __DONANTES__
#include "librerias.hpp"
#include "DonantesInterfaz.hpp"
#include "Lista.hpp"

namespace ed{
  class Donantes: public DonantesInterfaz{
  private:
    //Lista de Donantes
    Lista _l;
    int numDonantes;
  public:
    Donantes(){
      numDonantes = 0;
    }
    Donantes(const Donante &d){
        _l.insert(0,d);
    }

    //Getters
    bool empty()const{
      return _l.empty();
    }

    //Devuelve con Nombre No encontrado si no lo encontramos
    Donante findItem(std::string name,std::string secondName){
      Donante aux;
      aux.setName (name);
      aux.setSecondName (secondName);
      int pos = _l.findItem(aux,0);
      if(pos!=-1){
        return _l.item(pos);
      }
      else{
        aux.setName( "No encontrado");
        return aux;
      }
    }

    int getNumDon()const{
      return numDonantes;
    }

    void setNumDon(const int numDonantes){
      this->numDonantes=numDonantes;
    }

    void insertDonante(const Donante &d){
      int pos = _l.findPos(d);
      _l.insert(pos,d);
      numDonantes++;
    }
    void deleteDonante(const Donante &d){
      int pos = _l.findItem(d,0);
      if(pos!=-1)
      _l.remove(pos);
      else std::cout<<"No existe el elemento introducido a borrar";
      numDonantes--;
    }

    int exist(Donante &d){
      return  _l.exist(d);
    }
    void showlist(){
      BORRAR;
      _l.showlist();
      }

  };
}

#endif
