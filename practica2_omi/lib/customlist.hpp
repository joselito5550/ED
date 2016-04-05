#ifndef __CUSTOMLIST_HPP_
#define __CUSTOMLIST_HPP_
#include "../include/libraries.hpp"
#include "donor.hpp"

struct Node {
  Donor donor;
  Node *forward;
};

class CustomList {
private:

  int   numberOfNodes_;
  Node *head_;
  Node *current_;

public:

  CustomList();

  int  getNumberOfNodes();
  void setNumberOfNodes(int numberOfNodes);
  void setCurrent(Node *node);

  void printDonors();
  bool isEmpty();

  void insert(Donor& auxDonor);
  bool deleteDonor(Donor& auxDonor);
  bool editDonor(Donor& auxDonor);

  int  findDonor(Donor& auxDonor);
  int  findPositionToInsert(Donor& auxDonor);
  void setCursorToPosition(int position);
  void saveToFile();
  void loadFromFile();
};


#endif // ifndef __CUSTOMLIST_HPP_
