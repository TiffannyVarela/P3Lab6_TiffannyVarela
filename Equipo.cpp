#include <iostream>
#include <string>
#include "Jugador.cpp"
#include <vector>

#ifndef EQUIPO_CPP
#define EQUIPO_CPP
using namespace std;

class Equipo{
	protected:
		string nombre,anio;
		int p_j, p_g, p_p, p_e, g_f, g_c, d_g, goles, puntos;
		vector <Jugador*> jugadores;
		
	public:
		Equipo(){
		}
		
		Equipo(string nombre, string anio){
			this->nombre=nombre;
			this->anio=anio;
			p_j=0;//partidos jugados
			p_g=0;//partidos ganados
			p_p=0;//partidos perdidos
			p_e=0;//partidos empatados
			g_f=0;//goles a favor
			g_c=0;//goles en contra
			d_g=0;//diferencia de goles
			//goles=0;
			puntos=0;
		}
		
		string getNombre(){
			return this->nombre;
		}
		
		void setNombre(string nombre){
			this->nombre.assign(nombre);
		}
		
		string getAnio(){
			return this->anio;
		}
		
		void setAnio(string anio){
			this->anio=anio;
		}
		
		int getP_j(){
			return this->p_j;
		}
		
		void setP_j(int p_j){
			this->p_j=p_j;
		}
		
		int getP_g(){
			return this->p_g;
		}
		
		void setP_g(int p_g){
			this->p_g=p_g;
		}
		
		int getP_p(){
			return this->p_p;
		}
		
		void setP_p(int p_p){
			this->p_p=p_p;
		}
		
		int getP_e(){
			return this->p_e;
		}
		
		void setP_e(int p_e){
			this->p_e=p_e;
		}
		
		int getG_f(){
			return this->g_f;
		}
		
		void setG_f(int g_f){
			this->g_f=g_f;
		}
		
		int getG_c(){
			return this->g_c;
		}
		
		void setG_c(int g_c){
			this->g_c=g_c;
		}
		
		int getD_g(){
			return this->d_g;
		}
		
		void setD_g(int d_g){
			this->d_g=d_g;
		}
		
	/*	int getGoles(){
			return this->goles;
		}
		
		void setGoles(int goles){
			this->goles=goles;
		}
	*/
		int getPuntos(){
			return this->puntos;
		}
		
		void setPuntos(int puntos){
			this->puntos=puntos;
		}
		
		vector <Jugador*> getJugadores(){
			return this->jugadores;
		}
		
		void addJugador (Jugador* jugador){
			jugadores.push_back(jugador);
		}
		
		void remJugador(int p){
			jugadores.erase(jugadores.begin()+p);
		}
		
		void printEquipo(){
			cout<<"Nombre: "<<nombre<<endl;
			cout<<"Anio: "<<anio<<endl;
			for(int i=0; i<jugadores.size(); i++){
				cout<<"Num: "<<i<<endl;
				cout<<jugadores.at(i)->getNombre();
			}
		}
		
		~Equipo(){
		}
};

#endif
