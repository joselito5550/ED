#ifndef __DONORS_HPP_
#define __DONORS_HPP_
#include "../include/libraries.hpp"
#include "donor.hpp"
#include "interfaceDonors.hpp"
#include "customlist.hpp"
using namespace ed;

class Donors : public InterfaceDonors {
private:

  CustomList list_;

public:

  Donors();
  Donors(CustomList list);

  CustomList getCustomList();
  void       setCustomList(CustomList list);
  void       readDonors();
  void       printDonors();

  bool       isListEmpty();
  bool       findDonor();

  void       insertNewDonor();
  void       deleteDonor();
  void       editDonor();

  void loadFromFile();
  void saveToFile();
};


#endif // ifndef __DONORS_HPP_
