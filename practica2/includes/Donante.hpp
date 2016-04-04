#ifndef __DONANTE__
#define __DONANTE__
#include "librerias.hpp"
#include "DonanteInterfaz.hpp"
namespace ed{
  class Donante: public DonanteInterfaz{
  private:
    std::string Name;
    std::string SecondName;
    std::string Group;
    bool RH;

  public:


    //Constructors
    Donante(){
      Name = "";
      SecondName = "";
      Group = "";
      RH = "";
    }

    Donante(std::string Name, std::string SecondName, std::string Group, bool RH){
      this->Name = Name;
      this->SecondName = SecondName;
      this->Group = Group;
      this->RH = RH;
    }

    Donante(const Donante &don){
      this->Name = don.Name;
      this->SecondName = don.SecondName;
      this->Group = don.Group;
      this->RH = don.RH;
    }


    //Getters

    std::string getName()const{
      return Name;
    }

    std::string getSecondName()const{
      return SecondName;
    }

    std::string getGroup()const{
      return Group;
    }

    bool getRH()const{
      return RH;
    }

    //Setters

    void setName(const std::string& Name){
      this->Name = Name;
    }

    void setSecondName(const std::string& SecondName){
      this->SecondName = SecondName;
    }

    void setGroup(const std::string& Group){
      this->Group = Group;
    }

    void setRH(const bool& RH){
      this->RH = RH;
    }

    //read and write
    void writeDonante(){
        LUGAR(6,10);
        std::cout<<"Nombre:"<<this->getName();
        LUGAR(7,10);
        std::cout<<"Second Name:"<<this->getSecondName();
        LUGAR(8,10);

        std::cout<<"Group:"<<this->getGroup();
        LUGAR(9,10);
        if(this->RH){
          std::cout<<"RH: Positivo";
        }
        else {
          std::cout<<"RH: Negativo";
        }
    }

    void readDonante(){
      char rh;
      BORRAR;
      LUGAR(6,10);
      std::cout<<"Name:";
      getchar();
      getline(std::cin,Name);
      LUGAR(7,10);
      std::cout<<"Second Name:";
      getline(std::cin,SecondName);
      LUGAR(8,10);
      std::cout<<"Group:";
      getline(std::cin,Group);
      LUGAR(9,10);
      std::cout<<"RH(P=Positivo,N=Negativo):";
      std::cin>>rh;
      if(rh == 'P' || rh == 'p'){
        this->RH = true;
      }
      else this->RH = false;

    }

    //Igual que readDonante pero comprobando los campos vacios
    // para no modificarlos
    void modify(){
      std::string aux;
      BORRAR;
      LUGAR(6,10);
      std::cout<<"Deja el campo en blanco para no modificar";
      LUGAR(7,10);
      std::cout<<"Name:";
      getline(std::cin,aux);
      if(!aux.empty()){
        this->Name = aux;
      }
      LUGAR(8,10);
      std::cout<<"Second Name:";
      getline(std::cin,aux, '\n');
      if(!aux.empty()){
        this->SecondName= aux;
      }
      LUGAR(9,10);
      std::cout<<"Group:";
      getline(std::cin,aux);
      if(!aux.empty()){
        this->Group=aux;
      }
      LUGAR(10,10);
      std::cout<<"RH(P=Positivo,N=Negativo):";
      getline(std::cin,aux);
      if(!aux.empty()){
      if(aux == "P" || aux == "p"){
        this->RH = true;
      }
      else this->RH = false;

      }
    }

    //Overloaded operators

    Donante& operator=(Donante don){
      this->Name = don.Name;
      this->SecondName = don.SecondName;
      this->Group = don.Group;
      this->RH = don.RH;
      return *this;
    }

    bool operator==(const Donante& don1){
      bool result;
      if(don1.getName()==this->getName() && don1.getSecondName()==this->getSecondName()){
        result = true;
      }
      else result = false;
      return result;
    }


    //Perfe
    bool operator<=(const Donante& don1){
      bool result;
      if(this->getSecondName().compare(don1.getSecondName())<0){
        result = false;
      }
      else if(this->getSecondName().compare(don1.getSecondName())>0){
        result = true;
      }
      else{
        result = true;
      }
      return result;
    }
    bool operator>=(const Donante& don1){
      bool result;
      if(this->getSecondName().compare(don1.getSecondName())<0){
        result = true;
      }
      else if(this->getSecondName().compare(don1.getSecondName())>0){
        result = false;
      }
      else{
        result = true;
      }
      return result;
    }

    //friends function
    friend std::istream &operator>>(std::istream &stream, Donante &d){
      return stream;
    }

    friend std::ostream &operator<<(std::ostream &stream, Donante const &d){
      BORRAR;
      stream<<LUGAR(6,10);
      stream<<"Nombre: "<<d.getName();
      stream<<LUGAR(7,10);
      stream<<"Second Name: "<<d.getSecondName();
      LUGAR(8,10);
      stream<<"Group: "<<d.getGroup();
      LUGAR(9,10);
      stream<<"RH: "<<d.getRH();
      return stream;
    }

  };
}


#endif
