/*!
	\file main_polinomio.cpp
	\brief Main
	\author Jose M. Márquez Matarín
*/
#include "../includes/librerias.hpp"
using namespace ed;
int main(){
      int opc;
      Polinomio p1;
      Monomio m(1,1);
      Polinomio p2(m);
      Polinomio p3(p2);


      std::cout<<"Leer polinomio1"<<std::endl;
      p1.leerPolinomio();

      std::cout<<"Leer polinomio2"<<std::endl;
      p2.leerPolinomio();

      std::cout<<"P1: ";
      std::cout<<p1<<std::endl;
      std::cout<<"P2: ";
      std::cout<<p2<<std::endl;
      std::cout<<"P3: ";
      std::cout<<p3<<std::endl;
      int x;
      do{
        std::cout<<"\n";
        std::cout<<"1. Calcular Polinomio para un valor de x\n";
        std::cout<<"2. Multiplicar dos polinomios\n";
        std::cout<<"3. Sumar dos polinomios\n";
        std::cout<<"4. Añadir polinomio haciendo uso del operador >>\n";
        std::cout<<"5. Salir\n";
        std::cin>>opc;
        switch (opc) {
          case 1:
          std::cout<<"\nIntroduce el valor de x a calcular (se hara sobre el p1)\n";
          std::cin>>x;
          std::cout<<"El resultado es:"<<p1.calcular_monomio(x);
          break;
          case 2:
          p3 = p1*p2;
          std::cout<<"Hecha operacion p3=p1*p3"<<std::endl;
          std::cout<<p3;
          break;
          case 3:
          std::cout<<"Sumando p1+p2"<<std::endl;
          p3 = p1+p2;
          std::cout<<p3;
          break;
          case 4:
          Polinomio p4;
          std::cin>>p4;
          std::cout<<"Este es el polinomio introducido: ";
          std::cout<<p4;
        }
      }while(opc!=5);


      return 0;
}
