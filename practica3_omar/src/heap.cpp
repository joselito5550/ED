/*!
   \file heap.cpp
   \brief Implementation of the heap function
   \author Omar Sotillo Franco
   \date 22/04/2016
 */
#ifndef __HEAP_CPP_
#define __HEAP_CPP_
#include "../include/all.hpp"

// Constructor
Heap::Heap() {
  this->setNumberOfElements(0);
}

// Setting the number of elements
void Heap::setNumberOfElements(int aux) {
  this->numberOfElements_ = aux;
}

// Getting the number of elements
int Heap::getNumberOfElements() {
  return this->numberOfElements_;
}

// Is list empty
bool Heap::isEmpty() const {
  return v_.empty();
}

// Getting the top donor
Donor Heap::top() const {
  if (numberOfElements_ != 0) return v_.front();  // If elements return the
                                                  // front of the heap
  else {
    Donor d("No", "", "", true);
    return d;
  }
}

// Inserting a donor into the system
void Heap::insert(const Donor& auxDonor) {
  // If no elements found
  if (numberOfElements_ == 0) {
    v_.push_back(auxDonor);
    numberOfElements_++;
  }

  // If elements
  else {
    std::vector<Donor>::iterator it = v_.end();

    // First we insert it at the end
    v_.insert(it, auxDonor);
    int n = numberOfElements_;

    // While the child is smaller than the father lets swap them
    while (v_[((n - 1) / 2)].getDonations() > v_[n].getDonations()) {
      std::swap(v_[n], v_[(n - 1) / 2]);
      n = ((n - 1) / 2); // Changing the father
    }
    numberOfElements_++;
  }
}

void Heap::deleteTop()    {
  if (numberOfElements_ != 0) {
    int  n           = 0;
    bool posicionado = false;
    numberOfElements_--;
    std::swap(v_[0], v_[numberOfElements_]);

    std::vector<Donor>::iterator it = v_.end();
    v_.erase(it);
    Donor aux;
    int   smaller_son;
    int rightson;
    int leftson;

    while (n < numberOfElements_ && !posicionado) {
      // Initiating son
      rightson   = right_son(n);
      leftson = left_son(n);

      // Both sides completed
      if ((rightson < numberOfElements_) &&
          (leftson < numberOfElements_)) {
        // Lets find who is bigger or smaller
        if (v_[rightson].getDonations() <
            v_[leftson].getDonations()) {
          smaller_son = right_son(n);
        }
        else if (v_[rightson].getDonations() >
                 v_[leftson].getDonations()) {
          smaller_son = left_son(n);
        }
        else if (v_[rightson].getDonations() ==
                 v_[leftson].getDonations()) {
          smaller_son = left_son(n);
        }

        if (v_[smaller_son].getDonations() < v_[n].getDonations()) {
          // Swapping them
          std::swap(v_[smaller_son], v_[n]);
          n = smaller_son;
        }
        else {
          posicionado = true;
        }
      }

      // Only right side
      else if ((rightson < numberOfElements_) &&
               (leftson >= numberOfElements_)) {
        if (v_[rightson].getDonations() < v_[n].getDonations()) {
          std::swap(v_[rightson], v_[n]);
          n           = rightson;
          posicionado = true;
        }
        else {
          posicionado = true;
        }
      }

      // Only left side
      else if ((rightson >= numberOfElements_) &&
               (leftson < numberOfElements_)) {
        if (v_[leftson].getDonations() < v_[n].getDonations()) {
          std::swap(v_[leftson], v_[n]);
          posicionado = true;
        }
        else {
          posicionado = true;
        }
      }
      else posicionado = true;
    }
  }
}

// Delete all the heap
void Heap::deleteHeap() {
  int n = numberOfElements_;

  for (int i = 0; i < n; i++) { // Looping throug the heap
    deleteTop();
  }
}

// Printing all std vector donors
void Heap::printDonors() {
  int n = numberOfElements_;

  for (int i = 0; i < n; i++) {
    v_[i].printDonor();
  }
}

// Save current heap to a file
void Heap::saveToFile()   {
  std::ofstream f;
  Donor aux;

  f.open("../files/donors.txt");

  if (f.fail()) {
    std::cout << "Error opening the file";
  }

  for (int i = 0; i < numberOfElements_; i++) {
    aux = v_[i];
    f << aux.getSurname() << ";" << aux.getName() << ";" << aux.getBloodType() <<
    ";" << aux.getRhFactor() << ";" << aux.getDonations() << "\n";
  }
  f.close();
}

// take from a file all current heap
void Heap::loadFromFile() {
  std::ifstream f;

  std::string line;
  std::string surname, name, group, rh_aux, donations;
  bool rh;

  f.open("../files/donors.txt");

  if (f.fail()) std::cout << "Error";
  else {
    while (getline(f, line)) {
      Donor aux;
      std::stringstream line_aux(line);
      getline(line_aux, surname,   ';');
      getline(line_aux, name,       ';');
      getline(line_aux, group,      ';');
      getline(line_aux, rh_aux,     ';');
      getline(line_aux, donations, ';');

      aux.setName(name);
      aux.setSurname(surname);
      aux.setBloodType(group);

      if (rh_aux == "1") {
        rh = true;
      }
      else {
        rh = false;
      }
      aux.setRhFactor(rh);
      aux.setDonations(atoi(donations.c_str()));
      aux.printDonor();
      insert(aux);
    }
  }
}

#endif // ifndef __HEAP_CPP_
