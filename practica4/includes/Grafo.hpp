#ifndef __GRAFO__
#define __GRAFO__
#include "librerias.hpp"
#define INFINITO 999999
#include "Vertice.hpp"


namespace ed{
    class Grafo{
      private:
        std::vector<Vertice> _v;
        double **_matriz;
        bool _dirigido;
        
        int  _currVertices;
        int _numVertices;
        int _numLados;        
        int _tam; 
      public: 

      Grafo(int tam = 0, bool dirigido = true){
        if(tam < 0)
          tam = 0;
        _matriz = new double *[tam];          
        for(int i = 0; i < tam; i++){         
          _matriz[i] = new double [tam];
          for(int j = 0; j < tam; j++){
            _matriz[i][j] = INFINITO;
          }
        }

        _numVertices = 0; 
        _numLados = 0;
        _tam = tam;
        _currVertices = 0;
        _dirigido = dirigido;
      }
      
      //Observadores
      const int getNumVertices(){
          return _numVertices;
      }
      
      const int getNumLados(){
          return _numLados;
      }
      
      bool isDirected(){
          return _dirigido;
      }
      
      
      bool isEmpty(){
          return getNumVertices()==0;
      }
      //DUDA!!!
      //Lo suyo es que devuelva un valor double (El valor numerico que corresponda)
      //Porque al aplicar los algoritmos de floyd nos es útil
      double adjacent(Vertice &v, Vertice &u){
          return _matriz[v.getLabel()][u.getLabel()];
      }
      
      void addVertex(Vertice &v){
          _v.push_back(v);
          _numVertices++;
      }
      
      //Hay que pasarle el peso para añadirlo a la matriz
      void addEdge(Vertice &v, Vertice &u, double peso){
          _matriz[v.getLabel()][u.getLabel()] = peso;
          if(!_dirigido) _matriz[u.getLabel()][v.getLabel()] = _matriz[v.getLabel()][u.getLabel()];
      }
      
      Vertice currVertex(){
        return _v[_currVertices];
      }

      //Buscamos el vertice v, si lo encontramos ponemos el cursor sobre éste
      void searchVertex(std::string &data){
          bool encontrado = false;
          int i = 0;
          while(!encontrado && i<_numVertices){
              if(_v[i].getData() == data){
                  encontrado = true;
              }
              else i++;
          }
          if(encontrado){
              _currVertices = i;
          }
      }

      void searchVertexLabel(int &label){
          bool encontrado = false;
          int i = 0;
          while(!encontrado && i<_numVertices){
              if(_v[i].getLabel() == label){
                  encontrado = true;
                  _currVertices = i;
              }
              else i++;
          }
      }

  

     
    };
}
#endif