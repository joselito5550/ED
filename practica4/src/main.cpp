/*!
	\file main.cpp
	\brief Funcion Main del programa
	\author Jose Manuel Marquez Matarin
*/
#include "../includes/librerias.hpp"
#include <iostream>

 /*! 
    \brief Funcion que muestra el menu por pantalla
    \return int opcion elegida
    \param pasado bool
 */	
int menu(bool pasado){
  int opcion;
    BORRAR;
    LUGAR(5,10);
    std::cout<<"Menú donantes";
    LUGAR(6,10);
    std::cout<<"1. Cargar un grafo desde un fichero";

    LUGAR(7,10);
    std::cout<<"2. Aplicar algoritmo de FLOYD";
    LUGAR(8,10);
    std::cout<<"3. Mostrar el grafo";

    if(pasado){
    LUGAR(9,10);
    std::cout<<"4. Vertice con la menor suma de distancias a los demas vertices";

    LUGAR(10,10);
    std::cout<<"5. Suma de distancias cuando cada vértice es usado como origen";
    LUGAR(11,10);
    std::cout<<"6. Buscar camino minimo entre dos ciudades";
    LUGAR(12,10);
    std::cout<<"7. Salir";
	}
    std::cout<<"\n";
    std::cin>>opcion;
  return opcion;
}

using namespace ed;

 /*! 
    \brief Funcion principal del programa     
 */	
int main(){
	Grafo *grafo;
	Vertice v,u;
	double **distancias = NULL;
	int **recorridos = NULL;
	std::string file_name;
	int opc=0;
	std::string name_origen, name_destino;
	int suma;
	bool pasado = false;
	while(opc != 7){
		opc = menu(pasado);
		switch(opc){
			case 1:
			BORRAR;
			LUGAR(5,10);
			std::cout<<"1. Grafo peninsula";
			LUGAR(6,10);
			std::cout<<"2. Grafo andalucia\n";
			std::cin>>opc;
			if(opc == 1){
				file_name = "grafo_peninsula.txt";
			}
			else if(opc == 2){
				file_name = "grafo_andalucia.txt";
			}
			grafo = cargarFichero(file_name);
			std::cout<<"Todo ok";
			break;

        	case 2:
        	algoritmo_floyd(grafo,distancias,recorridos);
        	pasado = true;
        	break;

        	case 3:
        	mostrarGrafo(grafo);
        	getchar();
        	getchar();
        	break;

        	case 4:
        	if(pasado)
        	VerticeMenorSuma(grafo, distancias);
        	getchar();
        	getchar();
        	break;

        	case 5:
        	if(pasado){
        	for(int i = 0; i<grafo->getNumVertices();i++){
        		grafo->searchVertexLabel(i);
				v = grafo->currVertex();
				suma = SumaDistancias(grafo,distancias, v);
				std::cout<<"La suma para el vertice "<<v.getData()<<" es de "<<suma<<std::endl;
        	}
        	getchar();
        	getchar();
        	}
        	break;
        	
        	case 6:
        	if(pasado){
			std::cout<<"Introduce el nombre de la ciudad de origen:";
			getchar();
        	getline(std::cin,name_origen);
        	std::cout<<"Introduce el nombre de la ciudad de destino:";
        	
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
			}
        	break;
		}
	}
}
