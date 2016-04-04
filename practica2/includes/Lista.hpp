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
    if(pos<=numNodos || pos == 0){
      ret = true;
    }
    else ret = false;
    return ret;
  }

  bool cursor_to(int pos){
    cur=head;
    if(isValid(pos)){
      for(int i=0;i<pos;i++){
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
    Donante d;
    if(aux){
      d= cur->d;
      return d;
    }
    else{
      return d;
    }
  }

  int findItem(const Donante& d,int pos){
      bool aux = cursor_to(0);
      bool encontrado = false;
      if(aux){
      while(  !encontrado  && cur!=NULL){
        if(cur->d.getName() == d.getName() && cur->d.getSecondName()==d.getSecondName()){
          encontrado = true;
        }
        else{
          cur = cur->next;
          pos++;
        }
      }
      }
      if(encontrado){
        return pos;}
      else return -1;
  }

//CUIDADO
  void insert(int pos, const Donante &d){
    bool ok = isValid(pos);
    if(numNodos==0){
      Nodo *nuevo = new Nodo;
      nuevo->d = d;
      nuevo->next=NULL;
      nuevo->pre=NULL;
      head = nuevo;
      numNodos++;
    }
    else{
    if(ok){
      if(pos==0){
        Nodo *nuevo = new Nodo;
        nuevo->d=d;
        nuevo->next = head;
        nuevo->pre = NULL;
        head->pre = nuevo;
        head = nuevo;
        numNodos++;
      }
      else if(pos==numNodos){
        Nodo* aux = new Nodo;
        aux->d = d;
        ok=cursor_to(pos-1);
        aux->pre = cur;

        aux->next = NULL;
        cur->next =aux;
        numNodos++;

      }
      else{

    Nodo* aux = new Nodo;
    aux->d = d;
    ok=cursor_to(pos-1);
    aux->pre = cur;

    aux->next = cur->next;
    cur->next->pre = aux;
    cur->next =aux;
    numNodos++;
    }
    }
  }
  }

  void remove(int pos){
    bool ok = cursor_to(pos);
    Nodo *aux;
    if(ok){
      if(cur->pre==NULL){
        head = cur->next;
        delete cur;
        numNodos--;
      }
      else if(cur->next==NULL){
        aux = cur;
        cur = cur->pre;
        cur->next = NULL;
        delete aux;
        numNodos--;
      }
      else{
        aux = cur;
        cur = cur->pre;
        cur -> next = aux-> next;
        aux -> next -> pre = cur;
        delete aux;
        numNodos--;
      }
    }
  }

//La comparacion pasarla todas a mayusculas o minusculas
  int findPos(const Donante &d){
    int pos=0;
    if(numNodos==0){
      return pos;
    }
    else{

    bool ok = cursor_to(0);
    if(ok){
      while(cur!=NULL && cur->d>=d ){
        cur = cur->next;
        pos++;
      }
    }
    return pos;
  }
  }

  void showlist(){
    cur = head;
    Donante d;
    for(int i=0;i<numNodos;i++){
      d=cur->d;
      std::cout<<"Name: "<<d.getName();
      std::cout<<"\n";
      std::cout<<"SecondName: "<<d.getSecondName();
      std::cout<<"\n";
      std::cout<<"Group: "<<d.getGroup();
      std::cout<<"\n";
      std::cout<<"RH: "<<d.getRH();
      std::cout<<"\n";
      std::cout<<"\n";
      std::cout<<"\n";
      cur = cur->next;
    }
    getchar();
  }

void showlistRH(bool RH){
  cur = head;
  Donante d;
  for(int i=0;i<numNodos;i++){
    if(cur->d.getRH()==RH){
      d = cur->d;
      std::cout<<"Name: "<<d.getName();
      std::cout<<"\n";
      std::cout<<"SecondName: "<<d.getSecondName();
      std::cout<<"\n";
      std::cout<<"Group: "<<d.getGroup();
      std::cout<<"\n";
      std::cout<<"RH: "<<d.getRH();
      std::cout<<"\n";
      std::cout<<"\n";
      std::cout<<"\n";
    }
    cur = cur->next;
  }
  getchar();
}

  int exist(Donante &d){
    int pos=0;
    cursor_to(0);
    bool encontrado = false;
    while(cur!=NULL && !encontrado && cur->d>=d){
      if(cur->d == d){
        encontrado = true;
      }
      else{
        cur = cur->next;
        pos++;
      }
    }
    if(encontrado){
      return pos;
    }
    else {
      return -1;
    }
  }

void borrarLista(){
  for(int i=0;i<numNodos;i++){
    if(head->next!=NULL){
      cur=head->next;
    }
    delete head;
    head = cur;
  }
}
  ~Lista(){
  borrarLista();
  }

};

#endif
