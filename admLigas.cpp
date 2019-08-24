#include<iostream> 
#include <string> 
#include <fstream>
#include <stdlib.h>
#include "Jugador.cpp"
#include "Equipo.cpp"
#include "Liga.cpp"
#include<string.h>
#include <vector>
#include <bits/stdc++.h>

#ifndef ADMLIGAS_CPP
#define ADMLIGAS_CPP

using namespace std;

class admLigas{
	private: 
		string ruta;
		vector<Liga*> ligas;
		
	public:
		admLigas(string ruta){
			this->ruta=ruta;
		}
		
		string getRuta(){
			return ruta;
		}
		
		void addLiga(Liga* l){
			ligas.push_back(l);
		}
		
		vector <Liga*> getLigas(){
			return this->ligas;
		}
		
		void remLiga(int p){
			ligas.erase(ligas.begin()+p);
		}
		
		int getTam(){
			ligas.size();
		}
		
		~admLigas(){
		}
		
		
		void Escribir(){
			ofstream escribir;
			escribir.open(ruta.c_str());
			for(int i=0; i<ligas.size(); i++){//inicio for ligas
				escribir<<"$"<<ligas.at(i)->getNombre()<<":"<<ligas.at(i)->getPais()<<endl;
						for(int j=0; j<ligas.at(i)->getEquipos().size(); j++){//inicio for de equipos de liga
							escribir<<ligas.at(i)->getEquipos()[j]->getNombre()<<":"
									<<ligas.at(i)->getEquipos()[j]->getAnio()<<"{";
									for(int k=0; k<ligas.at(i)->getEquipos()[j]->getJugadores().size(); k++){//inicio for de jugadores de equipo
										escribir<<ligas.at(i)->getEquipos()[j]->getJugadores()[k]->getNombre()<<"|"
												<<ligas.at(i)->getEquipos()[j]->getJugadores()[k]->getDorsal()<<"|"
												<<ligas.at(i)->getEquipos()[j]->getJugadores()[k]->getPais_origen()<<";";
									}//fin for de jugadores de equipo
									escribir<<"}"<<endl;
						}//fin for de equipos de liga
						
			}//fin for ligas
			escribir.close();
		}
		
			
};
#endif

