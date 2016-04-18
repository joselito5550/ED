/*!
	\file Donante.hpp
	\brief Clase Donante, hereda de DonanteInterfaz
	\author Jose Manuel Marquez Matarin
*/

#ifndef __DONANTE__
#define __DONANTE__
#include "librerias.hpp"
#include "DonanteInterfaz.hpp"
/*!
	\brief Espacio de nombres ED
*/
namespace ed{
/*!
	\brief Clase Donante
*/
  class Donante: public DonanteInterfaz{
//! \name Atributos privados de la clase Donante
  private:
    std::string Name;
    std::string SecondName;
    std::string Group;
    bool RH;
    int donaciones;
//! \name Funciones publicas de la Clase Donante
  public:


    //Constructors
//! \name Constructores
    Donante(){
      Name = "";
      SecondName = "";
      Group = "";
      RH = "";
      donaciones = 0;
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
//! \name Observadores

	/*!
		\brief Devuelve el nombre del Donante
		\return String, nombre del donante
	*/
    std::string getName()const{
      return Name;
    }

	/*!
		\brief Devuelve el apellido del Donante
		\return String, apellido del donante
	*/
    std::string getSecondName()const{
      return SecondName;
    }
	/*!
		\brief Devuelve el grupo del Donante
		\return String, grupo del donante
	*/
    std::string getGroup()const{
      return Group;
    }
	/*!
		\brief Devuelve el factor RH del Donante
		\return Bool, factor RH del donante
	*/
    bool getRH()const{
      return RH;
    }

    /*!
      \brief Devuelve el numero de donaciones realizadas por el donante
      \return int
    */
    int getDonaciones()const{
      return donaciones;
    }

    //Setters
//! \name Modificadores
	/*!
		\brief Establece como nombre el string pasado por parametro
		\param String Name
		\post El donante debera de tener el nombre de la variable Name
	*/
    void setName(const std::string& Name){
      this->Name = Name;
    }

	/*!
		\brief Establece como apellido el string pasado por parametro
		\param String SecondName
		\post El donante debera de tener el apellido de la variable Name
	*/
    void setSecondName(const std::string& SecondName){
      this->SecondName = SecondName;
    }

	/*!
		\brief Establece como grupo Sanguineo el string pasado por parametro
		\param String Group
		\post El donante debera de tener el grupo de la variable Group

	*/
    void setGroup(const std::string& Group){
      this->Group = Group;
    }

	/*!
		\brief Establece como apellido el string pasado por parametro
		\param String SecondName
		\post El donante debera de tener el apellido de la variable SecondName

	*/
    void setRH(const bool& RH){
      this->RH = RH;
    }

    /*
      \brief Establece el numero de donaciones realizadas por el donante
      \param int donaciones
      \post El donante debera de tener las donaciones pasadas por parametro
  */
    void setDonaciones(const int &donacioens){
      this->donaciones = donaciones;
    }

//! \name Otras funciones de la clase
    //read and write

	/*!
		\brief Escribe por pantalla la informacion del Donante
	*/
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
	/*!
		\brief Lee por pantalla la informacion del Donante
	*/
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
	/*!
		\brief Modificar los datos de un donante
	*/
    void modify(){
      std::string aux;
      BORRAR;
      LUGAR(6,10);
      std::cout<<"Deja el campo en blanco para no modificar";
      LUGAR(7,10);
      getchar();
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

//! \name Sobrecarga de operadores

	/*!
		\brief Sobrecarga del operador =
		\param Donante al que se iguala
		\post Deberan de ser iguales
	*/
    Donante& operator=(Donante don){
      this->Name = don.Name;
      this->SecondName = don.SecondName;
      this->Group = don.Group;
      this->RH = don.RH;
      return *this;
    }

	/*!
		\brief Devuelve true si ambos donantes son iguales
		\param Donante don1
	*/
    bool operator==(const Donante& don1){
      bool result;
      if(don1.getName()==this->getName() && don1.getSecondName()==this->getSecondName()){
        result = true;
      }
      else result = false;
      return result;
    }


    //Perfe
	/*!
		\brief Operador <=, nos sera util para el ordenado alfabetico
		\param Donante don1
	*/
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

	/*!
		\brief Operador >=, nos sera util para el ordenado en la lista
		\param Donante don1
	*/
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

//! \name Funciones amigas

    //friends function
	/*!
		\brief Sobrecarga del operador >>
		\param Stream, Donante d
	*/
    friend std::istream &operator>>(std::istream &stream, Donante &d){
      std::cout << "Introduce los siguientes datos del donante\n";
	  std::cout << "Nombre:";
      stream >> d.Name;
      stream.ignore();
	  std::cout << "Apellidos:";
      stream >> d.SecondName;
      stream.ignore();

	  std::cout << "Grupo:";
      stream >> d.Group;
      stream.ignore();

	  std::cout << "RH:";
      stream >> d.RH;
      stream.ignore();

  	  return stream;
    }

	/*!
		\brief Sobrecarga del operador <<
		\param stream, Donante d
	*/
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
