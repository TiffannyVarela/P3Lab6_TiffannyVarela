#include <iostream>
#include <string>
#include "Equipo.cpp"

#ifndef LIGA_CPP
#define LIGA_CPP
using namespace std;

class Liga{
	protected:
		string nombre, pais;
		vector <Equipo*> equipos;
		
	public:
		Liga(){
		}
		
		Liga(string nombre, string pais){
			this->nombre=nombre;
			this->pais=pais;
		}
		
		string getNombre(){
			return nombre;
		}
		
		void setNombre(string nombre){
			this->nombre.assign(nombre);
		}
		
		string getPais(){
			return this->pais;
		}
		
		void setPais(string pais){
			this->pais.assign(pais);
		}
		
		vector <Equipo*> getEquipos(){
			return this->equipos;
		}
		
		void setEquipo(Equipo* equipo){
			equipos.push_back(equipo);
		}
		
		void remEquipo(int p){
			equipos.erase(equipos.begin()+p);
		}
};

#endif
