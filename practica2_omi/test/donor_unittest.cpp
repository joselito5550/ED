#include "../include/all.hpp"
#include "gtest/gtest.h"

// Observers.
// getName Test
TEST(Observers, getName) {
  Donor donor("Omar", "Sotillo", "AB", true);

  EXPECT_EQ("Omar", donor.getName());
}

// getSurname Test
TEST(Observers, getSurname) {
  Donor donor("Omar", "Sotillo", "AB", true);

  EXPECT_EQ("Sotillo", donor.getSurname());
}

// getBloodType Test
TEST(Observers, getBloodType) {
  Donor donor("Omar", "Sotillo", "AB", true);

  EXPECT_EQ("AB", donor.getBloodType());
}

// getRhFactor Test
TEST(Observers, getRhFactor) {
  Donor donor("Omar", "Sotillo", "AB", true);

  EXPECT_TRUE(donor.getRhFactor());
}

// Sets
// setName
// setName Test
TEST(Sets, setName) {
  Donor donor("Omar", "Sotillo", "AB", true);

  donor.setName("Andrea");
  EXPECT_EQ("Andrea", donor.getName());
}

// setSurname Test
TEST(Sets, setSurname) {
  Donor donor("Omar", "Sotillo", "AB", true);

  donor.setSurname("Giovanni");
  EXPECT_EQ("Giovanni", donor.getSurname());
}

// setBloodType Test
TEST(Sets, setBloodType) {
  Donor donor("Omar", "Sotillo", "AB", true);

  donor.setBloodType("0");
  EXPECT_TRUE(donor.setBloodType("0"));
  EXPECT_EQ("0", donor.getBloodType());

  donor.setBloodType("Fail");
  EXPECT_FALSE(donor.setBloodType("Fail"));
  EXPECT_EQ("0", donor.getBloodType());
}

// setRhFactor Test
TEST(Sets, setRhFactor) {
  Donor donor("Omar", "Sotillo", "AB", true);

  donor.setRhFactor(false);
  EXPECT_FALSE(donor.getRhFactor());
}

// Constructors.
// Constructor initialized
TEST(Constructor, IsInitialized) {
  Donor donor;

  EXPECT_EQ("", donor.getName());
  EXPECT_EQ("", donor.getSurname());
  EXPECT_EQ("", donor.getBloodType());
  EXPECT_FALSE(donor.getRhFactor());
}

// Constructor initilized with params
TEST(Constructor, IsInitializedWithParams) {
  Donor donor("Omar", "Sotillo", "AB", true);

  EXPECT_EQ("Omar",    donor.getName());
  EXPECT_EQ("Sotillo", donor.getSurname());
  EXPECT_EQ("AB",      donor.getBloodType());
  EXPECT_TRUE(donor.getRhFactor());
}

// Constructor of copy
TEST(Constructor, IsInitializedWithOtherDonor) {
  Donor copyDonor("Omar", "Sotillo", "AB", true);
  Donor copiedDonor(copyDonor);

  EXPECT_EQ("Omar",    copiedDonor.getName());
  EXPECT_EQ("Sotillo", copiedDonor.getSurname());
  EXPECT_EQ("AB",      copiedDonor.getBloodType());
  EXPECT_TRUE(copiedDonor.getRhFactor());
}

// Checking operators
// Operator =
TEST(Operator, OperatorEqual) {
  Donor copyDonor("Omar", "Sotillo", "AB", true);
  Donor copiedDonor;

  copiedDonor = copyDonor;

  EXPECT_EQ(copyDonor.getName(),      copiedDonor.getName());
  EXPECT_EQ(copyDonor.getSurname(),   copiedDonor.getSurname());
  EXPECT_EQ(copyDonor.getBloodType(), copiedDonor.getBloodType());
  EXPECT_TRUE(copiedDonor.getRhFactor());
}

// Operator ==
TEST(Operator, OperatorComparation) {
  Donor copyDonor("Omar", "Sotillo", "AB", true);
  Donor copiedDonor(copyDonor);
  Donor auxDonor;

  EXPECT_TRUE(copyDonor == copiedDonor);
  EXPECT_FALSE(auxDonor == copiedDonor);
}

// Operator <=
TEST(Operator, OperatorComparationOrBigger) {
  Donor copyDonor("a", "Sotillo", "AB", true);
  Donor copiedDonor("b", "Sotillo", "AB", true);
  Donor auxDonor;

  EXPECT_TRUE(copyDonor <= copiedDonor);
  EXPECT_FALSE(copiedDonor <= copyDonor);
}

// Operator >>
TEST(Operator, OperatorIntroduceAndShow) {
  Donor copyDonor("a", "b", "AB", true);
  Donor auxDonor;

  std::cout << "Checking the functionality of << and >> in the donor domain" <<
  std::endl;
  std::cin >> auxDonor;
  EXPECT_TRUE(auxDonor == copyDonor);
  std::cout << auxDonor;
}

// Read Donor and Show
TEST(Donor, ReadandPrintDonor) {
  Donor copyDonor("a", "b", "AB", true);
  Donor auxDonor;

  auxDonor.readDonor();
  auxDonor.printDonor();
  EXPECT_TRUE(auxDonor == copyDonor);
}

// Read Donor and Show
TEST(Donor, ModifyDonor) {
  Donor copyDonor("a", "b", "AB", true);
  Donor copyDonor1("a", "b", "AB", true);
  Donor copyDonor2("a", "b", "AB", true);

  std::cout << "Leave empty if you would like it to be the same as before" <<
  std::endl;
  copyDonor2.readDonor();
  copyDonor2.printDonor();
  EXPECT_TRUE(copyDonor2 == copyDonor);
}
