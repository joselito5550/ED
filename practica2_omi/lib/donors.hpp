/*!
   \file donors.hpp
   \brief Donors class .
   \author Omar Sotillo
 */

#ifndef __DONORS_HPP_
#define __DONORS_HPP_
#include "../include/libraries.hpp"
#include "donor.hpp"
#include "interfaceDonors.hpp"
#include "customlist.hpp"
using namespace ed;

/*!
   \brief Donor.
 */
class Donors : public InterfaceDonors {
private:

  CustomList list_; /*!< Custom list */

public:

  /*!
     \brief When a new Donors is set a constructor is init.
     \pre An empty Donors instance.
     \post We set the values to NULLs.
   */
  Donors();

  /*!
     \brief When a new donors is set a constructor is init.
     \param list a custom list
     \pre An empty donors instance.
     \post We set the values to another donors.
   */
  Donors(CustomList list);

  /*!
     \brief Get the list of a donors.
     \return a list of donors.
     \pre There must exists the object.
     \post We get the list of donors in a stream.
   */
  CustomList getCustomList();

  /*!
     \brief Fuction to set the list of the donors
     \pre None
     \param list a custom list
     \post New list is set
   */
  void       setCustomList(CustomList list);

  /*!
     \brief Fuction to read the donors.
   */
  void       readDonors();

  /*!
     \brief Fuction to print the donors.
   */
  void       printDonors();

  /*!
     \brief Fuction to check if a list is empty of  the donors.
     \return a bolean true or false.
   */
  bool       isListEmpty();

  /*!
     \brief Find the existence of a donor
     \return a bolean true or false.
   */
  bool       findDonor();

  /*!
     \brief Function to inser a donor to the list_
   */
  void       insertNewDonor();

  /*!
     \brief Function to delete a donor to the list_
   */
  void       deleteDonor();

  /*!
     \brief Function to edit a donor to the list_
   */
  void       editDonor();

  /*!
     \brief Function to load from a file a list of donors
   */
  void       loadFromFile();

  /*!
     \brief Function to save to a file a list of donor
   */
  void       saveToFile();
};


#endif // ifndef __DONORS_HPP_
