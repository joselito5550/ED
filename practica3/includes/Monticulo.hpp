
#ifndef __MONTICULO__
#define __MONTICULO__
#include "librerias.hpp"
namespace ed{
/*!
	\brief Clase DonanteInterfaz usada por Donante
*/
  class Monticulo: public MonticuloInterfaz{
//! \name Atributos privados de la clase Monticulo
  private:
    //Vector de Donantes
    std::vector<Donante> _v;
    int num_element;

    int right_son(int i){
      return i*2+2;
    }

    int left_son(int i){
      return i*2+1;
    }
//! \name Funciones publicas de la Clase Monticulo
  public:
    Monticulo(){
      num_element=0;
    }
    bool empty()const{
      return _v.empty();
    }

    Donante cima()const{
      if(num_element!=0)
      return _v.front();
      else{
          Donante d("NoHay","","",true);
          return d;
      }
      
    }

    void insertar(const Donante& d){
      //Si no hay elementos
      if(num_element==0){
        //Elemento raiz
        _v.push_back(d);
        num_element++;
        std::cout<<_v[0].getName()<<d.getDonaciones();
      }
      //Si hay elementos
      else{
        std::vector<Donante>::iterator it=_v.begin();
        for(int i=0;i<num_element;i++){
            it++;
        }
        //Lo insertamos al final
        _v.insert(it,d);
        int n = num_element;
        Donante aux;
        //Mientras que el hijo sea menor que el padre lo vamos intercambiando
        std::cout<<_v[(n-1)/2].getDonaciones();
        while(_v[((n-1)/2)].getDonaciones()>_v[n].getDonaciones()){
          //hacemos el intercambio
          std::swap(_v[n],_v[(n-1)/2]);
          //Miramos al nuevo padre
          n = ((n-1)/2);
        }
        num_element++;
      }
    }

    void deleteCima(){
      if(num_element!=0){
        //El ultimo elemento lo ponemos de raiz, y hundimos
        int n = 0;
        bool posicionado = false;
        num_element--;
        std::swap(_v[0],_v[num_element]);
        Donante aux;
        int hijo_menor; //Guardaremos la posicion del hijo 
        int hijo_derecho;
        int hijo_izquierdo;
        while(n<num_element && !posicionado){
          //Con posicionado controlamos si tiene algun hijo menor aun o ya hemos encontrado su posicion
          hijo_derecho = right_son(n);
          hijo_izquierdo = left_son(n);
          //Si existen los dos hijos
          if(hijo_derecho<num_element && hijo_izquierdo<num_element){
            if(_v[hijo_derecho].getDonaciones()<_v[hijo_izquierdo].getDonaciones()){
            hijo_menor = right_son(n);
            }
            else if(_v[hijo_derecho].getDonaciones()>_v[hijo_izquierdo].getDonaciones()){
            hijo_menor = left_son(n);
            }
            if(_v[hijo_menor].getDonaciones() < _v[n].getDonaciones()){
            //Intercambiamos
            std::swap(_v[hijo_menor],_v[n]);
            n = hijo_menor;
            }
            else{
            posicionado = true;
            }
          }
          //si solo existe el hijo derecho
          else if(hijo_derecho<num_element && hijo_izquierdo>=num_element){
            if(_v[hijo_derecho].getDonaciones() < _v[n].getDonaciones()){
                std::swap(_v[hijo_derecho],_v[n]);
                n = hijo_derecho;
                posicionado = true;
            }    
            else{
                posicionado = true;
            }
          }
          //si solo existe el hijo izquierdo
          else if(hijo_derecho>=num_element && hijo_izquierdo<num_element){
              if(_v[hijo_izquierdo].getDonaciones() < _v[n].getDonaciones()){
                  std::swap(_v[hijo_izquierdo],_v[n]);
                  posicionado = true;
              }
              else{
                  posicionado = true;
              }
          }
          else posicionado = true;
        }
      }
    }
    void borrarMonticulo(){
        int n = num_element;
        for(int i=0;i<n;i++){
            deleteCima();
        }

    }
    void to_file(std::string file){
        std::ofstream f;
        Donante aux;
        f.open(file,std::ofstream::out);
        if(f.fail()){
          std::cout<<"Error al abrir el fichero";
        }
        for(int i=0;i<num_element;i++){
          aux = _v[i];
          f<<aux.getSecondName()<<";"<<aux.getName()<<";"<<aux.getGroup()<<";"<<aux.getRH()<<";"<<aux.getDonaciones()<<"\n";
        }
        f.close();
    }

    void cargar_fichero(std::string file){
        std::ifstream f;
        Donante aux;
        std::string line;
        std::string apellido, name, group, rh_aux, donaciones;
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
            getline(line_aux, donaciones,';');

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
            aux.setDonaciones(atoi(donaciones.c_str()));
            insertar(aux);
          }
        }

    }

  };
}

#endif
