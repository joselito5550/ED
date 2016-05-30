/*!
   \file algorithms.hpp
   \brief algorithms implementation
   \author Omar
   \date 30/05/2016
 */
#ifndef __ALGORITHMS_HPP__
#define __ALGORITHMS_HPP__

#include "graph_matrix.hpp"
#include "vertex.hpp"
#include "../include/libraries.hpp"

/*!
   \brief FloydAlgorithm to find the distance and the intermediate matrix
   \param g matrix
   \param distance Matrix of distances
   \param intermediate matrix of intermediates nodes
 */
void FloydAlgorithm(edi::GraphMatrix& g,
                    float           **distance,
                    int             **intermediate);

/*!
   \brief shortestPath to find the best distance and nodes to be run
   \param g matrix
   \param distance Matrix of distances
   \param intermediate matrix of intermediates nodes
   \param from Start nodes
   \param to end node
 */
void shortestPath(edi::GraphMatrix & g,
                  const float      **distance,
                  const int        **intermediate,
                  const edi::Vertex& from,
                  const edi::Vertex& to);

/*!
   \brief Calculate the total of the distance
   \param g matrix
   \param distance Matrix of distances
   \param v vertex to be calculated
 */
int addDistances(edi::GraphMatrix& g,
                 float           **distance,
                 edi::Vertex       v);

/*!
   \brief Smaller vertex of the lesson
   \param g matrix
   \param distanceM Matrix of distances
 */
void VertexSmaller(edi::GraphMatrix& g,
                   float           **distanceM);
#endif // ifndef __ALGORITHMS_HPP__
