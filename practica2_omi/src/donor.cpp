/*!
   \file donor.cpp
   \brief Donor methods implemented
   \author Omar Sotillo
 */

#ifndef __DONOR_CPP_
#define __DONOR_CPP_
#include "../include/all.hpp"

// Constructors
// Constructor
Donor::Donor() {
  this->setName("");
  this->setSurname("");
  this->setBloodType("");
  this->setRhFactor(false);
}

// Constructor with params
Donor::Donor(const std::string& name,
             const std::string& surname,
             const std::string& bloodType,
             const bool       & rhFactor) {
  this->setName(name);
  this->setSurname(surname);
  this->setBloodType(bloodType);
  this->setRhFactor(rhFactor);
}

// Constructor of copy.
Donor::Donor(const Donor& copyDonor) {
  this->setName(copyDonor.getName());
  this->setSurname(copyDonor.getSurname());
  this->setBloodType(copyDonor.getBloodType());
  this->setRhFactor(copyDonor.getRhFactor());
}

std::string Donor::getName() const {
  return this->name_; // Returning the value name of the class.
}

std::string Donor::getSurname() const {
  return this->surname_;
}

std::string Donor::getBloodType() const {
  return this->bloodType_;
}

bool Donor::getRhFactor() const {
  return this->rhFactor_;
}

void Donor::setName(const std::string& name)           {
  this->name_ = name;
}

void Donor::setSurname(const std::string& surname)     {
  this->surname_ = surname;
}

bool Donor::setBloodType(const std::string& bloodType) {
  if ((bloodType == "AB") || (bloodType == "0") || (bloodType == "A") ||
      (bloodType == "B")) {
    this->bloodType_ = bloodType;
    return true;
  } else {
    return false;
  }
}

void Donor::setRhFactor(const bool& rhFactor)          {
  this->rhFactor_ = rhFactor;
}

void Donor::readDonor()                            {
  std::string auxString;

  LUGAR(6, 10);

  // Getting the name of the donor.
  std::cout << HEADER << "Introduce the name of the donor: " << ENDC;
  std::getline(std::cin, auxString);

  if (!auxString.empty()) {
    this->setName(auxString);
  }
  auxString.clear();

  LUGAR(7, 10);

  // Getting the surname of the donor.
  std::cout << HEADER << "Introduce the surname of the donor: " << ENDC;
  std::getline(std::cin, auxString);

  if (!auxString.empty()) {
    this->setSurname(auxString);
  }
  auxString.clear();

  LUGAR(8, 10);

  // Getting the bloodType of the donor.
  std::cout << HEADER << "Introduce the blood type of the donor: " << ENDC;
  std::getline(std::cin, auxString);

  if (!auxString.empty()) {
    this->setBloodType(auxString);
  }
  auxString.clear();

  LUGAR(9, 10);

  // Getting the Rh Factor of the Donor.
  std::cout << HEADER <<
  "Introduce 1 if positive or 0 if negative Rh Factor: " <<
  ENDC;
  std::getline(std::cin, auxString);


  if (atoi(auxString.c_str()) == 0) {
    this->setRhFactor(false);
  } else {
    this->setRhFactor(true);
  }
}

// Printing a donor.
void Donor::printDonor()                           {
  std::cout << HEADER << "Donor: " << OKBLUE << this->getName() << " " <<
  this->getSurname() << HEADER << " BloodType: " << OKBLUE <<
  this->getBloodType() << HEADER <<
  " RhFactor: " << OKBLUE <<  this->getRhFactor() << std::endl << ENDC;
}

// We set a new donor
Donor& Donor::operator=(const Donor& copiedDonor)    {
  this->setName(copiedDonor.getName());
  this->setSurname(copiedDonor.getSurname());
  this->setBloodType(copiedDonor.getBloodType());
  this->setRhFactor(copiedDonor.getRhFactor());
  return *this;
}

// Comparing two donors. If the same return true
bool Donor::operator==(const Donor& comparedDonor) {
  if ((this->getName().compare(comparedDonor.getName()) == 0) &&
      (this->getSurname().compare(comparedDonor.getSurname()) == 0))
  {
    return true;
  } else {
    return false;
  }
}

bool Donor::operator<=(const Donor& comparedDonor) {
  std::string auxDonor1 = this->getSurname();
  std::string auxDonor2 = comparedDonor.getSurname();

  if (auxDonor1.compare(auxDonor2) <= 0) {
    return true;
  } else {
    return false;
  }
}

std::istream& operator>>(std::istream& stream, Donor& d) {
  std::cout << "Introduce values for  ( Name, Surname, BloodType, RhFactor) : ";
  stream >> d.name_ >> d.surname_ >> d.bloodType_ >> d.rhFactor_;
  stream.ignore();
  return stream;
}

std::ostream& operator<<(std::ostream& stream,
                         Donor const & d) {
  stream << HEADER << "Donor: " << OKBLUE << d.getName() << " " <<
  d.getSurname() << HEADER << " BloodType: " << OKBLUE << d.getBloodType() <<
  HEADER <<
  " RhFactor: " << OKBLUE <<  d.getRhFactor() << std::endl << ENDC;
  return stream;
}

#endif // ifndef __DONOR_CPP_
