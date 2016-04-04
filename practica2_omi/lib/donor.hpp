/*!
   \file interfaceDonor.hpp
   \brief Class Interface for Donor.
   \author Omar Sotillo
 */
#ifndef __DONOR_HPP_
#define __DONOR_HPP_

#include "../include/libraries.hpp"
#include "interfaceDonor.hpp"

using namespace ed;

class Donor : public InterfaceDonor {
private:

  std::string name_;
  std::string surname_;
  std::string bloodType_;
  bool rhFactor_;

public:

  Donor();
  Donor(const std::string& name,
        const std::string& surname,
        const std::string& bloodType,
        const bool       & rhFactor);
  Donor(const Donor& copyDonor);

  std::string          getName() const;
  std::string          getSurname() const;
  std::string          getBloodType() const;
  bool                 getRhFactor() const;

  bool                 setBloodType(const std::string& bloodType);
  void                 setName(const std::string& name);
  void                 setSurname(const std::string& surname);
  void                 setRhFactor(const bool& rhFactor);

  void                 readDonor();
  void                 printDonor();

  Donor&               operator=(const Donor& copiedDonor);
  bool                 operator==(const Donor& comparedDonor);
  bool                 operator<=(const Donor& comparedDonor);

  friend std::istream& operator>>(std::istream& stream,
                                  Donor       & d);
  friend std::ostream& operator<<(std::ostream& stream,
                                  Donor const & d);
};

#endif // ifndef __DONOR_HPP_
