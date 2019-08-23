#include <iostream>
#include <string>
#include "Equipo.cpp"

#ifndef LIGA_CPP
#define LIGA_CPP
using namespace std;

class Liga{
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
			return nombre;
		}
		
		void setNombre(string nombre){
			this->nombre.assign(nombre);
		}
		
		string getDorsal(){
			return dorsal;
		}
		
		void setDorsal(string dorsal){
			this->dorsal.assign(dorsal);
		}
		
		string getPais_origen(){
			return pais_origen;
		}
		
		void setPais_origen(string pais_origen){
			this->pais_origen.assign(pais_origen);
		}
};

#endif
