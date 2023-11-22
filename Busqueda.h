#pragma once
#include "ListaCorreo.h"
#include "ArbolBusqueda.h"
#include "Contenido.h"
#include "Inicializador.h"

void imprimir(Contenido* c) {
	c->getContenido();
}

class Busqueda
{
private:
	//ListaDoble<Contenido*>* busqueda;
	Inicializador iniT;
	int idUsuario;
	string campoBusqueda;
	ArbolAVL<Contenido*>* busqueda;

public:
	Busqueda(int id) {
		//busqueda = new ListaDoble<Contenido*>();
		busqueda = new ArbolAVL<Contenido*>(imprimir);
		this->idUsuario = id;
	}

	~Busqueda() {
		busqueda->~ArbolAVL();
		//busqueda->~ListaDoble();
	}

	void busquedaPorFiltro(int filtro) {
		if (filtro == 1 || filtro == 2) {
			cout << "Buscar: "; cin >> campoBusqueda;
		}
		string direccion = "BD/" + to_string(idUsuario) + ".csv";
		iniT.inicializarBusqueda(busqueda, idUsuario, campoBusqueda, filtro);
		cout << "\nCargando resultados de busqueda...";
		cout << "\nResultados de busqueda cargados!\n";
		busqueda->inOrden();
		system("pause>null");
		delete busqueda;
		busqueda = new ArbolAVL<Contenido*>(imprimir);
	}

	void menuBusqueda() {
		int filtro;
		do
		{
			system("cls");
			cout << "\nBusqueda\n";
			cout << "\n1. Buscar mensajes por direccion de correo";
			cout << "\n2. Buscar mensajes por asunto";
			cout << "\n3. Buscar mensajes por intervalo de fechas";
			cout << "\n0. Cancelar\n";
			cout << "\nOpcion: "; cin >> filtro;
			busquedaPorFiltro(filtro);
			break;
		} while (true);
	}
};