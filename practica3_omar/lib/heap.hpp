/*!
   \file heap.hpp
   \brief Prototypes of the class heap
   \author Omar Sotillo Franco
   \date 21/April/2016
 */

#ifndef __HEAP_HPP_
#define __HEAP_HPP_

#include "donor.hpp"
#include "heapInterface.hpp"
#include "../include/libraries.hpp"

namespace ed {
/*!
   \brief Class representing a list of donors in a heap
 */
class Heap : public HeapInterface {
private:

  int numberOfElements_; /*!< Number of elements of a heap */
  std::vector<Donor> v_; /*!< A vector of the std. */

  int right_son(int i) { /*!< Right son of a node of the heap */
    return i * 2 + 2;
  }

  int left_son(int i) { /*!< Left son of a node of the heap */
    return i * 2 + 1;
  }

public:

  /*!
     \brief Constructor of the class Heap
     \pre A instance must be initiated
     \post A new heap is created
     \return None
   */
  Heap();

  /*!
     \brief Set of the number of elements
     \param aux integer number
     \pre None
     \post numberOfElements_ is changed
     \return None
   */
  void  setNumberOfElements(int aux);

  /*!
     \brief Get of the number of elements
     \pre A instance must be created
     \post The number of elements are returned
     \return integer number
   */
  int   getNumberOfElements();

  /*!
     \brief Check if a heap is empty or not
     \pre The object must be created
     \post None
     \return bool true if empty
   */
  bool  isEmpty() const;

  /*!
     \brief Getting the donor of the top of the heap
     \pre A heap must exist with a element
     \post A donor is returned
     \return Donor instance
   */
  Donor top() const;

  /*!
     \brief Function to inser a donor into a heap
     \param auxDonor Donor instance
     \pre None
     \post None
     \return None
   */
  void  insert(const Donor& auxDonor);

  /*!
     \brief Delete all the heap
     \pre None
     \post Heap should be empty
     \return None
   */
  void  deleteHeap();

  /*!
     \brief Delete the top of the heap.
     \pre None
     \post It delete the top donor a restructure the complete heap
     \return None
   */
  void  deleteTop();

  /*!
     \brief Printing all donors of a heap
     \pre There must be a donor within the heap
   */
  void  printDonors();

  /*!
     \brief Function to save the heap to a file.
     \post All donors must be into the heap.
   */
  void  saveToFile();

  /*!
     \brief Load all donors from a file
   */
  void  loadFromFile();
};
}


#endif // ifndef __HEAP_HPP_
