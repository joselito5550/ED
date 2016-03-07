/*!
   \file main.cpp
   \brief Main programm
   \author Omar Sotillo Franco
 */

#include "../include/all.hpp"

/*!
   \brief Function to print a menu and make the int main cleaner.
   \param We get the option choosen.
 */
void printmenu(int *option_menu);

/*!
   \brief Main function of the program implemented.
 */
int  main() {
  // DECLARING OBJECTS AND VARIABLES
  Monomial   monomial1(2, 2);
  Monomial   monomial2(monomial1);
  Monomial   monomial3 = monomial1;
  Polynomial polynomial1, polynomial2, polynomial3;

  std::vector<Monomial> v;

  double double1;
  int    option_menu, x_value;

  // PRINTING THE MENU OF THE MAIN.CPP
      printmenu(&option_menu);

  // WHILE OPTION IS DIFFERENT THAN -1 DO PROGRAM
  while (option_menu != -1) {
    // CALCULATE MONOMIAL
    if (option_menu == 1) {
      std::cout << std::string(50, '\n');
      monomial1.readMonomial();

      std::cout << HEADER << "Introduce the " << OKGREEN << "value" <<
      HEADER " of the x: " << ENDC;
      std::cin >> x_value;

      // CALCULATING X VALUE
      double1 = monomial1.calculateMonomial(x_value);

      std::cout << HEADER << "The value of the monomial is :" << WARNING <<
      double1 << ENDC << std::endl;

      printmenu(&option_menu);
    }

    // MULTIPLY MONOMIALS
    else if (option_menu == 2) {
      std::cout << std::string(50, '\n');

      // READING monomials
      monomial1.readMonomial();
      monomial2.readMonomial();

      // CALCULATING MULTIPLICATION
      monomial3 = (monomial1 * monomial2);
      std::cout << OKGREEN << "The new monomial is " << monomial3 << ENDC <<
      std::endl;

      printmenu(&option_menu);
    }

    // ADD TWO MONOMIALS
    else if (option_menu == 3) {
      std::cout << std::string(50, '\n');

      // READNING MONOMIALS
      monomial1.readMonomial();
      monomial2.readMonomial();

      // ADDING MONOMIALS
      monomial3 = (monomial1 + monomial2);
      std::cout << OKGREEN << "The new monomial is " << monomial3 << ENDC <<
      std::endl;

      printmenu(&option_menu);
    }

    // CALCULATE POLYNOMIALS
    else if (option_menu == 4) {
      std::cout << std::string(50, '\n');
      std::cout << HEADER << "Introduce the " << OKGREEN << "value" <<
      HEADER " of the x: " << ENDC;
      std::cin >> x_value;

      // CALCULATING X VALUE
      polynomial1.readPolynomial();
      polynomial1.printPolynomial();
      double1 = polynomial1.calculatePolynomial(x_value);

      std::cout << HEADER << "\nThe value of the monomial is :" << WARNING <<
      double1 << ENDC << std::endl;

      printmenu(&option_menu);
    }

    // MULTIPLY POLYNOMIALS
    else if (option_menu == 5) {
      std::cout << std::string(50, '\n');
      std::cout << WARNING << "Introduce the first polynomial:\n" << ENDC;
      polynomial1.readPolynomial();
      std::cout << WARNING << "Introduce the second polynomial:\n" << ENDC;
      polynomial2.readPolynomial();

      // READING
      std::cout << OKBLUE << "The first polynomial is:\n" << polynomial1 << ENDC;
      std::cout << OKBLUE << "The second polynomial is:\n" << polynomial2 << ENDC;

      // MULTIPLYING POLYNOMIALS
      polynomial3 = polynomial1 * polynomial2;

      polynomial3.orderPolynomial();
      polynomial3.printPolynomial();

      printmenu(&option_menu);
    }

    // ADDING TO POLYNOMIALS
    else if (option_menu == 6) {
      std::cout << std::string(50, '\n');
      std::cout << OKBLUE << "Introduce the first polynomial:\n" << ENDC;
      polynomial1.readPolynomial();
      std::cout << OKBLUE << "Introduce the second polynomial:\n" << ENDC;
      polynomial2.readPolynomial();
      std::cout << OKBLUE << "The first polynomial is:\n" << polynomial1 << ENDC;
      std::cout << OKBLUE << "The second polynomial is:\n" << polynomial2 << ENDC;
      // ADDING POLYNOMIALS
      polynomial3 = polynomial1 + polynomial2;
      polynomial3.orderPolynomial();
      polynomial3.printPolynomial();
      printmenu(&option_menu);
    }

    // EXIT
    else {
      option_menu = -1;
      std::cout << WARNING << "Bye" << ENDC << std::endl;
    }
  }
  return 0;
}

// Print function menu.
void printmenu(int *option_menu) {
  std::cout << FAIL << "\nWELCOME TO THE 1º PRACTICE OF ED" <<
  ENDC << std::endl;
  std::cout << FAIL << "================================" <<
  ENDC << std::endl;
  std::cout << WARNING << "1." << HEADER <<
  " Calculate a monomial in a X value." << ENDC << std::endl;
  std::cout << WARNING << "2." << HEADER << " Multiply two monomials." << ENDC <<
  std::endl;
  std::cout << WARNING << "3." << HEADER << " Add two monomials." << ENDC <<
  std::endl;
  std::cout << WARNING << "4." << HEADER << " Calculate a polynomial." << ENDC <<
  std::endl;
  std::cout << WARNING << "5." << HEADER << " Multiply two polynomials." <<
  ENDC <<  std::endl;
  std::cout << WARNING << "6." << HEADER << " Add two polynomials." <<
  ENDC <<  std::endl;
  std::cout << WARNING << "9." << HEADER << " Exit" << ENDC << std::endl;
  std::cout << OKBLUE << "Select one option:" << ENDC;
  std::cin >> *option_menu;
}
