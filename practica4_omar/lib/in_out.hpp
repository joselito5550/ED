/*!
   \file in_out.hpp
   \brief io of the app
 */
#ifndef __IN_OUT_HPP__
#define __IN_OUT_HPP_HPP__

#include "graph_matrix.hpp"
#include "../include/libraries.hpp"

/*!
   \brief Load a graph from a file
   \param g graph matrix
   \param fileGraph path to the file
 */
bool loadGraph(edi::GraphMatrix *& g,
               std::string         fileGraph);

/*!
   \brief Show graph
   \param g GraphMatrix
 */
void showGraph(edi::GraphMatrix& g);

#endif // ifndef __IN_OUT_HPP__
