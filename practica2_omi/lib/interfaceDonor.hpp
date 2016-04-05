/*!
   \file interfaceDonor.hpp
   \brief Class Interface for Donor.
   \author Omar Sotillo
 */
#ifndef __INTERFACEDONOR_HPP_
#define __INTERFACEDONOR_HPP_

#include "../include/libraries.hpp"

namespace ed {
/*!
   \brief Class interface of a donor
 */
class InterfaceDonor {
public:

  // ! /Observers

  /*!
     \brief Get the name of a donor.
     \return string name.
     \pre There must exists the object.
     \post We get the name of a donor in a stream.
   */
  virtual std::string getName() const = 0;

  /*!
     \brief Get the surnames of a donor.
     \return string name.
     \pre There must exists the object.
     \post We get the surname of a donor in a stream.
   */
  virtual std::string getSurname() const = 0;

  /*!
     \brief Get the bloodType of a donor.
     \return string name.
     \pre There must exists the object.
     \post We get the bloodType of a donor in a stream.
   */
  virtual std::string getBloodType() const = 0;

  /*!
     \brief Get the rhfactor of a donor.
     \return string name.
     \pre There must exists the object.
     \post We get the rhfactor of a donor in a stream.
   */
  virtual bool        getRhFactor() const = 0;

  // ! /Sets

  /*!
     \brief Fuction to set the name of the donor
     \pre None
     \param name a string
     \post New name is set
   */
  virtual void setName(const std::string& name) = 0;

  /*!
     \brief Fuction to set the surname of the donor
     \pre None
     \param surname a string
     \post New surname is set
   */
  virtual void setSurname(const std::string& surname) = 0;

  /*!
     \brief Fuction to set the bloodType of the donor
     \pre None
     \param bloodType a string
     \post New bloodType is set
   */
  virtual bool setBloodType(const std::string& bloodType) = 0;

  /*!
     \brief Fuction to set the rhFactor of the donor
     \pre None
     \param rhFactor a boolean
     \post New rhfactor is set
   */
  virtual void setRhFactor(const bool& rhFactor) = 0;
};
}
#endif // ifndef __INTERFACEDONOR_HPP_
