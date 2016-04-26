/*!
   \file heap.cpp
   \brief Implementation of the heap function
   \author "Your name"
   \date "DD"/"Month"/"Year"
 */
#ifndef __HEAP_CPP_
#define __HEAP_CPP_
#include "../include/all.hpp"

Heap::Heap() {
  this->setNumberOfElements(0);
}

void Heap::setNumberOfElements(int aux) {
  this->numberOfElements_ = aux;
}

int Heap::getNumberOfElements() {
  return this->numberOfElements_;
}

bool Heap::isEmpty() const {
  return v_.empty();
}

Donor Heap::top() const {
  if (numberOfElements_ != 0) return v_.front();
  else {
    Donor d("No", "", "", true);
    return d;
  }
}

void Heap::insert(const Donor& auxDonor) {
  // Si no hay elementos
  if (numberOfElements_ == 0) {
    // Elemento raiz
    v_.push_back(auxDonor);
    numberOfElements_++;
  }

  // Si hay elementos
  else {
    std::vector<Donor>::iterator it = v_.end();

    // Lo insertamos al final
    v_.insert(it, auxDonor);
    int n = numberOfElements_;

    // Mientras que el hijo sea menor que el padre lo vamos intercambiando
    while (v_[((n - 1) / 2)].getDonations() > v_[n].getDonations()) {
      // hacemos el intercambio
      std::swap(v_[n], v_[(n - 1) / 2]);

      // Volvemos a observar el nuevo padre
      n = ((n - 1) / 2);
    }
    numberOfElements_++;
  }
}

void Heap::deleteTop()    {
  if(numberOfElements_!=0){
    //El ultimo elemento lo ponemos de raiz, y hundimos
    int n = 0;
    bool posicionado = false;
    numberOfElements_--;
    std::swap(v_[0],v_[numberOfElements_]);

    //Borramos el ultimo elemento una vez hemos hecho el intercambio
    std::vector<Donor>::iterator it = v_.end();
    v_.erase(it);
    Donor aux;
    int hijo_menor; //Guardaremos la posicion del hijo

    int hijo_derecho;
    int hijo_izquierdo;

    //Mientras que no nos pasemos y no este aun colocado el elemento en su posicion
    while(n<numberOfElements_ && !posicionado){
      //Con posicionado controlamos si tiene algun hijo menor aun o ya hemos encontrado su posicion
      hijo_derecho = right_son(n);
      hijo_izquierdo = left_son(n);
      //Si existen los dos hijos
      if(hijo_derecho<numberOfElements_ && hijo_izquierdo<numberOfElements_){
          //Comprobamos que hijo es el menor
        if(v_[hijo_derecho].getDonations()<v_[hijo_izquierdo].getDonations()){
        hijo_menor = right_son(n);
        }
        else if(v_[hijo_derecho].getDonations()>v_[hijo_izquierdo].getDonations()){
        hijo_menor = left_son(n);
        }
        else if(v_[hijo_derecho].getDonations()==v_[hijo_izquierdo].getDonations()){
          hijo_menor = left_son(n);
        }
        if(v_[hijo_menor].getDonations() < v_[n].getDonations()){
        //Intercambiamos
        std::swap(v_[hijo_menor],v_[n]);
        n = hijo_menor;
        }
        else{
        posicionado = true;
        }
      }
      //si solo existe el hijo derecho
      else if(hijo_derecho<numberOfElements_ && hijo_izquierdo>=numberOfElements_){
        if(v_[hijo_derecho].getDonations() < v_[n].getDonations()){
            std::swap(v_[hijo_derecho],v_[n]);
            n = hijo_derecho;
            posicionado = true;
        }
        else{
            posicionado = true;
        }
      }
      //si solo existe el hijo izquierdo
      else if(hijo_derecho>=numberOfElements_ && hijo_izquierdo<numberOfElements_){
          if(v_[hijo_izquierdo].getDonations() < v_[n].getDonations()){
              std::swap(v_[hijo_izquierdo],v_[n]);
              posicionado = true;
          }
          else{
              posicionado = true;
          }
      }
      else posicionado = true;
    }
  }
}

void Heap::deleteHeap() {
  int n = numberOfElements_;

  for (int i = 0; i < n; i++) {
    deleteTop();
  }
}

void Heap::printDonors(){
  int n = numberOfElements_;

  for (int i = 0; i < n; i++) {
    v_[i].printDonor();
  }

}


void Heap::saveToFile()   {
  std::ofstream f;
  Donor aux;

  f.open("../files/donors.txt");

  if (f.fail()) {
    std::cout << "Error al abrir el fichero";
  }

  for (int i = 0; i < numberOfElements_; i++) {
    aux = v_[i];
    f << aux.getSurname() << ";" << aux.getName() << ";" << aux.getBloodType() <<
    ";" << aux.getRhFactor() << ";" << aux.getDonations() << "\n";
  }
  f.close();
}

void Heap::loadFromFile() {
  std::ifstream f;

  std::string line;
  std::string apellido, name, group, rh_aux, donaciones;
  bool rh;

  f.open("../files/donors.txt");

  if (f.fail()) std::cout << "Error al abrir el fichero";
  else {
    while (getline(f, line)) {
      Donor aux;
      std::stringstream line_aux(line);
      getline(line_aux, apellido,   ';');
      getline(line_aux, name,       ';');
      getline(line_aux, group,      ';');
      getline(line_aux, rh_aux,     ';');
      getline(line_aux, donaciones, ';');

      aux.setName(name);
      aux.setSurname(apellido);
      aux.setBloodType(group);

      if (rh_aux == "1") {
        rh = true;
      }
      else {
        rh = false;
      }
      aux.setRhFactor(rh);
      aux.setDonations(atoi(donaciones.c_str()));
      aux.printDonor();
      insert(aux);
    }
  }
}

#endif // ifndef __HEAP_CPP_
