/*!
	\file funciones.hpp
	\brief Fichero de funciones que utilizan el grafo
	\author Jose Manuel Marquez Matarin
*/
#ifndef __FUNCIONES__
#define __FUNCIONES__


#include "librerias.hpp"
#include "Grafo.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>
/*!
    \brief Espacio de nombres ed
*/
namespace ed{
	
 /*! 
    \brief Funcion para cargar el grafo desde un fichero pasado por parametro
    \param file_name std::string
	\return Grafo * puntero al grafo creado      
 */	
Grafo * cargarFichero(std::string file_name){
	std::ifstream f(file_name.c_str());
	int num_vertices;
	int dirigido;
	Vertice v, u;
	std::string name , name2;
	double distancia;
	f >> num_vertices;
	f >> dirigido;
	Grafo *grafo;
	//Creamos el grafo
	if(dirigido == 0) grafo = new Grafo(num_vertices,false);
	else grafo = new Grafo(num_vertices, true);


	//Añadimos los vertices
	for(int i=0;i<num_vertices;i++){
		v.setLabel(i);
		f >> name;
		v.setData(name);
		grafo->addVertex(v);
	}

	//Vamos leyendo del fichero los lados de los vertices y los añadimos
	while(f >> name >> name2 >> distancia){
		grafo->searchVertex(name);
		v = grafo->currVertex();

		grafo->searchVertex(name2);
		u = grafo->currVertex();

		grafo->addEdge(v,u,distancia);
	}
	f.close();
	return grafo;
}

 /*! 
    \brief Funcion que muestra el grafo por pantalla
    \param grafo Grafo      
 */	
void mostrarGrafo(Grafo *grafo){

	//Mostramos los vertices junto a sus respectivas etiquetas
	std::cout<<"Los vertices son: "<<std::endl;
	for(int i = 0; i<grafo->getNumVertices(); i++){
		grafo->searchVertexLabel(i);
		std::cout<<grafo->currVertex().getData()<<" con etiqueta "<<i<<std::endl;
	}

	//Mostramos los lados
	Vertice v, u;
	std::cout<<"Los lados son: "<<std::endl;
	for(int i = 0; i<grafo->getNumVertices(); i++){
		for(int j = 0; j<grafo->getNumVertices(); j++){
			grafo->searchVertexLabel(i);
			v = grafo->currVertex();

			grafo->searchVertexLabel(j);
			u = grafo->currVertex();

			if(grafo->adjacent(v,u) != INFINITO && i!=j){
				std::cout<<"De "<<v.getData()<<" a "<<u.getData()<<" hay "<<grafo->adjacent(v,u)<<" km"<<std::endl;
			}
		}
	}
}

 /*! 
    \brief Funcion que calcula el camino minimo entre dos vertices
    \param grafo Grafo
    \param matriz_recorridos int
    \param origen Vertice
    \param destino Vertice 
    \post Se debera mostrar por pantalla el camino minimo entre los dos vertices pasados   
 */	
void caminoMinimo(Grafo *grafo, int **matriz_recorridos, Vertice &origen, Vertice &destino){
	Vertice v;
	int label;
	//Si es == -1 entonces es que estan unidos directamente por lo que no habría que entrar
	if(matriz_recorridos[origen.getLabel()][destino.getLabel()] != -1){
		//En label guardamso el que sería nodo intermedio
		label = matriz_recorridos[origen.getLabel()][destino.getLabel()];
		grafo->searchVertexLabel(label);
		v = grafo->currVertex();
		caminoMinimo(grafo, matriz_recorridos, origen,v);
		std::cout<<v.getData()<<" ";
		caminoMinimo(grafo, matriz_recorridos,v,destino);
	}

}



 /*! 
    \brief Funcion que muestra la suma de distancias a cada vertice tomando como origen el vertice pasado por parametro
    \param grafo Grafo
    \param matriz_distancias double
    \param v Vertice
	\return int suma de distancias      
 */	
int SumaDistancias(Grafo *grafo, double **matriz_distancias, Vertice v){
	
	int suma = 0;
	//Hacemos un recorrido desde el vertice v a todos sumando las distancias
	for(int i = 0;i<grafo->getNumVertices();i++){
		suma += matriz_distancias[v.getLabel()][i];
	}
	return suma;
}

 /*! 
    \brief Funcion que muestra el vertice cuya suma de distancias es menor
    \param grafo Grafo
    \param matriz_distancias double 
 */	
void VerticeMenorSuma(Grafo *grafo, double **matriz_distancias){
	double menor_distancia = INFINITO;
	int vertice;
	double distancia = 0;
	for(int i=0;i<grafo->getNumVertices();i++){
		for(int j = 0;j<grafo->getNumVertices();j++){
			distancia += matriz_distancias[i][j];
		}
		if(distancia < menor_distancia){
			menor_distancia = distancia;
			vertice = i;
		}
		distancia = 0;
	}
	grafo->searchVertexLabel(vertice);
	Vertice v = grafo->currVertex();
	std::cout<<"La menor distancia es: "<<menor_distancia<<std::endl;;
	std::cout<<"El Vertice es: "<<v.getData();
	getchar();
}


 /*! 
    \brief Funcion que aplica el algoritmo de floyd al grafo pasado por parametro
    \param grafo Grafo
    \param matriz_distancias double
    \param matriz_recorridos int
 */	
void algoritmo_floyd(Grafo *&grafo, double **&matriz_distancias, int **&matriz_recorridos){

	Vertice v,u;
	//reservamos la memoria
	matriz_distancias = new double*[grafo->getNumVertices()];
	matriz_recorridos = new int*[grafo->getNumVertices()];


	for(int i = 0; i<grafo->getNumVertices(); i++){
		matriz_distancias[i] = new double [grafo->getNumVertices()];
		matriz_recorridos[i] = new int [grafo->getNumVertices()];

		//rellenamos las matrices
		for(int j = 0; j<grafo->getNumVertices();j++){
			matriz_recorridos[i][j] = -1;
			if(i == j){
				matriz_distancias[i][j] = 0;
			}
			else{
				grafo->searchVertexLabel(i);
				v = grafo->currVertex();
				grafo->searchVertexLabel(j);
				u = grafo->currVertex();
				matriz_distancias[i][j] = grafo->adjacent(v,u);
			}
		}
	}


	//Algoritmo de FLOYD diapositivas
	for(int k=0;k<grafo->getNumVertices();k++){
		for(int i=0;i<grafo->getNumVertices();i++){
			for(int j=0;j<grafo->getNumVertices();j++){
				if((matriz_distancias[i][k]+matriz_distancias[k][j])<matriz_distancias[i][j]){
					matriz_distancias[i][j] = (matriz_distancias[i][k]+matriz_distancias[k][j]);
					matriz_recorridos[i][j] = k;
				}
			}
		}
	}
}




}
#endif
