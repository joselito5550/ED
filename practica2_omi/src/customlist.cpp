/*!
   \file customlist.cpp
   \brief Implemented methods of custom list
   \author Omar Sotillo
 */
 #ifndef __CUSTOMLIST_CPP_
#define __CUSTOMLIST_CPP_
#include "../include/all.hpp"

CustomList::CustomList() {
  this->setNumberOfNodes(0);
  head_    = new Node;
  current_ = new Node;
}

int CustomList::getNumberOfNodes()                  {
  return this->numberOfNodes_;
}

void CustomList::setNumberOfNodes(int numberOfNodes) {
  this->numberOfNodes_ = numberOfNodes;
}

void CustomList::setCurrent(Node *node) {
  this->current_ = node;
}

void CustomList::printDonors() {
  this->setCurrent(this->head_);

  for (int  i = 0; i < numberOfNodes_; i++) {
    LUGAR(i + 5, 10);
    std::cout << this->current_->donor;
    this->setCurrent(this->current_->forward);
  }
}

int CustomList::findPositionToInsert(Donor& auxDonor) {
  int position = -1;

  this->setCurrent(this->head_);

  for (int  i = 0; i < numberOfNodes_; i++) {
    if (this->current_->donor <= auxDonor) {
      position = i;
    }
    this->setCurrent(this->current_->forward);
  }
  return position;
}

// Inserting into a ordered list.
void CustomList::insert(Donor& auxDonor) {
  int position = findPositionToInsert(auxDonor);

  position++;
  std::cout << position << std::endl;

  if (this->getNumberOfNodes() == 0) {
    Node *aux = new Node;
    aux->donor     = auxDonor;
    aux->forward   = new Node;
    this->head_    = aux;
    this->current_ = aux;
  } else {
    if (position == 0) {
      Node *aux = new Node;
      aux->donor     = auxDonor;
      aux->forward   = this->head_;
      this->head_    = aux;
      this->current_ = aux;
    }
    else if (position == this->getNumberOfNodes()) {
      this->setCursorToPosition(numberOfNodes_);
      this->current_->donor   = auxDonor;
      this->current_->forward = new Node;
    }
    else if ((position != 0) || (position == this->getNumberOfNodes())) {
      this->setCursorToPosition(position - 1);
      Node *aux = new Node;
      aux->donor              = auxDonor;
      aux->forward            = this->current_->forward;
      this->current_->forward = aux;
    }
  }
}

// Delete a custom Donor.
bool CustomList::deleteDonor(Donor& auxDonor) {
  int position;

  position = this->findDonor(auxDonor);

  if (position != -1) {
    if (position == 0) {
      this->head_ = this->head_->forward;
    } else {
      this->setCursorToPosition(position - 1);
      this->current_->forward = this->current_->forward->forward;
    }
    this->numberOfNodes_ = this->numberOfNodes_ - 1;
    return true;
  }
  else {
    return false;
  }
}

// Edit a donor.
bool CustomList::editDonor(Donor& auxDonor) {
  int position;

  position = this->findDonor(auxDonor);

  if (position != -1) {
    this->setCursorToPosition(position - 1);
    BORRAR;
    LUGAR(5, 9);
    INTENSIDAD;
    std::cout << "Leave empty if you would like it to be the same as before" <<
    std::endl;
    APAGA;
    this->current_->donor.readDonor();

    return true;
  }
  else {
    return false;
  }
}

// Find a determined donor
int CustomList::findDonor(Donor& auxDonor) {
  int position = -1;

  this->setCurrent(this->head_);

  for (int  i = 0; i < numberOfNodes_; i++) {
    if (this->current_->donor == auxDonor) {
      position = i;
    }
    this->setCurrent(this->current_->forward);
  }
  return position;
}

// Check if current list empty
bool CustomList::isEmpty()             {
  if (this->getNumberOfNodes() == 0) return true;
  else return false;
}

// Set the current_ to
void CustomList::setCursorToPosition(int position) {
  this->setCurrent(this->head_);

  for (int  i = 0; i < position; i++) {
    this->setCurrent(this->current_->forward);
  }
}

// Save from list to file
void CustomList::saveToFile() {
  std::string   auxString;
  std::ofstream myfile;

  myfile.open("../files/donors.txt");
  this->setCurrent(this->head_);


  for (int  i = 0; i < numberOfNodes_; i++) {
    auxString
      = this->current_->donor.getName() + "," +=
          this->current_->donor.getName() +
          "," +=
            this->current_->donor.
            getBloodType() + ",";

    if (this->current_->donor.getRhFactor()) {
      auxString = auxString + "1\n";
    }
    else {
      auxString = auxString + "0\n";
    }
    myfile << auxString;
    this->setCurrent(this->current_->forward);
  }
}

// Load a list from a file.
void CustomList::loadFromFile() {
  std::ifstream f;
  Donor aux;
  std::string line;
  std::string surname, name, blood, rh_aux;
  bool rh;

  f.open("../files/donors.txt");

  while (getline(f, line)) {
    std::stringstream line_aux(line);

    getline(line_aux, name,    ',');
    getline(line_aux, surname, ',');
    getline(line_aux, blood,   ',');
    getline(line_aux, rh_aux,  '\n');
    std::cout << name << std::endl;
    std::cout << surname << std::endl;
    std::cout << rh_aux << std::endl;
    aux.setName(name);
    aux.setSurname(surname);
    aux.setBloodType(blood);

    if (rh_aux == "1") {
      rh = true;
    }
    else {
      rh = false;
    }
    aux.setRhFactor(rh);

    this->insert(aux);
    this-> numberOfNodes_++;
  }
}

#endif // ifndef __CUSTOMLIST_CPP_
