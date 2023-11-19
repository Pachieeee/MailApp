#pragma once
#pragma warning(disable:4996) //Deshabilita el error _CRT_SECURE_NO_WARNINGS debido al uso de localtime() en ciertos sistemas
#include "Admin.h"
#include "Cuenta.h"
#include "Correo.h"
#include "ListaCuenta.h"
#include "ListaCorreo.h"
#include "CrearCuenta.h"
#include "Inicializador.h"
#include <ctime>


class MailApp
{
private:
	ListaSimple<Cuenta*>* LSCuenta;
	Correo* inbox;
	CrearCuenta<Cuenta*>* creador;
	Inicializador* generar;
public:
	MailApp() {
		LSCuenta = new ListaSimple<Cuenta*>();
		generar = new Inicializador();
		creador = new CrearCuenta<Cuenta*>();
	}
	~MailApp() {
		LSCuenta->~ListaSimple();
		inbox->~Correo();
		delete creador;
		delete generar;
	}

	void bienvenida(tm* tPtr){
		cout << "\n\n\n\t\t\t Fecha: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
		cout << "\t\t\t Hora: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\tBienvenido\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\ta\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\tMailApp\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\tDesarrollado por sebastian(x2) y jhomar\t\t  #" << endl;
		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t ",system("pause");
	}

	void iniciaSesion() {
		string correo, contra;
		int ID;
		cout << "\nIngrese correo: "; cin >> correo; 
		cout << "Ingrese contrasena: "; cin >> contra; 
		ID = LSCuenta->iniciarSesion(correo, contra); 
		if (ID == -1) { 
			cout << "\nLa cuenta no existe\n"; 
			system("pause"); 
			return;
		}
		cout << endl;
		system("pause");
		inbox = new Correo(ID);
		inbox->manejarCorreo(LSCuenta->getNodo(ID)->getID(), LSCuenta->getNodo(ID)->getApellido(), LSCuenta->getNodo(ID)->getCargo());
		inbox->~Correo();
	}

	

	void inicioPantalla(tm* tPtr, int &opt){
		cout << "\n\n\n\t\t\t Fecha: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
		cout << "\t\t\t Hora: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t INICIAR SESION\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t    1) Iniciar sesion\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t    2) Crear una cuenta\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t    3) Salir\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t    0) Administrador\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
		cout << "\t\t\t ##########################################################################################################################" << endl;
		cout << "\t\t\t Opcion: ",cin>>opt,cout<<endl;
	}


	void manejarOpcion(tm* tPtr, int op) {
		switch (op) {
		case 1:
			iniciaSesion();
			break;
		case 2:
			creador->crearCuentaCompleta(LSCuenta, tPtr);
			system("pause");
			break;
		case 3:
			exit(0);
		case 0:
			Admin administrador;
			string adminUsername;
			string adminPassword;
			int optionInAdmin;
			ADMINSCREEN_ONE:administrador.screenAdminOne(tPtr, adminUsername, adminPassword);
			system("cls");
			if(administrador.checkCredentials(adminUsername, adminPassword)){
				ADMINSCREEN_TWO:administrador.screenAdminTwo(tPtr, optionInAdmin);
				system("cls");
				switch (optionInAdmin)
				{
				case 1:
					LSCuenta->mostrarOrdenadoPorHeapSort();
					// LSCuenta->mostrar();
					goto ADMINSCREEN_TWO;
				case 0:
					system("cls");
					break;
				default:
					system("cls");
					cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
					cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;
					cout << "\t\t\t ##########################################################################################################################" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t Enigma System\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t #" << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  #" << endl;
					cout << "\t\t\t  Ingrese una opcion correcta " << endl;
					system("cls");
					goto ADMINSCREEN_ONE;
					break;
				}
			} else
			{
				cout << "\n\n\n\t\t\t Date: " << (tPtr->tm_mday) << "/" << (tPtr->tm_mon) + 1 << "/" << (tPtr->tm_year) + 1900 << endl;
				cout << "\t\t\t Time: " << (tPtr->tm_hour) << ":" << (tPtr->tm_min) << endl;

				cout << "Datos incorrectos" << endl;
				system("cls");
			}
			break;
			cout << endl;
			system("pause");
			break;
		}
	}

	void Run() {
		int inicioSesionOpcion = 0;

		time_t t = time(NULL);
		tm* tPtr = localtime(&t);
		generar->inicializarCuentas(LSCuenta);
		int op;
		bienvenida(tPtr);

		while (true) {
			system("cls");
			INICIOSESIONVISTA:inicioPantalla(tPtr, inicioSesionOpcion);
			system("cls");

			manejarOpcion(tPtr, inicioSesionOpcion);
		};

	}
};