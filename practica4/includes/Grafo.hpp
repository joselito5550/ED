#include "librerias.hpp"

namespace ed{
    class Grafo{
      private:
        std::vector<Vertice> _v;
        int **_matriz;
        bool _dirigido;
        
        Vertice  *_currVertices;
        int _currLados;
        int _numVertices;
        int _numLados;         
      public: 
      
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
      //Lo suyo es que devuelva un valor float (El valor numerico que corresponda)
      //Porque al aplicar los algoritmos de floyd nos es útil
      int adjacent(Vertice &v, Vertice &u){
          int labelv = v.getLabel();
          int labelu = u.getLabel();
          //Aqui habra que controlar si es dirigido o no? 
          if(_matriz[u][v]!=0 || _matriz[v][u]==!=0){
              return _matriz[u][v];
          }
          else return -1;
      }
      
      void addVertex(Vertice &v){
          _v.push_back(v);
          _numVertices++;
      }
      
      //Hay que pasarle el peso para añadirlo a la matriz
      void addEdge(Vertice &v, Vertice &u, int peso){
          _matriz[v.getLabel()][u.getLabel()] = peso;
          _matriz[u.getLabel()][v.getLabel()] = _matriz[v.getLabel()][u.getLabel()];
      }
      
      //Buscamos el vertice v, si lo encontramos ponemos el cursor sobre éste
      void searchVertex(Vertice &v){
          bool encontrado = false;
          int i = 0;
          while(!encontrado && i<_numVertices){
              if(_v[i] == v){
                  encontrado = true;
              }
              else i++;
          }
          if(encontrado){
              _currVertices = _v[i];
          }
      }
     
    };
}