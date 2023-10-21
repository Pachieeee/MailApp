#pragma once
#include "Bandeja.h"
#include "Busqueda.h"
class Correo {
private:
	int usuario; //a
	Bandeja* inbox;
	Busqueda* busqueda;
public:
	Correo() {
	}
	Correo(int ID) {
		inbox = new Bandeja(ID);
		busqueda = new Busqueda(ID);
	}
	~Correo() {
		inbox->~Bandeja();
		busqueda->~Busqueda();
	}

	void manejarOpc(int op) {
		switch (op) {
		case 1:
			system("cls");
			inbox->mostrarBandeja("P");
			break;
		case 2:
			system("cls");
			inbox->mostrarBandeja("F");
			break;
		case 3:
			system("cls");
			inbox->mostrarBandeja("S");
			break;
		case 4:
			system("cls");
			inbox->mostrarBandeja("E");
			break;
		case 5:
			system("cls");
			inbox->mostrarBandeja("T");
			break;
		case 6:
			system("cls");;
			inbox->ordenarPorInicialAutor();
			break;
		case 7:
			system("cls");
			busqueda->menuBusqueda();
			break;
		case 8:
			break;
		default:
			cout << "Opcion erronea.";
			break;
		}
	}

	int menuCliente(string nombre) {
		int op;
		system("cls");
		cout << "Bienvenido, " << nombre;
		cout << "\n1. Ver inbox principal";
		cout << "\n2. Ver inbox fijado";
		cout << "\n3. Ver inbox spam";
		cout << "\n4. Ver inbox enviado";
		cout << "\n5. Ver inbox papelera";
		cout << "\n6. Ordenar principal por autor";
		cout << "\n7. Buscar mensaje";
		cout << "\n8. Cerrar sesion";
		cout << "\nOpcion: "; cin >> op;
		return op;
	}

	void manejarCorreo(string nombre) {
		int op;
		inbox->iniciarBandeja();
		do {
			op = menuCliente(nombre);
			manejarOpc(op);
			system("pause");
		} while (op > 0 && op < 8);
	}
};