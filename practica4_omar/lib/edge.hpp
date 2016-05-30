/*!
   \file edge.hpp
   \brief Edge of a graph
   \author Omar Sotillo
   \date 30/05/2016
 */
#ifndef __EDGE_HPP__
#define __EDGE_HPP__

#include "vertex.hpp"
#include "../include/libraries.hpp"


namespace edi {
  /*!
     \brief Edge class
   */
class Edge {
private:

  float  _data;   /*!< value of a edge */
  Vertex _first;  /*!< First vertex  */
  Vertex _second; /*!< last vertex */

public:

  /*!
     \brief Get of data
     \return _data of the edge
   */
  const float& getData() const
  {
    return _data;
  }

  /*!
     \brief Get of fisrt vertex
     \return start vertex
   */
  const Vertex& first() const
  {
    return _first;
  }

  /*!
     \brief Get of last vertex
     \return last vertex
   */
  const Vertex& second() const
  {
    return _second;
  }

  /*!
     \brief Return if it has vertex
     \return boolean
   */
  bool has(const Vertex& u) const
  {
    return u == first() or u == second();
  }

  /*!
     \brief Return the other vertex
     \param u vertex
     \return vertex
   */
  const Vertex& other(const Vertex& u) const
  {
    assert(has(u));

    if (u == first()) return second();

    return first();
  }

  /*!
     \brief Set of data
     \param data Value
   */
  void setData(const float& data)
  {
    _data = data;
  }

  /*!
     \brief Set of data
     \param first vertex
   */
  void setFirst(const Vertex& first)
  {
    _first = first;
  }

  /*!
     \brief Set of second vertex
     \param second vertex
   */
  void setSecond(const Vertex& second)
  {
    _second = second;
  }

  /*!
     \brief Operator comparison
     \return boolean
   */
  bool operator==(const Edge& e) const
  {
    return e.first() == first() and e. second() == second();
  }
};
} // namespace ed

#endif // ifndef __EDGE_HPP__
