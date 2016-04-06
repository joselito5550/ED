/*!
   \file customlist.cpp
   \brief Implemented methods of custom list
   \author Omar Sotillo
 */
 #ifndef __CUSTOMLIST_CPP_
#define __CUSTOMLIST_CPP_
#include "../include/all.hpp"

// Constructor
CustomList::CustomList() {
  this->setNumberOfNodes(0);
  head_    = new Node;
  current_ = new Node;
}

// Get the number of nodes of a list
int CustomList::getNumberOfNodes()                  {
  return this->numberOfNodes_;
}

// Set the number of nodes o a list.
void CustomList::setNumberOfNodes(int numberOfNodes) {
  this->numberOfNodes_ = numberOfNodes;
}

// Set the current node of a list
void CustomList::setCurrent(Node *node) {
  this->current_ = node;
}

// Function to print the current list
void CustomList::printDonors() {
  this->setCurrent(this->head_);

  // Looping thorugh the items of the list and printing them.
  for (int  i = 0; i < numberOfNodes_; i++) {
    LUGAR(i + 5, 10);
    std::cout << this->current_->donor;
    this->setCurrent(this->current_->forward); // Changing current
  }
}

// Finding a position to insert into.
int CustomList::findPositionToInsert(Donor& auxDonor) {
  // If not initiated go -1
  int position = -1;

  this->setCurrent(this->head_); // Changing the current to the head of the
                                 // file.

  // Looping through the items.
  for (int  i = 0; i < numberOfNodes_; i++) {
    if (this->current_->donor <= auxDonor) { // Check if a donor is bigger than
                                             // the first one.
      position = i;                          // Coping the value for return
    }
    this->setCurrent(this->current_->forward);
  }
  return position;
}

// Inserting into a ordered list.
void CustomList::insert(Donor& auxDonor) {
  // Lets find where we have to insert the current auxDonor instance.
  int position = findPositionToInsert(auxDonor);

  // Incrementing it to change the position.
  position++;

  // If list is empty lets add it to the head.

  if (this->getNumberOfNodes() == 0) {
    Node *aux = new Node; // New donor instance and set the new values with
                          // auxDonor and a new Node
    aux->donor     = auxDonor;
    aux->forward   = new Node;
    this->head_    = aux;
    this->current_ = aux;
  }

  // If number of nodes is different than 0 lets find where to add using
  // position item
  else {
    // If position is 0 it means we have to add it to the head of the file :)
    if (position == 0) {
      // Lets focus on creating a new NOde that well be the head node and it is
      // pointing to the pre-head node
      Node *aux = new Node;
      aux->donor     = auxDonor;
      aux->forward   = this->head_;
      this->head_    = aux;
      this->current_ = aux;
    }

    // If position is last we just have to pushback the auxDonor item
    else if (position == this->getNumberOfNodes()) {
      this->setCursorToPosition(numberOfNodes_); // We set the current to the
                                                 // last position.
      this->current_->donor   = auxDonor;
      this->current_->forward = new Node;
    }
    else if ((position != 0) || (position == this->getNumberOfNodes())) {
      // We set the curson to the position before where we have to insert it.
      this->setCursorToPosition(position - 1);
      Node *aux = new Node; //  A new donor instance is created and this will
                            // have as value the auxDonor and the forward the
                            // current forward node as forward and we will set
                            // the this->current forward node as aux;
      aux->donor              = auxDonor;
      aux->forward            = this->current_->forward;
      this->current_->forward = aux;
    }
  }
}

// Delete a custom Donor.
bool CustomList::deleteDonor(Donor& auxDonor) {
  int position;

  // Lets find which is the position of the donor.
  position = this->findDonor(auxDonor);

  // If found
  if (position != -1) {
    // If we have to delete the head.
    if (position == 0) {
      this->head_ = this->head_->forward;
    }

    // We set the forwardt to the next forward.
    // FIXME: We should clear the node.
    else {
      this->setCursorToPosition(position - 1);
      this->current_->forward = this->current_->forward->forward;
    }

    // Decreasing number of items
    this->numberOfNodes_ = this->numberOfNodes_ - 1;
    return true;
  }

  // If not found
  else {
    return false;
  }
}

// Edit a donor.
bool CustomList::editDonor(Donor& auxDonor) {
  int position;

  // Lets find which is the position of the donor.
  position = this->findDonor(auxDonor);

  // If found
  if (position != -1) {
    this->setCursorToPosition(position - 1);

    // Printing edition.
    BORRAR;
    LUGAR(5, 9);
    INTENSIDAD;
    std::cout << "Leave empty if you would like it to be the same as before" <<
    std::endl;
    APAGA;

    // We just read again the donor. Custom edit is Implemented within the read
    // function.
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

  // We set the current to head
  this->setCurrent(this->head_);

  // Looping through the items elements
  for (int  i = 0; i < numberOfNodes_; i++) {
    if (this->current_->donor == auxDonor) { // If the same do the following
      position = i;                          // Change position value;
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

  // Opening file.
  myfile.open("../files/donors.txt");
  this->setCurrent(this->head_);

  // Looping through item list.
  for (int  i = 0; i < numberOfNodes_; i++) {
    // AuxString new value to be printed.
    auxString
      = this->current_->donor.getName() + "," +=
          this->current_->donor.getName() + ","
            += this->current_->donor.getBloodType()  + ",";

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

  // Values needet to copy
  // TODO: Can be simplified.
  std::string line;
  std::string surname, name, blood, rh_aux;
  bool rh;

  f.open("../files/donors.txt");

  while (getline(f, line)) {
    std::stringstream line_aux(line);

    // Changing value of the stream
    getline(line_aux, name,    ',');
    getline(line_aux, surname, ',');
    getline(line_aux, blood,   ',');
    getline(line_aux, rh_aux,  '\n');

    // Setting the values.
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
    this->numberOfNodes_++;
  }
}

#endif // ifndef __CUSTOMLIST_CPP_
