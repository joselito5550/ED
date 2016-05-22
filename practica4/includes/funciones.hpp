#ifndef __FUNCIONES__
#define __FUNCIONES__


#include "librerias.hpp"
#include "Grafo.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <ctype.h>

namespace ed{
	
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
	if(dirigido == 0) grafo = new Grafo(num_vertices,false);
	else grafo = new Grafo(num_vertices, true);


	//Añadimos los vertices
	for(int i=0;i<num_vertices;i++){
		v.setLabel(i);
		f >> name;
		v.setData(name);
		grafo->addVertex(v);
	}

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

void caminoMinimo(Grafo *grafo, int **matriz_recorridos, Vertice &origen, Vertice &destino){
	Vertice v;
	int label;

	if(matriz_recorridos[origen.getLabel()][destino.getLabel()] != -1){
		label = matriz_recorridos[origen.getLabel()][destino.getLabel()];
		grafo->searchVertexLabel(label);
		v = grafo->currVertex();
		caminoMinimo(grafo, matriz_recorridos, origen,v);
		std::cout<<v.getData()<<" ";
		caminoMinimo(grafo, matriz_recorridos,v,destino);
	}

}


void algoritmo_floyd(Grafo *&grafo, double **&matriz_distancias, int **&matriz_recorridos){

	Vertice v,u;

	matriz_distancias = new double*[grafo->getNumVertices()];
	matriz_recorridos = new int*[grafo->getNumVertices()];


	for(int i = 0; i<grafo->getNumVertices(); i++){
		matriz_distancias[i] = new double [grafo->getNumVertices()];
		matriz_recorridos[i] = new int [grafo->getNumVertices()];


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
