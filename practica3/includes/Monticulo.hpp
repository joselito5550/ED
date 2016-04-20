
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
    //Lista de Donantes
    std::vector<Donante> _v;
    int num_element;

    int rigth_son(int i){
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
      return _v.front();
    }

    void insertar(Donante &d){
      //Si no hay elementos
      if(num_element==0){
        //Elemento raiz
        _v[0]=d;
        num_element++;
      }
      //Si hay elementos
      else{
        //Lo insertamos al final
        _v[num_element]=d;
        int n = num_element;
        Donante aux;
        //Mientras que el hijo sea menor que el padre lo vamos intercambiando
        while(_v[(n-1)/2]>_v[n]){
          //hacemos el intercambio
          aux = v[n];
          v[n] = v[(n-1)/2];
          v[(n-1)/2] = aux;
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
        _v[0] = _v[num_element];
        Donante aux;
        num_element--;
        int hijo_menor;
        while(n<num_element && !posicionado){
          if(_v[rigth_son(n)].getDonaciones()<_v[left_son(n)].getDonaciones()){
            hijo_menor = rigth_son(n);
          }
          else if(_v[rigth_son(n)].getDonaciones()>_v[left_son(n)].getDonaciones()){
            hijo_menor = left_son(n);
          }
          if(_v[hijo_menor] < _v[n]){
          //Intercambiamos
            aux = v[hijo_menor];
            v[hijo_menor] = v[n];
            v[n] = aux;
            n = hijo_menor;
        }
        else{
          posicionado = true;
        }
      }
    }

    void borrarMonticulo(){

    }
    void to_file(std::string file){

    }

    void cargar_fichero(std::string file){

    }

  };
}

#endif
