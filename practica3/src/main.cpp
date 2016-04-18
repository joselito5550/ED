#include "../includes/librerias.hpp"
#include <string>
int menu(){
  int opcion;
    BORRAR;
    LUGAR(5,10);
    std::cout<<"Menú donantes";
    LUGAR(6,10);
    std::cout<<"1. Comprobar si el monticulo esta vacio";
    LUGAR(7,10);
    std::cout<<"2. Crear un monticulo de donantes a partir de un fichero";
    LUGAR(8,10);
    std::cout<<"3. Grabar un monticulo de donantes en un fichero";
    LUGAR(9,10);
    std::cout<<"4. Mostrar el donante que se encuentra en la cima del monticulo";
    LUGAR(10,10);
    std::cout<<"5. Simular la realizacion de una o mas donaciones";
    LUGAR(11,10);
    std::cout<<"6. Salir";
    std::cout<<"\n";
    std::cin>>opcion;
  return opcion;
}


int main(){
    ed::Donantes donantes;
    int opcion,donante;

    do{
      opcion = menu();
      switch (opcion) {
        case 1:
        BORRAR;
        if(donantes.empty()){
            LUGAR(6,10);
            std::cout<<"El monticulo de donantes esta vacío";
        }
        else{
            LUGAR(6,10);
            std::cout<<"El monticulo de donantes no esta vacío";
        }
        //Darle a enter para continuar
        break;

        case 2:
        BORRAR;
        LUGAR(6,10);
        std::cout<<"Introduce el nombre del fichero del cual desea cargar los donantes:";
        getchar();
        getline(std::cin,file);
        donantes.borrarDonantes();
        donantes.cargar_fichero(file);

        break;

        case 3:
        BORRAR;
        LUGAR(6,10);
        std::cout<<"Introduce el nombre del fichero donde desea salvar los donantes:";
        getchar();
        getline(std::cin,file);
        donantes.to_file(file);
        break;

        case 4:
        BORRAR;
        std::cout<<donantes.getCima();
        break;

        case 5:

        break;

        default:
        }
    }while(opcion!=6);

    return 0;
}