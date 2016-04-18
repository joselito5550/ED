/*!
   \file donors.cpp
   \brief Donors methods implemented
   \author Omar Sotillo
 */
#ifndef __DONORS_CPP_
#define __DONORS_CPP_
#include "../include/all.hpp"

// COnstructor
Donors::Donors() {
  list_.setNumberOfNodes(0);
}

// Constructor
Donors::Donors(CustomList list) {
  this->setCustomList(list);
}

// Get of custom list
CustomList Donors::getCustomList()                {
  return list_;
}

// Set of CustomList
void Donors::setCustomList(CustomList list) {
  this->list_ = list;
}

// Printing all list
void Donors::printDonors() {
  this->list_.printDonors();
}

// Check if a list is empty
bool Donors::isListEmpty()                  {
  return this->getCustomList().isEmpty();
}

bool Donors::findDonor() {
  return true;
}

// Insert new donor
// This is a interface to the method implemented in CustomList
void Donors::insertNewDonor()               {
  Donor auxDonor;

  std::cin.ignore();
  auxDonor.readDonor();

  // We call the method.
  // The way insert is implemented can be change when want.
  this->list_.insert(auxDonor);
  this->list_.setNumberOfNodes((this->list_.getNumberOfNodes() + 1));
}

// Editing a donor
// This is a interface to the method implemented in CustomList
void Donors::editDonor()               {
  Donor auxDonor;

  std::cin.ignore();
  auxDonor.readDonor();

  if (!this->list_.editDonor(auxDonor)) {
    BORRAR;
    LUGAR(6, 10);
    std::cout << FAIL << "Donor dont exists" << std::endl << ENDC;
    sleep(4);
  }
  else {
    BORRAR;
    LUGAR(6, 10);
    std::cout << OKGREEN << "Edited correctly " <<
    std::endl << ENDC;
    sleep(4);
  }
}

// Delete a deleteDonor
// This is a interface to the method implemented in CustomList
void Donors::deleteDonor() {
  Donor auxDonor;


  std::cin.ignore();
  auxDonor.readDonor();

  if (!this->list_.deleteDonor(auxDonor)) {
    BORRAR;
    LUGAR(6, 10);
    std::cout << FAIL << "Donor dont exists" << std::endl << ENDC;
    sleep(4);
  }
  else {
    BORRAR;
    LUGAR(6, 10);
    std::cout << OKGREEN << "Deleted correctly " <<
    std::endl << ENDC;
    sleep(4);
  }
}

// Load a list from a file
// This is a interface to the method implemented in CustomList
void Donors::loadFromFile() {
  list_.loadFromFile();
}

// Load a list from a file.
void Donors::saveToFile() {
  list_.saveToFile();
}

#endif // ifndef __DONORS_CPP_
