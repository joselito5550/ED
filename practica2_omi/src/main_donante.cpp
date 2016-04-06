/*!
   \file main.cpp
   \brief Main of the program.
   \author Omar Sotillo
 */
#ifndef __MAIN_CPP_
#define __MAIN_CPP_

#include "../include/all.hpp"
void printmenu();

/*!
   \brief Main function of the program
 */
int  main(int argc, char const *argv[]) {
  int option = 0;
  Donor donor,donor1;

  do {
    printmenu();
    LUGAR(18, 10);
    std::cin >> option;

    // Check emptyness of the list.
    if (option == 1) {
      donor.readDonor();
      BORRAR;
    }

    if (option == 2) {
      donor.printDonor();
      BORRAR;
    }

    if (option == 3) {
      std::cout << "Leave empty if you dont want to modify it" << std::endl;
      donor.readDonor();
      BORRAR;
    }

    if (option == 4) {
      std::cout << "Introduce first donor" << std::endl;
      donor.readDonor();
      std::cout << "Introduce 2º donor" << std::endl;
      donor1.readDonor();
      if (donor1==donor) {
        std::cout << "They are equal" << std::endl;
      }else{
        std::cout << "They are not equal" << std::endl;
      }

      BORRAR;
    }

    if (option == 5) {

    }
  } while (option != 5);

    LUGAR(19, 11);
  INTENSIDAD;
  std::cout << "BYE!" << std::endl;
  sleep(1);
  BORRAR;
  return 0;
}

/*!
   \brief Fuction to print a menu
 */
void printmenu() {
  BORRAR;

  // Welcoming the user to the main.
  LUGAR(4, 10);
  INTENSIDAD;
  SUBRAYADO;
  std::cout << HEADER << "Welcome to the 2º Work of ED!" << std::endl << ENDC;

  // Showing the menu
  LUGAR(6, 10);
  APAGA;
  std::cout << OKBLUE << "Please choose and option from the menu:" <<
  std::endl << ENDC;

  LUGAR(8, 11);
  INTENSIDAD;
  std::cout << "1.- ";
  APAGA;
  std::cout << WARNING << "Read a donor." <<
  std::endl << ENDC;
  LUGAR(9, 11);
  INTENSIDAD;
  std::cout << "2.- ";
  APAGA;
  std::cout << WARNING << "Print a donor." <<
  std::endl << ENDC;
  LUGAR(10, 11);
  INTENSIDAD;
  std::cout << "3.- ";
  APAGA;
  std::cout << WARNING << "Modify a donor." <<
  std::endl << ENDC;
  LUGAR(11, 11);
  INTENSIDAD;
  std::cout << "4.- ";
  APAGA;
  std::cout << WARNING << "Compare two donors." <<
  std::endl << ENDC;
  LUGAR(12, 11);
  INTENSIDAD;
  std::cout << "5.- ";
  APAGA;
  std::cout << WARNING << "Exit." <<
  std::endl << ENDC;

  LUGAR(17, 11);
  INTENSIDAD;
  std::cout << "Introduce the option: " << std::endl;
  APAGA;
}

#endif // ifndef __MAIN_CPP_
