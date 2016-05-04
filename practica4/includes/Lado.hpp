#include "librerias.hpp"

namespace ed{
	class Lado{
	private:
		Vertice _first;
		Vertice _second;
		double _data;		//Distancia
	public:
		//Observadores
		
		const double getData(){
			return _data;
		}
		const Vertice getFirst(){
			return _first;
		}
		const Vertice getSecond(){
			return _second;
		}
        
        const bool has(Vertice &v){
            return (v == getFirst() || v == getSecond());
        }
        
        const Vertice other(Vertice &v){
            if(v == getFirst()){
                return getFirst();
            }
            else if(v == getSecond()){
                return getSecond();
            }
        }
		//Modificadores
		
		void setData(double &data){
			this->_data = data;
		}

		void setFirst(Vertice &v){
			this->_first = v;
		}

		void setSecond(Vertice &v){
			this->_second = v;
		}

	};
}