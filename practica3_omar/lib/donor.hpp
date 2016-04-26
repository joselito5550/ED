/*!
   \file donor.hpp
   \brief Class for donor.
   \author Omar Sotillo
 */

#ifndef __DONOR_HPP_
#define __DONOR_HPP_

#include "../include/libraries.hpp"
#include "interfaceDonor.hpp"

using namespace ed;

/*!
   \brief Donor.
 */
class Donor : public InterfaceDonor {
private:

  std::string name_;      /*!< Name of the donor */
  std::string surname_;   /*!< Surname of the donor */
  std::string bloodType_; /*!< BloodType of the donor*/
  bool rhFactor_;         /*!< Rhfactor of a donor */
  int  donations_;

public:

  /*!
     \brief When a new donor is set a constructor is init.
     \pre An empty donor instance.
     \post We set the values to NULLs.
   */
  Donor();

  /*!
     \brief When a new donor is set a constructor is init.
     \param name a string
     \param surname a string
     \param bloodType a string
     \param rhFactor a string
     \pre An empty donor instance.
     \post We set the values to the donor.
   */
  Donor(const std::string& name,
        const std::string& surname,
        const std::string& bloodType,
        const bool       & rhFactor);

  /*!
     \brief When a new donor is set a constructor is init.
     \param copyDonor a donor instance
     \pre An empty donor instance.
     \post We set the values to another donor.
   */
  Donor(const Donor& copyDonor);

  /*!
     \brief Get the name of a donor.
     \return a string.
     \pre There must exists the object.
     \post We get name of a donor in a stream.
   */
  std::string getName() const;

  /*!
     \brief Get the surname of a donor.
     \return a string.
     \pre There must exists the object.
     \post We get surname of a donor in a stream.
   */
  std::string getSurname() const;

  /*!
     \brief Get the bloodType of a donor.
     \return a string.
     \pre There must exists the object.
     \post We get bloodType of a donor in a stream.
   */
  std::string getBloodType() const;

  /*!
     \brief Get the rhFactor of a donor.
     \return a string.
     \pre There must exists the object.
     \post We get rhfactor of a donor in a stream.
   */
  bool        getRhFactor() const;

  /*!
     \brief Getting the donations made by a donor
     \pre There must exist a object
     \post We get the donations of a donor
     \return a integer.
   */
  int         getDonations() const;

  /*!
     \brief Setting the donations of a donors
     \param donations is a integer
   */
  void        setDonations(const int& donations);

  /*!
     \brief Fuction to set the bloodType of the donor
     \pre None
     \param bloodType a string
     \post New bloodType is set
   */
  bool        setBloodType(const std::string& bloodType);

  /*!
     \brief Fuction to set the name of the donor
     \pre None
     \param name a string
     \post New name is set
   */
  void        setName(const std::string& name);

  /*!
     \brief Fuction to set the surname of the donor
     \pre None
     \param surname a string
     \post New surname is set
   */
  void        setSurname(const std::string& surname);

  /*!
     \brief Fuction to set the rhfactor of the donor
     \pre None
     \param rhFactor a boolean
     \post New rhfactor is set
   */
  void        setRhFactor(const bool& rhFactor);

  /*!
     \brief A Donor is read by a user.
   */
  void        readDonor();

  /*!
     \brief A Donor is printed in the screen.
   */
  void        printDonor();

  // ! \name Operators.

  /*!
     \brief Overload of the operator =.
     \return A new donor.
     \pre A donor is created.
     \param copiedDonor a donor instance
     \post The donor is set with the new value.
   */
  Donor&               operator=(const Donor& copiedDonor);

  /*!
     \brief Overload of the operator ==.
     \return A boolean.
     \param comparedDonor a donor instance
     \post The donor is compared.
   */
  bool                 operator==(const Donor& comparedDonor);

  /*!
     \brief Overload of the operator <=.
     \return A boolean.
     \param comparedDonor a donor instance
     \post The donor is compared.
   */
  bool                 operator<=(const Donor& comparedDonor);

  /*!
     \brief Overload of the operator >>.
     \param stream a in stream
     \param d a donor instance
     \pre There must be a donor created.
     \post We Introduce the values of the donor.
   */
  friend std::istream& operator>>(std::istream& stream,
                                  Donor       & d);

  /*!
     \brief Overload of the operator <<.
     \param stream a in stream
     \param d a donor instance
     \pre There must be a donor created.
     \post We print the values of a donor
   */
  friend std::ostream& operator<<(std::ostream& stream,
                                  Donor const & d);
};

#endif // ifndef __DONOR_HPP_
