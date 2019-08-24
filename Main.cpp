#include <iostream>
#include <string>
#include <vector>

#include "Liga.cpp"
#include "Jugador.cpp"
#include "Equipo.cpp"
#include "admLigas.cpp"
#include "Partido.cpp"

using namespace std;

int menu();
int menu2();
void printLigas(vector<Liga*>&);
void printEquipos(vector<Equipo*>&);
void printJugadores(vector<Jugador*>&);
void EliminarLiga(vector<Liga*>&);
void EliminarEquipo(vector<Liga*>&,vector<Equipo*>&);
void EliminarJugador(vector<Jugador*>&, vector<Equipo*>&, vector<Liga*>&);

int main(){
	vector <Equipo*> equipos;
	vector <Liga*> ligas;
	vector <Jugador*> jugadores;
	admLigas adm("./ligas.txt");
	
	int opc =0 ;
	int opc2 =0;
	
	Liga* liga;
	Equipo* equipo;
	Jugador* jugador;
	
	int pos;
	
	string nombreL, paisL;
	
	string nombreE, anioE;
	
	string nombreJ, dorsalJ, paisJ;
	int pos2;
	
	Partido* partido;
	Equipo* e1;
	Equipo* e2;
	int pos3;
	
	do{
		switch(opc=menu()){
			case 1:
				do{
					switch (opc2=menu2()){
					case 1:
						cout<<"Nombre de Liga: ";
						cin>>nombreL;
						cout<<"Pais de Liga: ";
						cin>>paisL;
						liga=new Liga(nombreL, paisL);
						ligas.push_back(liga);
						break;
						
					case 2:
						printLigas(ligas);
						EliminarLiga(ligas);						
						printLigas(ligas);
						break;
					}
				}while(opc2!=3);
				break;
				
			case 2://validar
				if(ligas.empty()){
					cout<<"Ingrese Ligas Para Ingresar Equipos"<<endl;
				}
				else{
					do{
						switch (opc2=menu2()){
							case 1:
								cout<<"Nombre Equipo: ";
								cin>>nombreE;
								cout<<"Anio de Fundacion: ";
								cin>>anioE;
								equipo = new Equipo(nombreE, anioE);
								equipos.push_back(equipo);
								printLigas(ligas);
								cout<<"Ingrese Posicion a la cual ingresar equipo: ";
								cin>>pos;
								if(pos<ligas.size()){
									ligas.at(pos)->addEquipo(equipo);
									cout<<"Agregado"<<endl;
								}
								else{
									cout<<"Posicion No Valida"<<endl;
								}
								break;
								
							case 2:
								//printEquipos(equipos);
								EliminarEquipo(ligas,equipos);
								printEquipos(equipos);						
								break;
						}
					}while(opc2!=3);
				}
				break;
				
			case 3://validar
				if(equipos.empty()){
					cout<<"Ingrese Equipos Para Ingresar Jugadores"<<endl;
				}
				else{
					do{
						switch (opc2=menu2()){
							case 1:
								cout<<"Nombre Jugador: ";
								cin>>nombreJ;
								cout<<"Dorsal: ";
								cin>>dorsalJ;
								cout<<"Pais de Origen: ";
								cin>>paisJ;
								jugador = new Jugador(nombreJ, dorsalJ, paisJ);
								jugadores.push_back(jugador);
								printLigas(ligas);
								cout<<"Ingrese Posicion de la liga: ";
								cin>>pos;
								if(pos<ligas.size()){
									ligas.at(pos)->printLiga();
									cout<<"Ingrese Posicion del equipo: ";
									cin>>pos2;
									if(pos2<ligas.at(pos)->getEquipos().size()){
										ligas.at(pos)->getEquipos().at(pos2)->addJugador(jugador);
									}
									else{
										cout<<"Posicion No Valida"<<endl;
									}
								}
								else{
									cout<<"Posicion No Valida"<<endl;
								}
								break;
								
							case 2:
								//printJugadores(jugadores);
								//EliminarJugador(jugadores,equipos,ligas);
								printJugadores(jugadores);
								break;
					}
					}while(opc2!=3);
				}
				break;
				
			case 4:
				cout<<"Ingrese Posicion Liga 1: ";
				cin>>pos;
				if(pos<ligas.size()){
					ligas.at(pos)->printLiga();
					cout<<"Ingrese Posicion Equipo 1: ";
					cin>>pos2;
					e1=ligas.at(pos)->getEquipos().at(pos2);
				}
				pos=0;
				pos2=0;
				cout<<"Ingrese Posicion Liga 2: ";
				cin>>pos;
				if(pos<ligas.size()){
					ligas.at(pos)->printLiga();
					cout<<"Ingrese Posicion Equipo 2: ";
					cin>>pos2;
					e2=ligas.at(pos)->getEquipos().at(pos2);
				}	
				partido = new Partido(e1,e2);
				partido->jugar();	
				break;
				
			case 5:
				break;
				
			case 6:
				break;
				
			case 7:
				break;
				
			case 8:
				ligas.clear();
				if(!ligas.empty()){
					ligas.clear();
				}
				
				equipos.clear();
				if(!equipos.empty()){
					equipos.clear();
				}
				
				equipos.clear();
				if(!equipos.empty()){
					equipos.clear();
				}
				
				cout<<"Saliendo"<<endl;
				break;
		}
	}while(opc!=8);
	return 0;
}

int menu(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Administrar Ligas"<<endl
			<<"2.-Administrar Equipos"<<endl
			<<"3.-Administrar Jugadores"<<endl
			<<"4.-Jugar Partido"<<endl
			<<"5.-Cargar Archivo"<<endl
			<<"6.-Guardar Archivo"<<endl
			<<"7.-Ver Tabla"<<endl
			<<"8.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=8){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

int menu2(){
	int opc=0;
	while (true){
		cout<<"MENU"<<endl
			<<"1.-Agregar Nuevo"<<endl
			<<"2.-Eliminar"<<endl
			<<"3.-Salir"<<endl;
			
		cout<<"Ingrese una opcion: ";
		cin>>opc;
		if(opc>=1 && opc<=3){
			return opc;
		}
		else{
			cout<<"Opcion elegida no es valida"<<endl;
		}
	}
	return 0;
}

void printLigas(vector <Liga*>& l){
	cout<<endl;
	for(int i=0; i<l.size(); i++){
		cout<<"Pos. Ligas: "<<i<<endl;
		l.at(i)->printLiga();
		cout<<endl;
		cout<<endl;
	}
}

void EliminarLiga(vector <Liga*>& ligas){
	int pos;
	cout<<"Ingrese Posicion: ";
	cin>>pos;
	if(pos<ligas.size()){
		ligas.erase(ligas.begin()+pos);
		cout<<"Eliminada"<<endl;
	}
	else{
		cout<<"Posicion No Valida"<<endl;
	}
}

void printEquipos(vector <Equipo*>& l){
	cout<<endl;
	for(int i=0; i<l.size(); i++){
		cout<<"Pos. Equipos: "<<i<<endl;
		l.at(i)->printEquipo();
		cout<<endl;
		cout<<endl;
	}
}

void EliminarEquipo(vector <Liga*>& ligas, vector <Equipo*>& equipo){
	printLigas(ligas);
	int pos, pos2;
	cout<<"Ingrese Posicion Liga: ";
	cin>>pos;
	if(pos<ligas.size()){
		//printEquipos(equipo);
		ligas.at(pos)->printLiga();
		cout<<"Ingrese Posicion a Eliminar: ";
		cin>>pos2;
		if(pos2<ligas.at(pos)->getEquipos().size()){
			for(int i=0; i<equipo.size(); i++){
				if(equipo.at(i)->getNombre() == ligas.at(pos)->getEquipos().at(pos2)->getNombre()){
					equipo.erase(equipo.begin()+i);
				}
			}
			
			ligas.at(pos)->remEquipo(pos2);
		}
	}
	else{
		cout<<"Posicion No Valida"<<endl;
	}
}

void printJugadores(vector <Jugador*>& l){
	cout<<endl;
	for(int i=0; i<l.size(); i++){
		cout<<"Pos. Jugadores: "<<i<<endl;
		for(int j=0; j<l.size(); j++){
			l.at(i)->printJugador();
		}
		cout<<endl;
		cout<<endl;
	}
}

void EliminarJugador(vector <Jugador*> jugadores, vector <Equipo*>& equipo,vector <Liga*>& ligas){
	printLigas(ligas);
	int pos, pos2,pos3;
	cout<<"Ingrese Posicion Liga: ";
	cin>>pos;
	if(pos<ligas.size()){
		//printEquipos(equipo);
		ligas.at(pos)->printLiga();
		cout<<"Ingrese Posicion Equipo: ";
		cin>>pos2;
		if(pos2<ligas.at(pos)->getEquipos().size()){
			ligas.at(pos)->getEquipos().at(pos2)->printEquipo();
			cout<<"Ingrese Posicion Jugador: ";
			cin>>pos3;
			if(pos3<ligas.at(pos)->getEquipos().at(pos2)->getJugadores().size()){
				for(int i=0; i<jugadores.size(); i++){
					for(int j=0; j<ligas.at(pos)->getEquipos().at(pos2)->getJugadores().size(); j++){
						if(jugadores.at(i)->getNombre() == ligas.at(pos)->getEquipos().at(pos2)->getJugadores().at(j)->getNombre()){
							jugadores.erase(jugadores.begin()+i);
						}
					}
				}
				ligas.at(pos)->getEquipos().at(pos2)->remJugador(pos3);
			}
		}
	}
	else{
		cout<<"Posicion No Valida"<<endl;
	}
}

