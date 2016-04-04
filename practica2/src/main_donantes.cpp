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
    std::cout<<"9. Modificar";
    LUGAR(15,10);
    std::cout<<"10. Salir";
    std::cout<<"\n";
    std::cin>>opcion;
  return opcion;
}


int main(){
    int opcion;
    std::string file;
    std::string Name;
    std::string SecondName;
    Donantes donantes;
    Donante d;

    do{
      opcion = menu();
      switch (opcion) {
        case 1:
        BORRAR;
        LUGAR(6,10);
        if(donantes.empty()){
          std::cout<<"La lista SI esta vacia";
        }
        else{
          std::cout<<"La lista NO esta vacia";
        }
        getchar();
        getchar();
          break;
        case 2:
        BORRAR;
        LUGAR(6,10);
        std::cout<<"Introduce el nombre del fichero:";
        getchar();
        getline(std::cin,file);
        donantes.borrarLista();
        donantes.cargar_fichero(file);
          break;
        case 3:
        getchar();
          getline(std::cin,file);
          donantes.to_file(file);
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
          BORRAR;
            char rh_aux;
            bool RH;
            std::cout<<"RH positivo o negativo(P/N):";
            std::cin>>rh_aux;
            if(rh_aux=='P' || rh_aux=='p'){
              RH = true;
            }
            else{
              RH = false;
            }
            donantes.showlistRH(RH);
            getchar();
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
          case 9:
          BORRAR;
          LUGAR(6,10);
          std::cout<<"Introduce el nombre del donante que desea modificar:";
          getchar();
          getline(std::cin,Name);
          std::cout<<"Introduce el apellido del donante que desea modificar:";
          getline(std::cin,SecondName);
          d = donantes.findItem(Name,SecondName);
          if(d.getName()!="No encontrado"){
              donantes.deleteDonante(d);
              d.modify();
              donantes.insertDonante(d);
          }
          else{
            std::cout<<"No encontrado";
          }
      }
    }while(opcion!=10);

    return 0;
}
