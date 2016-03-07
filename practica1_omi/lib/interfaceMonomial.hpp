/*!
   \file interfaceMonomial.hpp
   \brief Interface of the Monomial where some methods are implemented.
   \author Omar Sotillo Franco
 */
#ifndef __INTERFACEMONOMIAL_HPP_
#define __INTERFACEMONOMIAL_HPP_

#include "../include/libraries.hpp"

/*!
   \brief Namespace for the ED course.
 */
namespace ed {
/*!
   \brief Class interface of a monomial.
   \brief Some methods are here implemented
 */
class InterfaceMonomial {
public:

  //! \name Observers

  /*!
     \brief Get the degree of a monomial.
     \return We get a integer degree.
     \pre There must exists the object.
     \post We get the degree of the monomial in a stream.
   */
  virtual int    getDegree() const = 0;

  /*!
     \brief Fuction to get the coefficient
     \return A double coefficient.
     \pre There must be a object
     \post We get a Degree
   */
  virtual double getCoefficient() const = 0;

  //! \name Sets

  /*!
     \brief Fuction to set the degree of the monomial
     \pre None
     \param a reference to a integer degree.
     \param Reference to a degree integer.
     \post New integer is set
   */
  virtual void setDegree(const int& degree) = 0;

  /*!
     \brief Fuction to set the coefficient
     \param Reference to a coefficient integer.
     \param Reference to double coefficient.
     \post New integer coefficient is set
     \pre None
   */
  virtual void setCoefficient(const double& coefficient) = 0;
};
} // namespace ed
#endif // ifndef __INTERFACEMONOMIAL_HPP_
