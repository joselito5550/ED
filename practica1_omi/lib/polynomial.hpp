/*!
   \file polynomial.hpp
   \brief Polynomial and some methods implemented inline.
   \author Omar Sotillo Franco
 */

#ifndef __POLYNOMIAL_HPP_
#define __POLYNOMIAL_HPP_

#include "../include/libraries.hpp"
#include "monomial.hpp"
#include "interfacePolynomial.hpp"

using namespace ed;

/*!
   \brief Class of a Polynomial.
   \brief Some methods of the class polynomial are implemented here.
   \brief Other are done in the polynomial.cpp
 */
class Polynomial : public InterfacePolynomial {
private:

  int number_of_monomials_;
  int degree_;
  std::vector<Monomial> vector_;

public:

  // ! \name Constructors.

  /*!
     \brief When a new Polynomial is set a constructor is init.
     \pre An empty polynomial instance.
     \post We set the values to 0 and vector.
   */
  inline Polynomial() {
    this->vector_.clear();
    this->setDegree(0);
    this->setNumberOfMonomials(0);
  }

  /*!
     \brief When a new Polynomial is set a constructor is init.
     \param A reference to a int degree.
     \param A reference to a int  number of monomials.
     \pre An empty polynomial instance.
     \post We set the values to the polynomial with the ones provided.
   */
  inline Polynomial(const int                & number_of_monomials,
                    const int                & degree,
                    const std::vector<Monomial>vector) {
    this->setVector(vector);
    this->setDegree(degree);
    this->setNumberOfMonomials(number_of_monomials);
  }

  /*!
     \brief When a new Polynomial is set a constructor is init.
     \param A polynomial reference.
     \pre An empty polynomial instance.
     \post We set the values to another polynomial.
   */
  inline Polynomial(const Polynomial& polynomial) {
    this->setVector(polynomial.getVector());
    this->setDegree(polynomial.getDegree());
    this->setNumberOfMonomials(polynomial.getNumberOfMonomials());
  }

  // ! \name Observers

  /*!
     \brief Get the vector of monomials of a polynomial.
     \return Vector of monomials
     \pre There must exists the object.
     \post We get the vector of monomials in a stream.
   */
  inline std::vector<Monomial>getVector() const {
    return vector_;
  }

  /*!
     \brief Get the degree of a polynomial.
     \return Integer degree.
     \pre There must exists the object.
     \post We get the degree in a stream.
   */
  inline int getDegree() const {
    return degree_;
  }

  /*!
     \brief Get the number of monomials of a polynomial.
     \return Integer number of monomials in the polynomial.
     \pre There must exists the object.
     \post We get the number of monomials in a stream.
   */
  inline int getNumberOfMonomials() const {
    return number_of_monomials_;
  }

  // ! \name Sets.

  /*!
     \brief Set the vector of monomials of a polynomial.
     \return None.
     \param  A reference to a vector.
     \pre There must exists the object.
     \post We set the vector of monomials in a stream.
   */
  inline void setVector(const std::vector<Monomial>& vector) {
    vector_.clear();
    vector_ = vector;
  }

  /*!
     \brief Set the degree of a polynomial.
     \return None.
     \pre There must exists the object.
     \param A reference to a integer degree.
     \post We set the degree in a stream.
   */
  inline void setDegree(const int& degree) {
    degree_ = degree;
  }

  /*!
     \brief Set the number of monomials of a polynomial.
     \return None.
     \param a reference to a integer number of monomials.
     \pre There must exists the object.
     \post We set the number of monomials in a stream.
   */
  inline void setNumberOfMonomials(const int& number_of_monomials) {
    number_of_monomials_ = number_of_monomials;
  }

  // ! \name Interaction with the user.

  /*!
     \brief Check wether a polynomial is empty or not.
     \return TRUE if empty FALSO if not.
   */
  inline bool isEmpty() {
    if (vector_.size() == 0) {
      return true;
    } else {
      return false;
    }
  }

  /*!
     \brief Function to read a polynomial
     \pre A Polynomial is created.
     \return A polynomial is set.
     \post A polynomial is set
   */
  void readPolynomial();

  /*!
     \brief Function to print a polynomial
     \pre A polynomial is created.
     \post A polynomial is printed.
   */
  void printPolynomial();

  /*!
     \brief Function to calculate a polynomial in a certain point.
     \pre A polynomial is created.
     \return A double with the value of the operation.
     \param The value of the x.
   */
  int  calculatePolynomial(double x);

  /*!
     \brief Function to order a polynomail which means there are only one
        monomial of each degree.
     \pre A polynomial is created.
     \return An ordered polynomial
   */
  void orderPolynomial();

  // ! \name Operators.

  /*!
     \brief Overload of the operator =.
     \return A new polynomial.
     \pre A polynomial is created.
     \param We get another polynomial
     \return A double with the value of the operation.
     \post The polynomial is set with the new value.
   */
  Polynomial&          operator=(const Polynomial& polynomial);

  /*!
     \brief Overload of the operator +.
     \return A new polynomial.
     \pre A polynomial is created.
     \param Another polynomial
     \return A double with the value of the operation.
     \post The monomial is set with the operation of addiction of polynomials.
   */
  Polynomial&          operator+(const Polynomial& polynomial);

  /*!
     \brief Overload of the operator *.
     \return A new polynomial.
     \pre A polynomial is created.
     \param We get another polynomial
     \return A double with the value of the operation.
     \post The monomial is set with the operation of multiplication of
        polynomials.
   */
  Polynomial&          operator*(const Polynomial& polynomial);

  /*!
     \brief Overload of the operator <<.
     \param We get the stream and the polynomial.
     \pre There must be a polynomial created.
     \post We print the values of a polynomial
   */
  friend std::ostream& operator<<(std::ostream    & stream,
                                  Polynomial const& p);
};
#endif // ifndef __POLYNOMIAL_HPP_
