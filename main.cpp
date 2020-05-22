#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <conio.h>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include "Persona.cpp"
using namespace std;



/* run this program using the console pauser or add your own getch, system("pause") or input loop */
string Encriptar(string);
int menu(){
	int retValue=0;
	while(retValue < 1 || retValue > 3){
		cout<<"***CLI-MESSENGER-SERVICE***"<<endl
			<<"  1.- Registrarse"<<endl
			<<"  2.- Ingresar"<<endl
			<<"  3.- Salir"<<endl
			<<"-> Que opcion desea ver: ";
			
			cin>>retValue;
			
			if(retValue >= 1 && retValue <= 3){
				break;
			}else{
				cout<<endl<<"Opcion ingresada incorrecta, elija nuevamente"<<endl;
			}
			
			
	}//end while
	
	return retValue;
}//fin metodo de menu

vector <Persona*> personas; 

int main(int argc, char** argv) {
	int  opcion = menu();
	int seguir = 1;
	
	while(seguir == 1){
		switch(opcion){
			case 1:{//Registrarse
				string nombre, apellido, contra;
				int llave;
				cout<<endl<<"Ingrese su nombre: ";
				cin>>nombre;
				
				cout<<endl<<"Ingrese su apellido: ";
				cin>>apellido;
				
				cout<<"Ingrese su contraseña: ";
				cin>>contra;
				
				llave = rand()%16;
				
				personas.push_back(new Persona(llave, nombre, apellido, contra));
				
				cout<<"Su usuario es: ";
				cout<<endl<<"	Nombre: "<<nombre;
				cout<<endl<<"	Apellido: "<<apellido;
				cout<<endl<<"	Contraseña: "<<contra;
				
				
				break;
			}//fin case 1
			
			case 2:{//Log in
				string nombre, contra;
				int llave;
				
				cout<<endl<<"****LOG IN****";
				cout<<endl<<"Ingrese su nombre: ";
				cin>> nombre;
				
				int Valida_nom=0;
				
				while(Valida_nom == 0){
					for(int i=0; i < personas.size(); i++){
						if( nombre == personas[i]->getName() ){
							Valida_nom = 1;
						}
					}
					if(Valida_nom == 0){
						cout<<endl<<"El nombre ingresado no existe, vuelva a intentar ingresar su nombre: ";
						cin>> nombre;
					}
				}
				
				cout<<endl<<"Ingrese su contraseña: ";
				cin>> contra;
				
				int Valida_contra=0;
				
				while(Valida_contra == 0){
					for(int i=0; i < personas.size(); i++){
						if( contra == personas[i]->getPassword() ){
							Valida_contra = 1;
						}
					}
					if(Valida_contra == 0){
						cout<<endl<<"La contraseña ingresada es incorrecta, vuelva a intentar ingresar su contraseña: ";
						cin>> contra;
					}
				}
				
				bool seguir_in = true;
				int sub_menu;
				while(seguir_in){//sub menu 2
					cout<<"***Bienvenida: "<<nombre<<"***"<<endl
						<<"  1.- Enviar mensaje"<<endl
						<<"  2.- Ver mensajes"<<endl
						<<"  3.- Ver mi llame"<<endl
						<<"  4.- salir"<<endl
						<<"-> Que opcion desea ver: ";
					cin>>sub_menu;
					while(sub_menu < 1 || sub_menu > 4){
						cout<<"***Opcion anterior ingresa incorrecta, "<<nombre<<" intente de nuevo***"<<endl
							<<"  1.- Enviar mensaje"<<endl
							<<"  2.- Ver mensajes"<<endl
							<<"  3.- Ver mi llave"<<endl
							<<"  4.- salir"<<endl
							<<"-> Que opcion desea ver: ";
						cin>>sub_menu;
					}
					
					switch(sub_menu){
						case 1:{//Enviar mensaje
							int destinatario;
							string mensaje;
							
							cout<<endl<<"A quien le quiere enviar el mensaje: "<<endl;
							for(int i = 0; i < personas.size(); i++){
								cout<<i+1<<") "<<personas[i]->getName()<<endl;
							}
							cin>>destinatario;
							destinatario--;
							personas[destinatario]->setSender(nombre);
							
							cout<<"escriba el mensaje que desea enviar: ";
							cin>>mensaje;
							
							string mensajeEncriptado;
							
							personas[destinatario]->setMessage(mensajeEncriptado);
							break;
						}//fin case 1
						
						case 2:{//Ver mensajes
							
							break;
						}//fin case 2
						
						case 3:{//Ver mi llave
							
							break;
						}//fin case 2
						
						case 4:{
							cout<<endl<<"Gracias por entrar al sistema."<<endl;
							seguir=0;
							break;
						}//fin case 3
					}//fin del switch
				}//fin while del sub menu
				
				break;
			}//fin case 2
			
			case 3:{
				cout<<endl<<"Gracias por entrar al sistema."<<endl;
				seguir=0;
				break;
			}//fin case 3
		}//fin del switch
	}//fin del while
	
	return 0;
}//fin del main

string Encriptar(string mensaje){
	string mensaje_encriptado;
	
	return mensaje_encriptado;
	
}
