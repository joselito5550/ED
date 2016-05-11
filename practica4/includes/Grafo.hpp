#include "librerias.hpp"

namespace ed{
    class Grafo{
      private:
        std::vector<Vertice> _v;
        int **_matriz;
        bool _dirigido;
        
        int _currVertices;
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
      }
     
    };
}