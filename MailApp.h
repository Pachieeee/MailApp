#pragma once
#include "Cuenta.h"
#include "Correo.h"
#include "ListaCuenta.h"
#include "ListaCorreo.h"
#include "CrearCuenta.h"
#include "Inicializador.h"

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

	void ingresar() {
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
		inbox->manejarCorreo(LSCuenta->getNodo(ID)->getNombre());
		inbox->~Correo();
	}

	void manejarOpcion(int op) {
		switch (op) {
		case 1:
			ingresar();
			break;
		case 2:
			creador->crearCuentaCompleta(LSCuenta);
			system("pause");
			break;
		case 3:
			exit(0);
		case 0:
			LSCuenta->mostrar();
			system("pause");
			break;
		}
	}

	int Menu() {
		int opcion;
		do {
			system("cls");
			cout << "||===BIENVENIDO A MAILAPP===||\n";
			cout << "\n1. Iniciar sesion";
			cout << "\n2. Crear cuenta de cliente";
			cout << "\n3. Salir";
			cout << "\n0. DEBUG: Mostrar cuentas";
			cout << "\nOpcion: "; cin >> opcion;
		} while (opcion < 0 || opcion > 3);
		return opcion;
	}

	void Run() {
		generar->inicializarCuentas(LSCuenta);
		int op;

		do {
			system("cls");
			op = Menu();
			manejarOpcion(op);
		} while (true);
	}
};