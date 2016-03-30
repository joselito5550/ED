/*!
   \file interfaceDonor.hpp
   \brief Class Interface for Donor.
   \author Omar Sotillo
 */
#ifndef __INTERFACEDONOR_HPP_
#define __INTERFACEDONOR_HPP_

#include "../include/libraries.hpp"

namespace ed {
class InterfaceDonor {
public:

  // ! /Observers
  virtual std::string getName() const      = 0;
  virtual std::string getSurname() const   = 0;
  virtual std::string getBloodType() const = 0;
  virtual bool        getRhFactor() const  = 0;

  // ! /Sets
  virtual void        setName(const std::string& name)           = 0;
  virtual void        setSurname(const std::string& surname)     = 0;
  virtual bool        setBloodType(const std::string& bloodType) = 0;
  virtual void        setRhFactor(const bool& rhFactor)          = 0;

};
}
#endif // ifndef __INTERFACEDONOR_HPP_
