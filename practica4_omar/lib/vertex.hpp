/*!
   \file vertex.hpp
   \brief vertex class of the app
   \author Omar
   \date 30/05/2016
 */
#ifndef __VERTEX_HPP__
#define __VERTEX_HPP__

#include "../include/libraries.hpp"

namespace edi {
/*!
   \brief Class vertex

 */
class Vertex {
private:

  std::string _data; /*!< value */
  int _label;        /*!< number */

public:

  /*!
     \brief Get data of the vertex
     \return Return value data
   */
  const std::string& getData() const
  {
    return this->_data;
  }

  /*!
     \brief Get label of the vertex
     \return Return value data
   */
  const int& getLabel() const
  {
    return this->_label;
  }

  /*!
     \brief Set data of the vertex
     \param data value
   */
  void setData(const std::string& data)
  {
    this->_data = data;
  }

  /*!
     \brief Set label of the vertex
     \param label value
   */
  void setLabel(const int& label)
  {
    _label = label;
  }

  /*!
     \brief Operator of comparison
     \return boolean
   */
  bool operator==(const Vertex& v) const
  {
    return v.getData() == getData();
  }

  /*!
     \brief Operator of distinction
     \return boolean
   */
  bool operator!=(const Vertex& v) const
  {
    return v.getData() != getData();
  }
};
}

#endif // ifndef __VERTEX_HPP__
