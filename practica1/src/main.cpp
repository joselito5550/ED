/*!
	\file main.cpp
	\brief Main monomio
	\author Jose M. Márquez Matarín
*/
#include "../includes/librerias.hpp"
using namespace ed;
int main(){
      Monomio mon1(2,3);
      std::cout<<"He inicializado el monomio1 con exponente 2 y coeficiente 3\n";
      Monomio mon2;
      std::cout<<"He inicializado el monomio2 con exponente 1 y coeficiente 1\n";
      Monomio mon3(mon2);
      std::cout<<"He inicializado el monomio3 como una copia del monomio2\n";
      int x,opc=1,result,opc_mon;
      std::cin>>opc;
      do{
        std::cout<<"1. Calcular Monomio para un valor de x\n";
        std::cout<<"2. Multiplicar dos monomios y almacenar el resultado en el sobrante\n";
        std::cout<<"3. Salir\n";
        std::cin>>opc;
        switch (opc) {
          case 1:
            system("clear");
            std::cout<<"¿Para que monomio desea calcular su resultado segun un valor de x? (1,2,3)\n";
            std::cin>>opc_mon;
            std::cout<<"Introduce el valor de x\n";
            std::cin>>x;
            if(opc_mon==1){
              result = mon1.calcular_monomio(x);
            } else if(opc_mon==2){
              result = mon2.calcular_monomio(x);
            }
            else if(opc_mon==3){
              result = mon3.calcular_monomio(x);
            }
            else{
              std::cout<<"Error al introducir el monomio";
              result=-1;
            }
            std::cout<<"el resultado es: "<<result<<"\n";
          break;
          case 2:
            std::cout<<"Se multiplicara el primer monomio con el segundo y se almacenara en el tercero\n";
            mon3 = mon1*mon2;
            mon3.escribirMonomio();
          break;

          case 3:
            std::cout<<"Hasta luego!\n";
          break;

          default:
            std::cout<<"Opcion introducida incorrecta\n";
          break;
        }
      }while(opc!=3);


      return 0;
}
