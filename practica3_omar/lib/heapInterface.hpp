/*!
   \file heapInterface.hpp
   \brief Prototypes of the class heapInterface
   \author Omar Sotillo Franco
   \date 21/April/2016
 */

#ifndef __HEAP_HPP_
#define __HEAP_HPP_

#include "../include/libraries.hpp"
#include "donor.hpp"
namespace ed {
class HeapInterface {
public:

  virtual bool  isEmpty() const               = 0;
  virtual Donor top() const                   = 0;
  virtual void  insert(const Donor& auxDonor) = 0;
  virtual void  deleteTop()                   = 0;
};
}


#endif // ifndef __HEAP_HPP_
