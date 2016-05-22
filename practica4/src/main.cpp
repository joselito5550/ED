#include "../includes/librerias.hpp"
#include <iostream>
int menu(){
  int opcion;
    BORRAR;
    LUGAR(5,10);
    std::cout<<"Menú donantes";
    LUGAR(6,10);
    std::cout<<"1. Cargar un grafo desde un fichero";

    LUGAR(7,10);
    std::cout<<"2. Buscar camino minimo entre dos ciudades";

    LUGAR(8,10);
    std::cout<<"1. Cargar un grafo desde un fichero";

    LUGAR(9,10);
    std::cout<<"1. Cargar un grafo desde un fichero";

    LUGAR(10,10);
    std::cout<<"1. Cargar un grafo desde un fichero";

    std::cout<<"\n";
    std::cin>>opcion;
  return opcion;
}

using namespace ed;
int main(){
	Grafo *grafo;
	Vertice v,u;
	double **distancias = NULL;
	int **recorridos = NULL;
	std::string file_name;
	int opc=0;
	std::string name_origen, name_destino;

	while(opc != 6){
		opc = menu();
		switch(opc){
			case 1:
			std::cout<<"Introduce el nombre del fichero:";
			getchar();
        	getline(std::cin,file_name);
			grafo = cargarFichero(file_name);
			std::cout<<"Todo ok";
			break;

			case 2:
			std::cout<<"Introduce el nombre de la ciudad de origen:";
			getchar();
        	getline(std::cin,name_origen);
        	std::cout<<"Introduce el nombre de la ciudad de origen:";
        	
        	getline(std::cin,name_destino);

        	grafo->searchVertex(name_origen);
        	v = grafo->currVertex();

        	grafo->searchVertex(name_destino);
        	u = grafo->currVertex();
			std::cout << "El camino mínimo es: "<< distancias[v.getLabel()][u.getLabel()]<<"\nEl recorrido es:";								// muestra el camino
			std::cout << v.getData() << " ";
			caminoMinimo(grafo,recorridos, v, u);
			std::cout << u.getData() << std::endl;
			getchar();
        	break;

        	case 3:
        	algoritmo_floyd(grafo,distancias,recorridos);

		}
	}
}