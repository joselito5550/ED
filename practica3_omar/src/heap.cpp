/*!
   \file heap.cpp
   \brief Implementation of the heap function
   \author "Your name"
   \date "DD"/"Month"/"Year"
 */
#ifndef __HEAP_CPP_
#define __HEAP_CPP_
#include "../include/all.hpp"

Heap::Heap() {
  this->setNumberOfElements(0);
}

void Heap::setNumberOfElements(int aux) {
  this->numberOfElements_ = aux;
}

int Heap::getNumberOfElements() {
  return this->numberOfElements_;
}

bool Heap::isEmpty() const {
  return v_.empty();
}

Donor Heap::top() const {
  if (numberOfElements_ != 0) { // No way of get
    return v_.front();
  }
  else {
    Donor donor("NO", "", "", true, 0);
    return donor;
  }
}

void Heap::insert(const Donor& auxDonor) {
  if (this->getNumberOfElements() == 0) {
    v_.push_back(auxDonor);
    this->setNumberOfElements(this->getNumberOfElements() + 1);
  }
  else {
    std::vector<Donor>::iterator it = v_.begin();

    for (int i = 0; i < this->getNumberOfElements(); i++) {
      it++;
    }
    Donor aux;
    int   n = this->getNumberOfElements();
    v_.insert(it, auxDonor);

    // While the child is smaller than the parent
    while (v_[((n - 1) / 2)].getDonations() > v_[n].getDonations()) {
      std::swap(v_[n], v_[(n - 1) / 2]);
      n = ((n - 1) / 2);
    }
    this->setNumberOfElements(this->getNumberOfElements() + 1);
  }
}

void Heap::deleteTop()    {
  if (this->getNumberOfElements() != 0) {
    Donor aux;
    int   rightSon, leftSon, smallerSon;

    int  n        = 0;
    bool position = false;
    numberOfElements_--;
    std::swap(v_[0], v_[numberOfElements_]);
    std::vector<Donor>::iterator it = v_.begin();

    for (int i = 0; i < (numberOfElements_ + 1); i++) {
      it++;
    }
    v_.erase(it);

    while (n < numberOfElements_ && !position) {
      rightSon = right_son(n);
      leftSon  = left_son(n);

      if ((rightSon < numberOfElements_) && (leftSon < numberOfElements_)) {
        if (v_[rightSon].getDonations() < v_[leftSon].getDonations()) {
          smallerSon = right_son(n);
        }
        else if (v_[rightSon].getDonations() > v_[leftSon].getDonations()) {
          smallerSon = left_son(n);
        }

        if (v_[smallerSon].getDonations() < v_[n].getDonations()) {
          std::swap(v_[smallerSon], v_[n]);
          n = smallerSon;
        }
        else {
          position = true;
        }
      }
      else if ((rightSon < numberOfElements_) &&
               (leftSon >= numberOfElements_)) {
        if (v_[rightSon].getDonations() < v_[n].getDonations()) {
          std::swap(v_[rightSon], v_[n]);
          n        = rightSon;
          position = true;
        }
        else position = true;
      }
      else if ((rightSon >= numberOfElements_) &&
               (leftSon < numberOfElements_)) {
        if (v_[leftSon].getDonations() < v_[n].getDonations()) {
          std::swap(v_[leftSon], v_[n]);
          position = true;
        }
        else position = true;
      }
    }
  }
}

void Heap::saveToFile()   {
  Donor aux;
  std::string   auxString;
  std::ofstream myfile;

  // Opening file.
  myfile.open("../files/donors.txt");

  // Looping through item list.
  for (int  i = 0; i < numberOfElements_; i++) {
    // AuxString new value to be printed.
    aux       = v_[i];
    auxString = aux.getName() + "," += aux.getName() + "," +=
                                         aux.getBloodType()  + ","+= aux.getDonations()  + ",";

    if (aux.getRhFactor()) {
      auxString = auxString + "1\n";
    }
    else {
      auxString = auxString + "0\n";
    }
    myfile << auxString;
  }
}

void Heap::loadFromFile() {
  std::ifstream f;
  Donor aux;

  std::string line;
  std::string surname, name, blood,donations, rh_aux;
  bool rh;

  f.open("../files/donors.txt");

  while (getline(f, line)) {
    std::stringstream line_aux(line);

    // Changing value of the stream
    getline(line_aux, name,    ',');
    getline(line_aux, surname, ',');
    getline(line_aux, blood,   ',');
    getline(line_aux, donations,   ',');
    getline(line_aux, rh_aux,  '\n');

    // Setting the values.
    aux.setName(name);
    aux.setSurname(surname);
    aux.setDonations(atoi(donations.c_str()));
    aux.setBloodType(blood);

    if (rh_aux == "1") {
      rh = true;
    }
    else {
      rh = false;
    }
    aux.setRhFactor(rh);

    this->insert(aux);
  }
}

#endif // ifndef __HEAP_CPP_
