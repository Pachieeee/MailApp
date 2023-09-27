#pragma once

#include "ListaCorreo.h"
#include "Contenido.h"
#include "Inicializador.h"
class Busqueda
{
private:
	ListaDoble<Contenido*>* busqueda;
	Inicializador iniT;
	int idUsuario;
	int filtro;
	string campoBusqueda;
public:
	Busqueda(int id) {
		busqueda = new ListaDoble<Contenido*>();
		this->idUsuario = id;
	}
	~Busqueda() {
		busqueda->~ListaDoble();
	}

	void iniciarContenidoBusqueda() {
		cout << "\nCargando resultados de busqueda...";
		string direccion = "Datos/" + to_string(idUsuario) + ".txt";
		iniT.inicializarBusqueda(busqueda, direccion, campoBusqueda, filtro);
		cout << "\nResultados de busqueda cargados!\n";
		system("pause>null");
	}

	void mostrarContenidoBusqueda() {
		busqueda->mostrar();
		delete busqueda;
		busqueda = new ListaDoble<Contenido*>();
		system("pause>null");
	}

	void busquedaPorAutor() {
		cout << "\nIngrese el nombre del autor: ";
		cin >> campoBusqueda;
		iniciarContenidoBusqueda();
		mostrarContenidoBusqueda();
	}

	void busquedaPorCorreo() {
		cout << "\nIngrese la direccion de correo: ";
		cin >> campoBusqueda;
		iniciarContenidoBusqueda();
		mostrarContenidoBusqueda();
	}

	void menuBusqueda() {
		do
		{
			system("cls");
			cout << "\nBusqueda\n";
			cout << "\n1. Buscar mensajes por autor";
			cout << "\n2. Buscar mensajes por direccion de correo";
			cout << "\n3. Cancelar\n";
			cout << "\nOpcion: "; cin >> filtro;
			if (filtro == 1) busquedaPorAutor();
			if (filtro == 2) busquedaPorCorreo();
		} while (filtro != 3);
	}
};