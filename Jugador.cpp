#include <iostream>
#include <string>

#ifndef JUGADOR_CPP
#define JUGADOR_CPP
using namespace std;

class Jugador{
	protected:
		string nombre, dorsal, pais_origen;
		
	public:
		Jugador(){
		}
		
		Jugador(string nombre, string dorsal, string pais_origen){
			this->nombre=nombre;
			this->dorsal=dorsal;
			this->pais_origen=pais_origen;
		}
		
		string getNombre(){
			return this->nombre;
		}
		
		void setNombre(string nombre){
			this->nombre.assign(nombre);
		}
		
		string getDorsal(){
			return this->dorsal;
		}
		
		void setDorsal(string dorsal){
			this->dorsal.assign(dorsal);
		}
		
		string getPais_origen(){
			return this->pais_origen;
		}
		
		void setPais_origen(string pais_origen){
			this->pais_origen.assign(pais_origen);
		}
		
		~Jugador(){
		}
};

#endif
