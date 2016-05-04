#include "librerias.hpp"

namespace ed{
    class Grafo{
      private:
        std::vector<Vertice> _v;
        int **_matriz;
        bool _dirigido;
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
      
      bool adjacent(Vertice &v, Vertice &u){
          int labelv = v.getLabel();
          int labelu = u.getLabel();
          
          if(_matriz[u][v]==1 || _matriz[v][u]==1){
              return true;
          }
          else return false;
      }
     
    };
}