/*!
  \file Grafo.hpp
  \brief Clase Grafo
  \author Jose Manuel Marquez Matarin
*/
#ifndef __GRAFO__
#define __GRAFO__
#include "librerias.hpp"

/**Valor de INFINITO.*/  
#define INFINITO 999999
#include "Vertice.hpp"

/*!
    \brief Espacio de nombres ed
*/
namespace ed{
  /**Clase grafo.*/
    class Grafo{
      //! \name Atributos privados de la clase Grafo
      private:
            /*! Vector donde se almacenan los vertices*/
        std::vector<Vertice> _v;

            /*! Matriz de adyacencia*/
        double **_matriz;

            /*! Booleano para saber si es dirigido o no*/
        bool _dirigido;
        
            /*! Cursor para los vertices*/
        int  _currVertices;

            /*! Numero de vertices*/
        int _numVertices;

            /*! Numero de lados*/
        int _numLados;        

            /*! Tamaño del grafo*/
        int _tam; 
        //! \name Funciones publicas de la Clase Monticulo
      public: 
//! \name Constructor
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
      
      //! \name Observadores
      //Observadores
  /*!
    \brief Devolver el valor de _numVertices
    \return Valor de _numVertices
  */      
      const int getNumVertices(){
          return _numVertices;
      }
  /*!
    \brief Devolver el valor de _numLados
    \return Valor de _numLados
  */ 
      const int getNumLados(){
          return _numLados;
      }
  /*!
    \brief Devolver el valor de _dirigido
    \return Valor de _dirigido
  */       
      bool isDirected(){
          return _dirigido;
      }
      
  /*!
    \brief Saber si esta vacio el grafo
    \return True si esta vacio, false si no lo esta
  */ 
      bool isEmpty(){
          return getNumVertices()==0;
      }
      //DUDA!!!
      //Lo suyo es que devuelva un valor double (El valor numerico que corresponda)
      //Porque al aplicar los algoritmos de floyd nos es útil
  /*!
    \brief Devolver el valor de la matriz para esos dos vertices
    \return Valor de la matriz para esos dos vertices
  */ 
      double adjacent(Vertice &v, Vertice &u){
          return _matriz[v.getLabel()][u.getLabel()];
      }
      
  /*!
    \brief Devuelve el vertice apuntado por el cursor
    \return Vertice
  */             
      Vertice currVertex(){
        return _v[_currVertices];
      }

    //! \name Modificadores
  /*!
    \brief Añade un vertice al grafo
    \param v Vertice
  */       
      void addVertex(Vertice &v){
          _v.push_back(v);
          _numVertices++;
      }
      
      //Hay que pasarle el peso para añadirlo a la matriz
  /*!
    \brief Añade un lado al grafo
    \param v Vertice
    \param u Vertice
    \param peso double
  */             
      void addEdge(Vertice &v, Vertice &u, double peso){
          _matriz[v.getLabel()][u.getLabel()] = peso;
          if(!_dirigido) _matriz[u.getLabel()][v.getLabel()] = _matriz[v.getLabel()][u.getLabel()];
      }

      //Buscamos el vertice v, si lo encontramos ponemos el cursor sobre éste
  /*!
    \brief Posiciona el cursor sobre el vertice con el valor data
    \param data std::string
  */       
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

  /*!
    \brief Posiciona el cursor sobre el Vertice con la etiqueta label
    \param label int
  */       
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