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
class Heap : public HeapInterface {
private:

  int numberOfElements_;
  std::vector<Donor> v_;

  int right_son(int i) {
    return i * 2 + 2;
  }

  int left_son(int i) {
    return i * 2 + 1;
  }

public:

  Heap();
  void setNumberOfElements(int aux);
  int getNumberOfElements();
  bool  isEmpty() const;
  Donor top() const;
  void  insert(const Donor& auxDonor) = 0;
  void  deleteTop()                   = 0;
  void  saveToFile();
  void  loadFromFile();
};
}


#endif // ifndef __HEAP_HPP_
