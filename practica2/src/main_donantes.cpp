#include "../includes/librerias.hpp"
#include <string>
using namespace ed;
int menu(){
  int opcion;
    BORRAR;
    LUGAR(5,10);
    std::cout<<"Menú donantes";
    LUGAR(6,10);
    std::cout<<"1. Comprobar si hay donantes";
    LUGAR(7,10);
    std::cout<<"2. Cargar una lista de donantes desde fichero";
    LUGAR(8,10);
    std::cout<<"3. Grabar una lista de donantes en un fichero";
    LUGAR(9,10);
    std::cout<<"4. Insertar un Donante";
    LUGAR(10,10);
    std::cout<<"5. Fin del programa";
    std::cout<<"\n";
    std::cin>>opcion;
  return opcion;
}


int main(){

    int opcion,donante;

    do{
      opcion = menu();
      switch (opcion) {
        case 1:
          break;
        case 2:
          break;
        case 3:
          break;
        case 4:
          break;
      }
    }while(opcion!=5);

    return 0;
}
