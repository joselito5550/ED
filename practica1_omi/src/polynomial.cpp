/*!
   \file polynomial.cpp
   \brief Polynomial implementation of the fuctions wich are not inline.
   \author Omar Sotillo Franco.
 */

#ifndef __POLYNOMIAL_CPP_
#define __POLYNOMIAL_CPP_
#include "../include/all.hpp"

void Polynomial::readPolynomial()  {
  int number, i, coefficient;
  Monomial aux_monomial;

  vector_.clear();
  std::cout << WARNING << "Introduce the max degree of the polynomial:" << ENDC;
  std::cin >> number;
  this->setDegree(number);

  for (i = 0; i <= this->getDegree(); i++) {
    std::cout << WARNING << i << "º degree:" << ENDC << std::endl;
    std::cout << HEADER << "Introduce the " << OKGREEN << "coefficient" <<
    HEADER << " of the monomial: " << ENDC;
    std::cin >> coefficient;
    aux_monomial.setDegree(i);
    aux_monomial.setCoefficient(coefficient);
    vector_.push_back(aux_monomial);
  }
  this->setNumberOfMonomials(i);
}

void Polynomial::printPolynomial() {
  int i;

  if (this->isEmpty()) {
    std::cout << FAIL << "No polynomial is created" << ENDC << std::endl;
  }
  else {
    std::cout << OKGREEN << "The polynomial is:" << ENDC << std::endl;

    for (i = this->getDegree(); i >= 0; i--) {
      vector_[i].printMonomial();
    } std::cout << std::endl;
  }
}

void Polynomial::orderPolynomial() {
  std::vector<Monomial> v;
  Monomial aux1, aux2, aux3;
  Monomial aux(0, 0);

  for (size_t i = 0; i <= this->getDegree(); i++) {
    aux.setDegree(i);
    v.push_back(aux);
  }

  for (size_t i = 0; i < this->getNumberOfMonomials(); i++) {
    aux1                            = vector_[i];
    aux2                            = v[vector_.at(i).getDegree()];
    aux3                            = (aux1 + aux2);
    v.at(vector_.at(i).getDegree()) = aux3;
  }

  vector_.erase(vector_.begin(), vector_.end());
  this->vector_.clear();
  this->vector_.resize(this->getDegree() + 1);
  this->vector_ = v;
}

int Polynomial::calculatePolynomial(double x) {
  int result = 0, i;

  for (i = 0; i < this->getNumberOfMonomials(); i++) {
    result += this->vector_.at(i).calculateMonomial(x);
  }
  return result;
}

Polynomial& Polynomial::operator=(const Polynomial& polynomial) {
  this->degree_ = polynomial.getDegree();
  this->vector_.clear();
  this->vector_              = polynomial.getVector();
  this->number_of_monomials_ = polynomial.getNumberOfMonomials();
  return *this;
}

Polynomial& Polynomial::operator+(const Polynomial& polynomial) {
  for (size_t i = 0; i < polynomial.getNumberOfMonomials(); i++) {
    this->vector_.push_back(polynomial.getVector()[i]);
  }
  this->number_of_monomials_ += polynomial.getNumberOfMonomials();
  return *this;
}

Polynomial& Polynomial::operator*(const Polynomial& polynomial) {
  int i, j;
  Monomial aux, aux1, aux2;

  std::vector<Monomial> v;
  std::vector<Monomial> vaux1 = this->vector_;
  std::vector<Monomial> vaux2 = polynomial.getVector();

  for (i = 0; i < vaux1.size(); i++) {
    for (j = 0; j < vaux2.size(); j++) {
      aux1 = vaux1[i];
      aux2 = vaux2[j];
      v.push_back(aux1 * aux2);
    }
  }
  this->vector_              = v;
  this->number_of_monomials_ = vaux1.size() * vaux2.size();
  this->degree_              = this->degree_ + polynomial.getDegree();
  return *this;
}

std::ostream& operator<<(std::ostream    & stream,
                         Polynomial const& p) {
  int i;

  std::cout << OKGREEN << "The polynomial is:" << ENDC << std::endl;

  for (i = p.getDegree(); i >= 0; i--) {
    stream <<  WARNING << "+" << HEADER << p.getVector()[i].getCoefficient() <<
    "x^" <<
    p.getVector()[i].getDegree() << ENDC;
  } stream << std::endl;

  return stream;
}

#endif // ifndef __polynomial_CPP_
