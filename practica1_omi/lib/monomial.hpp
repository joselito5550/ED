/*!
   \file monomial.hpp
   \brief Monomial class where some methods are implemented.
   \author Omar Sotillo Franco
 */
#ifndef __MONOMIAL_HPP_
#define __MONOMIAL_HPP_

#include "../include/libraries.hpp"
#include "interfaceMonomial.hpp"

using namespace ed;

/*!
   \brief Class of a monomial.
   \brief Some methods of the class monomial are implemented here.
   \brief Other are done in the monomial.cpp
 */
class Monomial : public InterfaceMonomial {
private:

  int degree_;
  double coefficient_;

public:

  //! \name Constructors.

  /*!
     \brief When a new Monomial is set a constructor is init.
     \pre An empty monomial instance.
     \post We set the values to 0.
   */
  inline Monomial() {
    this->setDegree(0);
    this->setCoefficient(0);
  }

  /*!
     \brief When a new Monomial is set a constructor is init.
     \param A reference to a double coefficient.
     \param A reference to a degree coefficient.
     \pre An empty monomial instance.
     \post We set the values to the .
   */
  inline Monomial(const double& coefficient,
                  const int   & degree) {
    this->setDegree(degree);
    this->setCoefficient(coefficient);
  }

  /*!
     \brief When a new Monomial is set a constructor is init.
     \param A monomial reference.
     \pre An empty monomial instance.
     \post We set the values to another monomial.
   */
  inline Monomial(const Monomial& monomial_) {
    this->setDegree(monomial_.getDegree());
    this->setCoefficient(monomial_.getCoefficient());
  }

  //! \name Observers

  /*!
     \brief Get the degree of a monomial.
     \return We get a integer degree.
     \pre There must exists the object.
     \post We get the degree of the monomial in a stream.
   */
  inline int getDegree() const {
    return this->degree_;
  }

  /*!
     \brief Fuction to get the coefficient
     \return A double coefficient.
     \pre There must be a object
     \post We get a Degree
   */
  inline double getCoefficient() const {
    return this->coefficient_;
  }

  //! \name Sets.

  /*!
     \brief Fuction to set the degree of the monomial
     \pre None
     \param a reference to a integer degree.
     \param Reference to a degree integer.
     \post New integer is set
   */
  inline void setDegree(const int& degree) {
    this->degree_ = degree;
  }

  /*!
     \brief Fuction to set the coefficient
     \param Reference to a coefficient integer.
     \param Reference to double coefficient.
     \post New integer coefficient is set
     \pre None
   */
  inline void setCoefficient(const double& coefficient) {
    this->coefficient_ = coefficient;
  }

  //! \name Interaction with the user.

  /*!
     \brief Function to read a monomial
     \pre A monomial is created.
     \return A monomial is set.
     \post A monomial is set
   */
  void   readMonomial();

  /*!
     \brief Function to print a monomial
     \pre A monomial is created.
     \post A monomial is printed.
   */
  void   printMonomial();

  /*!
     \brief Function to calculate a monomial in a certain point.
     \pre A monomial is created.
     \return A double with the value of the operation.
     \param The value of the x.
   */
  double calculateMonomial(double x);

  //! \name Operators.

  /*!
     \brief Overload of the operator =.
     \return A new monomial.
     \pre A monomial is created.
     \param We get another monomial
     \return A double with the value of the operation.
     \post The monomial is set with the new value.
   */
  Monomial& operator=(const Monomial& monomial1_);

  /*!
     \brief Overload of the operator *.
     \return A new monomial.
     \pre A monomial is created.
     \param We get another monomial
     \return A double with the value of the operation.
     \post The monomial is set with the operation of multiplication of
        monomials.
   */
  Monomial& operator*(const Monomial& monomial_);

  /*!
     \brief Overload of the operator +.
     \return A new monomial.
     \pre A monomial is created.
     \param Another monomial
     \return A double with the value of the operation.
     \post The monomial is set with the operation of addiction of monomials.
   */
  Monomial& operator+(const Monomial& monomial_);

  //! \name Stream interaction.

  /*!
     \brief Overload of the operator >>.
     \param We get the stream and the monomial.
     \pre There must be a monomial created.
     \post We Introduce the values of the monomial.
   */
  friend std::istream& operator>>(std::istream& stream,
                                  Monomial    & m);

  /*!
     \brief Overload of the operator <<.
     \param We get the stream and the monomial.
     \pre There must be a monomial created.
     \post We print the values of a monomial
   */
  friend std::ostream& operator<<(std::ostream  & stream,
                                  Monomial const& m);
};

#endif // ifndef __INTERFACEMONOMIAL_HPP_
