#include <iostream>
#include <string>
#include <stdlib.h>
#include "Equipo.cpp"

#ifndef PARTIDO_CPP
#define PARTIDO_CPP
using namespace std;

class Partido{
	protected:
		Equipo* equipo1;
		Equipo *equipo2;
		
	public:
		Partido(){
		}
		
		Partido(Equipo* _equipo1, Equipo* _equipo2){
			equipo1=_equipo1;
			equipo2=_equipo2;
		}
		
		jugar(){
			int gol1, gol2;
			
			gol1=0+rand()%20;
			gol2=0+rand()%20;
			
			equipo1->setGoles(gol1);
			equipo2->setGoles(gol2);
			equipo1->setP_j(equipo1->getP_j()+1);
			equipo2->setP_j(equipo2->getP_j()+1);
			
			if(gol1>gol2){
				cout<<"Gana equipo 1 "<<equipo1->getNombre()<<endl;
				equipo1->setP_g(equipo1->getP_g()+1);
				equipo2->setP_p(equipo2->getP_p()+1);
				equipo1->setG_f(equipo1->getG_f()+gol1);
				equipo2->setG_c(equipo2->getG_c()+gol1);
			}
			
			if(gol1<gol2){
				cout<<"Gana equipo 2 "<<equipo2->getNombre()<<endl;
				equipo2->setP_g(equipo2->getP_g()+1);
				equipo1->setP_p(equipo1->getP_p()+1);
				equipo2->setG_f(equipo2->getG_f()+gol2);
				equipo1->setG_c(equipo1->getG_c()+gol2);
			}
			
			if(gol1==gol2){
				cout<<"Empate"<<endl;
				equipo1->setP_e(equipo1->getP_e()+1);
				equipo2->setP_e(equipo2->getP_e()+1);
			}
			
		}
		
		
};

#endif
