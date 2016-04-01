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
    std::cout<<"5. Buscar un donante por Nombre";
    LUGAR(11,10);
    std::cout<<"6. Mostrar todos los donantes";
    LUGAR(12,10);
    std::cout<<"7. Mostrar donantes segun su RH";
    LUGAR(13,10);
    std::cout<<"8. Borrar un donante de una lista";
    LUGAR(14,10);
    std::cout<<"9. Salir";
    std::cout<<"\n";
    std::cin>>opcion;
  return opcion;
}


int main(){
    int opcion;
    std::string Name;
    std::string SecondName;
    Donantes donantes;
    Donante d;

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
          d.readDonante();
          donantes.insertDonante(d);
          break;
        case 5:
          BORRAR;
          LUGAR(6,10);
          std::cout<<"Name to search: ";
          getchar();
          getline(std::cin,Name);
          std::cout<<"SecondName to search: ";
          getline(std::cin,SecondName);
          d=donantes.findItem(Name,SecondName);
          if(d.getName()=="No encontrado"){
            std::cout<<"No se ha encontrado el donante introducido";
          }
          else{
            std::cout<<"El donante introducido es:"<<d;
            getchar();
          }
          break;

          case 6:
            BORRAR;
            donantes.showlist();
            getchar();
          break;

          case 7:

          break;

          case 8:
            BORRAR;
            LUGAR(6,10);
            std::cout<<"Introduce el nombre del donante a borrar";
            getchar();
            getline(std::cin,Name);
            std::cout<<"Introduce el apellido del donante a borrar";
            getline(std::cin,SecondName);
            d = donantes.findItem(Name,SecondName);
            if(d.getName()!="No encontrado"){
              donantes.deleteDonante(d);
            }
            else{
              std::cout<<"\nEl donante introducido no existe";
              getchar();
            }
          break;
      }
    }while(opcion!=9);

    return 0;
}
