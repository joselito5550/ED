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
  ed::Heap auxHeap;
  Donor    auxDonor;

  do {
    printmenu();
    LUGAR(18, 10);
    std::cin >> option;

    // Check emptyness of the heap.
    if (option == 1) {
      BORRAR;

      if (auxHeap.isEmpty()) {
        std::cout << FAIL << "The heap is empty. No elements found." << ENDC <<
        std::endl;
      } else {
        std::cout << OKGREEN << "The heap is not empty." << ENDC << std::endl;
      }
      getchar();
      getchar();
    }

    if (option == 2) {
      BORRAR;
      auxHeap.deleteHeap();
      std::cout << "DENTRO DE LA FUNCIÓN " << std::endl;
      auxHeap.loadFromFile();
      std::cout << "LO QUE SE RECIBE EN EL MAIN" << std::endl;
      auxHeap.printDonors();
      LUGAR(6, 10);
      std::cout << OKGREEN << "New heap loaded" << std::endl;
      getchar();
      getchar();
    }

    if (option == 3) {
      BORRAR;
      auxHeap.saveToFile();
      LUGAR(6, 10);
      std::cout << OKGREEN << "New heap saved" << std::endl;
      getchar();
      getchar();
    }

    if (option == 4) {
      BORRAR;

      if (auxHeap.top().getName() != "No") auxHeap.top().printDonor();
      getchar();
      getchar();
    }

    if (option == 5) {
      BORRAR;
    }
  } while (option != 6);

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
  std::cout << HEADER << "Welcome to the 3º Work of ED!" << std::endl << ENDC;

  // Showing the menu
  LUGAR(6, 10);
  APAGA;
  std::cout << OKBLUE << "Please choose and option from the menu:" <<
  std::endl << ENDC;

  LUGAR(8, 11);
  INTENSIDAD;
  std::cout << "1.- ";
  APAGA;
  std::cout << WARNING << "Check if a heap is empty." <<
  std::endl << ENDC;
  LUGAR(9, 11);
  INTENSIDAD;
  std::cout << "2.- ";
  APAGA;
  std::cout << WARNING << "Load from a file a heap" <<
  std::endl << ENDC;
  LUGAR(10, 11);
  INTENSIDAD;
  std::cout << "3.- ";
  APAGA;
  std::cout << WARNING << "Save a heap to a file." <<
  std::endl << ENDC;
  LUGAR(11, 11);
  INTENSIDAD;
  std::cout << "4.- ";
  APAGA;
  std::cout << WARNING << "Show the donor in the top of the heap." <<
  std::endl << ENDC;
  LUGAR(12, 11);
  INTENSIDAD;
  std::cout << "5.- ";
  APAGA;
  std::cout << WARNING << "Simulate a donation." <<
  std::endl << ENDC;
  LUGAR(13, 11);
  INTENSIDAD;
  std::cout << "6.- ";
  APAGA;
  std::cout << WARNING << "Exit" <<
  std::endl << ENDC;

  LUGAR(15, 11);
  INTENSIDAD;
  std::cout << "Introduce an option: " << std::endl;
  APAGA;
}

#endif // ifndef __MAIN_CPP_
