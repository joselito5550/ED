#include "Monomio.hpp"
#include "../includes/librerias.hpp"
using namespace ed;
int main(){
      Monomio aux(2,3);
      std::cout<<"He inicializado con exponente 2 y coeficiente 3\n";
      aux.leerMonomio();
      aux.escribirMonomio();
      

      int x;
      std::cout<<"Calcular el Monomio para un valor de x: ";
      std::cin>>x;
      int result = aux.calcular_monomio(x);
      std::cout<<"Para x = "<<x<<" el Monomio vale --->"<<result<<std::endl;
      return 0;
}
