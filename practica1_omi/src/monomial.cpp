/*!
   \file monomial.cpp
   \brief Implementing not inline functions of the monomial.hpp.
   \author Omar Sotillo Franco
 */
#include "../include/all.hpp"

void Monomial::readMonomial() {
  int degree;
  double coefficient;

  std::cout << HEADER << "Introduce the " << OKGREEN << "coefficient" <<
  HEADER << " of the monomial: " << ENDC;
  std::cin >> coefficient;
  std::cout << HEADER << "Introduce the " << OKGREEN << "degree" << HEADER <<
  " of the monomial: " << ENDC;
  std::cin >> degree;

  this->setDegree(degree);
  this->setCoefficient(coefficient);
}

void Monomial::printMonomial() {
  if (this->getDegree() == 0) {
    std::cout << WARNING << "+" << this->getCoefficient() << ENDC;
  }
  else if (this->getCoefficient() > 0) {
    std::cout << WARNING << "+" << HEADER << this->getCoefficient() << "x^" <<
    this->getDegree() << ENDC;
  }
  else {
    std::cout << WARNING << this->getCoefficient() << FAIL << "x^" << OKBLUE <<
    this->getDegree() << ENDC;
  }
}

double Monomial::calculateMonomial(double x) {
  return this->getCoefficient() * (pow(x, this->getDegree()));
}

Monomial& Monomial::operator=(const Monomial& monomial1_) {
  this->degree_      = monomial1_.getDegree();
  this->coefficient_ = monomial1_.getCoefficient();
  return *this;
}

Monomial& Monomial::operator*(const Monomial& monomial_) {
  this->coefficient_ *= monomial_.getCoefficient();
  this->degree_      += monomial_.getDegree();
  return *this;
}

Monomial& Monomial::operator+(const Monomial& monomial_) {
  if (this->degree_ == monomial_.getDegree()) {
    this->coefficient_ += monomial_.getCoefficient();
  } else {
    std::cout << FAIL << "Must be the same degree!!" << std::endl;
  }
  return *this;
}

std::istream& operator>>(std::istream& stream,
                         Monomial    & m) {
  std::cout << "Introduce values for  ( coefficient, degree) : ";
  stream >> m.coefficient_ >> m.degree_;
  stream.ignore();
  return stream;
}

std::ostream& operator<<(std::ostream  & stream,
                         Monomial const& m) {
  if (m.coefficient_ >= 0) {
    stream << WARNING << "+" << m.coefficient_ << FAIL << "x^" << OKBLUE <<
    m.degree_ << ENDC;
  } else {
    stream << WARNING << m.coefficient_ << FAIL << "x^" << OKBLUE <<
    m.degree_ << ENDC;
  }
  return stream;
}
