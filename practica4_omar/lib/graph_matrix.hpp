/*!
   \file graph_matrix.hpp
   \brief Graph class
   \author Omar Sotillo Fracno
 */
#ifndef __GRAPH_MATRIX_HPP__
#define __GRAPH_MATRIX_HPP__

#include "vertex.hpp"
#include "edge.hpp"
#include "../include/libraries.hpp"

namespace edi {
/*!
   \brief GraphMatrix class
 */
class GraphMatrix {
private:

  std::vector<Vertex> _vertexes; /*!< Vector of vertexes */

  float **_weights;              /*!< Adjacency matrix of weights */

  bool _isDirected;              /*!< Is directed */

  Vertex *_currVertex;           /*!< cursor of vertexes */

  Edge *_currEdge;               /*!<  cursor of edges */

  unsigned int _numVertexes;     /*!< number of vertexes */

  unsigned int _numEdges;        /*!< number of edges */

  unsigned int _capacity;        /*!< Capacity of graph (maximum value of
                                    _numVertexes. _capacity >= */

public:

  /*!
     \brief Constructor
     \param capacity capacity of the matrix
     \param isDirected isDirected value
   */
  GraphMatrix(const unsigned int& capacity = 0,
              const bool        & isDirected = true);

  /*!
     \brief get of number of vertexes
     \return integer numberVertexes
   */
  const unsigned int& numVertexes() const;

  /*!
     \brief get of number of Edges
     \return integer numberEdges
   */
  const unsigned int& numEdges() const;

  /*!
     \brief get capacity
     \return integer capacity of the matrix
   */
  const unsigned int& capacity() const;

  /*!
     \brief return if it is empty
     \return boolean
   */
  bool                isEmpty() const;

  /*!
     \brief return if it isDirected
     \return boolean
   */
  bool                isDirected() const;

  /*!
     \brief Return the element of intermediate matrix
     \param u vertex
     \param v vertex
   */
  const float&        adjacent(const Vertex& u,
                               const Vertex& v) const;

  /*!
     \brief hasCurrVertex return if it has a vertex set as current
     \return boolean
   */
  bool          hasCurrVertex() const;

  /*!
     \brief Return the current vertex
     \return boolean
   */
  const Vertex& currVertex() const;

  // Está el cursor de lados posición válida

  /*!
     \brief is in valid position and has Edge
     \return boolean
   */
  bool hasCurrEdge() const;


  /*!
     \brief current edge
     \return Edge
   */
  const Edge currEdge();


  /*!
     \brief make a directed graph
   */
  void makeDirected();

  /*!
     \brief make a non directed graph

   */
  void makeUndirected();

  /*!
     \brief Add a vertex to the graph
     \param data value
   */
  void addVertex(const std::string& data);

  /*!
     \brief add a edge
     \param data value
     \param u first vertex
     \param v last vertex
   */
  void addEdge(const float & data,
               const Vertex& u,
               const Vertex& v);

  /*!
     \brief Search a vertex with its value
     \param data value
   */
  void searchVertex(const std::string& data);

  /*!
     \brief Set cursor to the vertex
     \param u vertex
   */
  void goTo(const Vertex& u);

  /*!
     \brief Set cursor to the vertex
     \param idx label integer
   */
  void goTo(const unsigned int& idx);

  /*!
     \brief Set cursor to a edge with its vertex
     \param u first vertex
     \param v last vertex
   */
  void searchEdge(const Vertex& u,
                  const Vertex& v);

  /*!
     \brief Set cursor to first vertex
   */
  void beginVertex();

  /*!
     \brief Set cursor to next vertex
   */
  void nextVertex();

  /*!
     \brief Set cursor to first vertex
   */
  bool afterEndVertex() const;

  /*!
     \brief Set cursor to first edge leaving u vertex
     \param u vertex
   */
  void beginEdge(const Vertex& u);

  /*!
     \brief Set cursor to next edge
   */
  void nextEdge();

  /*!
     \brief Set cursor to first edge of the last edge
   */
  bool afterEndEdge();
};
} // namespace ed

#endif // ifndef __GRAPH_MATRIX_HPP__
