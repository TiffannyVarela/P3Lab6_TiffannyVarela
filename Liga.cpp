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
		
		void addEquipo(Equipo* equipo){
			equipos.push_back(equipo);
		}
		
		void remEquipo(int p){
			equipos.erase(equipos.begin()+p);
		}
		
		void printLiga(){
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Pais: "<<pais<<endl;
			for(int i=0; i<equipos.size(); i++){
				cout<<"Num: "<<i<<endl;
				cout<<equipos.at(i)->getNombre();
				cout<<endl;
			}
		}
		
		~Liga(){
		}
};

#endif
