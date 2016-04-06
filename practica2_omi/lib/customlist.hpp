/*!
   \file customlist.hpp
   \brief Custom list of nodes.
   \author Omar Sotillo
 */
#ifndef __CUSTOMLIST_HPP_
#define __CUSTOMLIST_HPP_

#include "../include/libraries.hpp"
#include "donor.hpp"

/*!
   \brief A structure representing a element.
 */
struct Node {
  Donor donor;   /*!< A donor instance */
  Node *forward; /*!< A node reference to the following node */
};

/*!
   \brief Class of a CustomList.
 */
class CustomList {
private:

  int   numberOfNodes_; /*!< Number of nodes */
  Node *head_;          /*!< Node head of the list */
  Node *current_;       /*!< Node actual of the list */

public:

  //! \name Constructors.

  /*!
     \brief When a new CustomList is set a constructor is init.
     \pre An empty CustomList instance.
   */
  CustomList();

  //! \name Gets.

  /*!
     \brief Get the number of nodes.
     \return numberOfNodes_.
   */
  int getNumberOfNodes();

  //! \name Sets.

  /*!
     \brief Set the number of nodes.
     \param numberOfNodes a integer
   */
  void setNumberOfNodes(int numberOfNodes);

  /*!
     \brief Set the current node.
     \return current_.
     \param node a node structure.
   */
  void setCurrent(Node *node);

  // ! \name Othe fuctions.

  /*!
     \brief Print all the donors
   */
  void printDonors();

  /*!
     \brief Check if a list is empty or not.
     \return a boolean true or false.
   */
  bool isEmpty();

  /*!
     \brief Insert into a ordered list a donor.
     \param auxDonor a donor instance
   */
  void insert(Donor& auxDonor);

  /*!
     \brief Delete one donor of a list.
     \param auxDonor a donor instance
     \return a boolean true or false.
   */
  bool deleteDonor(Donor& auxDonor);

  /*!
     \brief Edit one donor of a list.
     \param auxDonor a donor instance
     \return a boolean true or false.
   */
  bool editDonor(Donor& auxDonor);

  /*!
     \brief Find one donor of a list.
     \param auxDonor a donor instance
     \return a integer to int.
   */
  int  findDonor(Donor& auxDonor);

  /*!
     \brief Find one position to insert.
     \param auxDonor a donor instance
     \return a position to where to enter.
   */
  int  findPositionToInsert(Donor& auxDonor);

  /*!
     \brief Set the cursor to a determined position.
     \param position a integer number
   */
  void setCursorToPosition(int position);

  /*!
     \brief Save a current list to the file.
   */
  void saveToFile();

  /*!
     \brief Take from a file a current list.
   */
  void loadFromFile();
};


#endif // ifndef __CUSTOMLIST_HPP_
