#ifndef __LISTA__
#define __LISTA__
#include "librerias.hpp"
using namespace ed;
struct Nodo{
  Donante d;
  Nodo* next;
  Nodo* pre;
};

class Lista{
private:
  int numNodos;
  Nodo* head;
  Nodo* cur;  //Cursor
public:
  Lista(){
    head = NULL;
    cur = NULL;
    numNodos = 0;
  }

  bool isValid(int pos){
    bool ret;
    if(pos<numNodos){
      ret = true;
    }
    else ret = false;
    return ret;
  }

  bool cursor_to(int pos){
    cur=head;
    if(isValid(pos)){
      for(int i=0;i<pos;){
        cur=cur->next;
      }
      return true;
    }
    else return false;
  }

  bool empty()const{
    if(head==NULL){
      return true;
    }
    else return false;
  }

  //return the element
  Donante item(int pos){
    bool aux = cursor_to(pos);
    if(aux){
      return cur->d;
    }
    else{
      Donante d;
      return d;
    }
  }

  int findItem(const Donante& d,int pos){
      bool aux = cursor_to(0);
      if(aux){
      while(cur->d.getName() != d.getName() && cur->d.getSecondName()!=d.getSecondName() && cur!=NULL){
        cur = cur->next;
        pos++;
      }
      }
      return pos;
  }

  void insert(int pos, const Donante &d){

  }
  void remove(int pos){

  }

  int findPos(const Donante &d){
    int pos=0;
    return pos;
  }

};

#endif
