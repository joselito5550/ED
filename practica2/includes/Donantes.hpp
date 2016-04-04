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

      void to_file(std::string file){
        std::ofstream f;
        Donante aux;
        f.open(file,std::ofstream::out);
        if(f.fail()){
          std::cout<<"Error al abrir el fichero";
        }
        for(int i=0;i<numDonantes;i++){
          aux = _l.item(i);
          f<<aux.getSecondName()<<";"<<aux.getName()<<";"<<aux.getGroup()<<";"<<aux.getRH()<<"\n";
        }
        f.close();
      }

      void borrarLista(){
        _l.borrarLista();
      }


     void cargar_fichero(std::string file){
        std::ifstream f;
        Donante aux;
        std::string line;
        std::string apellido, name, group, rh_aux;
        bool rh;
        f.open(file.c_str());
        if(f.fail()) std::cout<<"Error al abrir el fichero";
        else{
          while(getline(f,line)){
            std::stringstream line_aux(line);
            getline(line_aux, apellido,';');
            getline(line_aux,name,';');
            getline(line_aux, group,';');
            getline(line_aux, rh_aux,';');

            aux.setName(name);
            aux.setSecondName(apellido);
            aux.setGroup(group);
            if(rh_aux=="1"){
              rh = true;
            }
            else{
              rh = false;
            }
            aux.setRH(rh);

            insertDonante(aux);
          }
        }
      }

      void showlistRH(bool RH){
        BORRAR;
        _l.showlistRH(RH);
      }


  };
}

#endif
