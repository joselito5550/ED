#ifndef __DONORS_CPP_
#define __DONORS_CPP_
#include "../include/all.hpp"
Donors::Donors() {
  list_.setNumberOfNodes(0);
}

Donors::Donors(CustomList list) {
  this->setCustomList(list);
}

CustomList Donors::getCustomList()                {
  return list_;
}

void Donors::setCustomList(CustomList list) {
  this->list_ = list;
}

void Donors::readDonors() {}

void Donors::printDonors() {
  this->list_.printDonors();
}

bool Donors::isListEmpty()                  {
  return this->getCustomList().isEmpty();
}

bool Donors::findDonor() {
  return true;
}

void Donors::insertNewDonor()               {
  Donor auxDonor;

  std::cin.ignore();
  auxDonor.readDonor();
  this->list_.insert(auxDonor);
  this->list_.setNumberOfNodes((this->list_.getNumberOfNodes() + 1));
}

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


  void Donors::loadFromFile(){
    list_.loadFromFile();
  }
  void Donors::saveToFile(){
    list_.saveToFile();
  }

#endif // ifndef __DONORS_CPP_
