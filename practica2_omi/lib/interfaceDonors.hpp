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
class InterfaceDonors {
public:

  virtual bool isListEmpty()=0;
  virtual bool findDonor()= 0;

  virtual void insertNewDonor() = 0;
  virtual void deleteDonor()    = 0;
};
}
#endif // ifndef __INTERFACEDONORS_HPP_
