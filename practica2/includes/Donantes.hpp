/*!
	\file Donantes.hpp
	\brief Clase Donantes, hereda de DonantesInterfaz
	\author Jose Manuel Marquez Matarin
*/
#ifndef __DONANTES__
#define __DONANTES__
#include "librerias.hpp"
#include "DonantesInterfaz.hpp"
#include "Lista.hpp"

/*!
	\brief Espacio de nombres ed
*/
namespace ed{
/*!
	\brief Clase DonanteInterfaz usada por Donante
*/
  class Donantes: public DonantesInterfaz{
//! \name Atributos privados de la clase Donantes
  private:
    //Lista de Donantes
    Lista _l;
    int numDonantes;
//! \name Funciones publicas de la Clase Donantes
  public:

//! \name Constructores
    Donantes(){
      numDonantes = 0;
    }
    Donantes(const Donante &d){
        _l.insert(0,d);
    }

    //Getters
//! \name Observadores

	/*!
		\brief Devuelve True si no hay donantes
		\return Bool
	*/
    bool empty()const{
      return _l.empty();
    }

    //Devuelve con Nombre No encontrado si no lo encontramos
	/*!
		\brief Devuelve un objecto Donante con los mismos nombres y apellidos, en caso de no encontrarlo, devuelve un objecto Donante con Nombre = "No encontrado"
		\param String name, String SecondName
		\return Donante, nombre del donante
	*/
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
	/*!
		\brief Devuelve el numero de Donantes
		\return Int
	*/
    int getNumDon()const{
      return numDonantes;
    }

	//! \name Modificadores
	/*!
		\brief Establece el numero de Donantes numDonantes
		\param int numDonantes 
	*/
    void setNumDon(const int numDonantes){
      this->numDonantes=numDonantes;
    }
	/*!
		\brief Insertar un donante en la lista
		\param El donante a insertar
	*/
    void insertDonante(const Donante &d){
      int pos = _l.findPos(d);
      _l.insert(pos,d);
      numDonantes++;
    }
	/*!
		\brief Eliminar un donante
		\param El donante a eliminar
	*/
    void deleteDonante(const Donante &d){
      int pos = _l.findItem(d,0);
      if(pos!=-1)
      _l.remove(pos);
      else std::cout<<"No existe el elemento introducido a borrar";
      numDonantes--;
    }

	/*!
		\brief Posicion del donante pasado por parametro
		\param Donante d
		\return int
	*/
    int exist(Donante &d){
      return  _l.exist(d);
    }

	/*!
		\brief Mostrar la lista de Donantes
	*/
    void showlist(){
      BORRAR;
      _l.showlist();
      }

	/*!
		\brief Pasar los donantes a un fichero
		\param String, nombre del fichero
	*/
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

	/*!
		\brief Eliminar la lista de donantes
	*/
      void borrarLista(){
        _l.borrarLista();
      }

	/*!
		\brief Cargar una lista de donantes desde un fichero
		\param String, nombre del fichero
	*/
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

	/*!
		\brief Mostrar los donantes segun su RH
		\param Bool RH
	*/
      void showlistRH(bool RH){
        BORRAR;
        _l.showlistRH(RH);
      }


  };
}

#endif
