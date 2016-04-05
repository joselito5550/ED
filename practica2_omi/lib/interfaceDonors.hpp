/*!
   \file interfaceDonors.hpp
   \brief Class Interface for Donors.
   \author Omar Sotillo
 */
#ifndef __INTERFACEDONORS_HPP_
#define __INTERFACEDONORS_HPP_

#include "../include/libraries.hpp"
#include "donor.hpp"
namespace ed {
  /*!
     \brief Class interface of donors
   */
class InterfaceDonors {
public:
  /*!
     \brief Fuction to check if a list is empty
   */
  virtual bool isListEmpty()=0;
  /*!
     \brief Fuction to find a donor
   */
  virtual bool findDonor()= 0;

  /*!
     \brief Fuction to insert a new donor
   */
  virtual void insertNewDonor() = 0;
  /*!
     \brief Fuction to delete a donor
   */
  virtual void deleteDonor()    = 0;
};
}
#endif // ifndef __INTERFACEDONORS_HPP_
