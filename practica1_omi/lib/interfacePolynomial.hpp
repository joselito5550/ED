/*!
   \file interfacePolynomial.hpp
   \brief Interface of the Polynomial where some methods are implemented.
   \author Omar Sotillo Franco
 */
#ifndef __INTERFACEPOLYNOMIAL_HPP_
#define __INTERFACEPOLYNOMIAL_HPP_

#include "../include/libraries.hpp"
#include "monomial.hpp"

/*!
   \brief Namespace for the ED course.
 */
namespace ed {
/*!
   \brief Class interface for a polynomial.
 */
class InterfacePolynomial {
public:

  //! \name Observers

  /*!
     \brief Get the vector of monomials of a polynomial.
     \return Vector of monomials
     \pre There must exists the object.
     \post We get the vector of monomials in a stream.
   */
  virtual std::vector<Monomial>getVector() const = 0;

  /*!
     \brief Get the degree of a polynomial.
     \return Integer degree.
     \pre There must exists the object.
     \post We get the degree in a stream.
   */
  virtual int                  getDegree() const
    = 0;

  /*!
     \brief Get the number of monomials of a polynomial.
     \return Integer number of monomials in the polynomial.
     \pre There must exists the object.
     \post We get the number of monomials in a stream.
   */
  virtual int getNumberOfMonomials() const
    = 0;

  //! \name Sets

  /*!
     \brief Set the vector of monomials of a polynomial.
     \return None.
     \param  A reference to a vector.
     \pre There must exists the object.
     \post We set the vector of monomials in a stream.
   */
  virtual void setVector(const std::vector<Monomial>& vector)
    = 0;

  /*!
     \brief Set the degree of a polynomial.
     \return None.
     \pre There must exists the object.
     \param A reference to a integer degree.
     \post We set the degree in a stream.
   */
  virtual void setDegree(const int& degree)
    = 0;

  /*!
     \brief Set the number of monomials of a polynomial.
     \return None.
     \param a reference to a integer number of monomials.
     \pre There must exists the object.
     \post We set the number of monomials in a stream.
   */
  virtual void setNumberOfMonomials(
    const int& number_of_monomials) = 0;

  //! \name Other fuctions.

  /*!
     \brief Fuction to see if the polynomial is empty.
     \return A TRUE if is Empty or FALSE if not.
     \pre None.
     \post We get a boolean.
   */
  virtual bool isEmpty()
    = 0;
};
} // namespace ed
#endif // ifndef __INTERFACEMONOMIAL_HPP_
