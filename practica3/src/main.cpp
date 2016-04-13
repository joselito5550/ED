#include "../includes/librerias.hpp"
#include <string>
using namespace ed;
int menu(){
  int opcion;
    BORRAR;
    LUGAR(5,10);
    std::cout<<"Menú donantes";
    LUGAR(6,10);
    std::cout<<"1. Leer un donante desde teclado";
    LUGAR(7,10);
    std::cout<<"2. Escribir un donante por pantalla";
    LUGAR(8,10);
    std::cout<<"3. Modificar los datos de un donante";
    LUGAR(9,10);
    std::cout<<"4. Comparar lexicograficamente dos donantes";
    LUGAR(10,10);
    std::cout<<"5. Fin del programa";
    std::cout<<"\n";
    std::cin>>opcion;
  return opcion;
}


int main(){
    Donante don1;
    std::string Name = "Jose";
    std::string SecondName = "Marquez";
    std::string Group = "A";
    Donante don2(Name,SecondName,Group,false);
    Donante don3(don1);

    int opcion,donante;

    do{
      opcion = menu();
      switch (opcion) {
        case 1:
          don1.readDonante();
          break;
        case 2:
        BORRAR;
        LUGAR(6,10);
        std::cout<<"¿Que donante desea mostrar por pantalla? (1,2,3)";
        std::cin>>donante;
        switch (donante) {
          case 1:
            BORRAR;
            don1.writeDonante();
            std::cout<<"\nIntroduzca un numero para continuar...\n";
            std::cin>>donante;
            break;
          case 2:
          BORRAR;
          don2.writeDonante();
          std::cout<<"\nIntroduzca un numero para continuar...\n";
          std::cin>>donante;
          break;
          case 3:
          BORRAR;
          don3.writeDonante();
          std::cout<<"\nIntroduzca un numero para continuar...\n";
          std::cin>>donante;
          break;
        }
        break;

        case 3:
        BORRAR;
        LUGAR(6,10);
        std::cout<<"¿Que donante desea modificar?(1,2,3)";
        std::cin>>donante;
        switch (donante) {
          case 1:
          don1.modify();
          break;
          case 2:
          don2.modify();
          break;
          case 3:
          don3.modify();
          break;
        }
        break;

        //Comprobar operator <=
        case 4:
        BORRAR;
        LUGAR(5,10);
        std::cout<<"Se comparará el primer donante con el segundo.";
        LUGAR(7,10);
        if(don1<=don2){
          BORRAR;
          don2.writeDonante();
          std::cin>>donante;
          BORRAR;
          don1.writeDonante();
          std::cin>>donante;
        }
        else{
          BORRAR;
          don1.writeDonante();
          std::cin>>donante;
          BORRAR;
          don2.writeDonante();
          std::cin>>donante;
        }
      }
    }while(opcion!=5);

    return 0;
}
