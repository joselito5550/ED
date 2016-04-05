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
  Donors donors;

  do {
    printmenu();
        LUGAR(18, 10);
    std::cin >> option;

    // Check emptyness of the list.
    if (option == 1) {
      BORRAR;

      if (donors.isListEmpty()) {
        LUGAR(6, 11);
        INTENSIDAD;
        std::cout << FAIL << "The current list is Empty" << std::endl << ENDC;
        sleep(3);
      }
      else {
        LUGAR(6, 11);
        INTENSIDAD;
        std::cout << OKGREEN << "The current list has " << WARNING <<
        donors.getCustomList().getNumberOfNodes() << OKGREEN << " values" <<
        std::endl << ENDC;

        sleep(3);
      }
    }

    if (option == 2) {
      donors.loadFromFile();
    }

    if (option == 3) {
      donors.saveToFile();
    }

    if (option == 4) {
      BORRAR;
      donors.insertNewDonor();
    }

    if (option == 5) {
      BORRAR;
      donors.editDonor();
    }

    if (option == 6) {
      BORRAR;
      donors.deleteDonor();
    }

    if (option == 7) {
      BORRAR;
      donors.printDonors();
        sleep(5);
    }
  } while (option != 8);

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
  std::cout << WARNING << "Check if there are Donors." <<
  std::endl << ENDC;
  LUGAR(9, 11);
  INTENSIDAD;
  std::cout << "2.- ";
  APAGA;
  std::cout << WARNING << "Load a list of donors from a file." <<
  std::endl << ENDC;
  LUGAR(10, 11);
  INTENSIDAD;
  std::cout << "3.- ";
  APAGA;
  std::cout << WARNING << "Save a list to the file." <<
  std::endl << ENDC;
  LUGAR(11, 11);
  INTENSIDAD;
  std::cout << "4.- ";
  APAGA;
  std::cout << WARNING << "Insert a new donor to current list." <<
  std::endl << ENDC;
  LUGAR(12, 11);
  INTENSIDAD;
  std::cout << "5.- ";
  APAGA;
  std::cout << WARNING << "Modify the information of a donor." <<
  std::endl << ENDC;
  LUGAR(13, 11);
  INTENSIDAD;
  std::cout << "6.- ";
  APAGA;
  std::cout << WARNING << "Delete a donor from the current list." <<
  std::endl << ENDC;
  LUGAR(14, 11);
  INTENSIDAD;
  std::cout << "7.- ";
  APAGA;
  std::cout << WARNING << "Print all donors of the current list" <<
  std::endl << ENDC;
  LUGAR(15, 11);
  INTENSIDAD;
  std::cout << "8.- ";
  APAGA;
  std::cout << WARNING << "Exit" <<
  std::endl << ENDC;

  LUGAR(17, 11);
  INTENSIDAD;
  std::cout << "Introduce the option: " << std::endl;
  APAGA;
}

#endif // ifndef __MAIN_CPP_
