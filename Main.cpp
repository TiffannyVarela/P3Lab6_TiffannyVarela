#include <iostream>
#include <string>
#include <vector>

#include "Liga.cpp"
#include "Equipo.cpp"
#include "Jugador.cpp"

using namespace std;

int menu();
int menu2();
void printLigas(vector<Liga*>&);
void printEquipos(vector<Equipo*>&);
void printJugadores(vector<Jugador*>&);
void EliminarLiga(vector<Liga*>&);

int main(){
	vector <Equipo*> equipos;
	vector <Liga*> ligas;
	vector <Jugador*> jugadores;
	
	int opc =0 ;
	int opc2 =0;
	
	Liga* liga;
	Equipo* equipo;
	Jugador* jugador;
	
	string nombreL, paisL;
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
					switch (opc2=menu2()){
					case 1:
						break;
						
					case 2:
						break;
					}
				}
				break;
				
			case 3://validar
				if(equipos.empty()){
					cout<<"Ingrese Equipos Para Ingresar Jugadores"<<endl;
				}
				else{
					switch (opc2=menu2()){
					case 1:
						break;
						
					case 2:
						break;
					}
				}
				break;
				
			case 4:
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
	for(int i=0; i<l.size(); i++){
		cout<<"Pos: "<<i<<endl;
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
