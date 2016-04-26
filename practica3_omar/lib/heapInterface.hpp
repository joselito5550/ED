/*!
   \file heapInterface.hpp
   \brief Prototypes of the class heapInterface
   \author Omar Sotillo Franco
   \date 21/April/2016
 */

#ifndef __HEAPINTERFACE_HPP_
#define __HEAPINTERFACE_HPP_

#include "../include/libraries.hpp"
#include "donor.hpp"
namespace ed {
/*!
   \brief Class interface for the heap
 */
class HeapInterface {
public:

  /*!
     \brief Check if a heap is empty or not
     \pre The object must be created
     \post None
     \return bool true if empty
   */
  virtual bool  isEmpty() const = 0;

  /*!
     \brief Getting the donor of the top of the heap
     \pre A heap must exist with a element
     \post A donor is returned
     \return Donor instance
   */
  virtual Donor top() const = 0;

  /*!
     \brief Function to inser a donor into a heap
     \param auxDonor Donor instance
     \pre None
     \post None
     \return None
   */
  virtual void  insert(const Donor& auxDonor) = 0;

  /*!
     \brief Delete the top of the heap.
     \pre None
     \post It delete the top donor a restructure the complete heap
     \return None
   */
  virtual void  deleteTop() = 0;
};
}


#endif // ifndef __HEAP_HPP_
