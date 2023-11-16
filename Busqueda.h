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
		cout << "Buscar: "; cin >> campoBusqueda;
		cout << "\nCargando resultados de busqueda...";
		string direccion = "BD/" + to_string(idUsuario) + ".csv";
		iniT.inicializarBusqueda(busqueda, direccion, campoBusqueda, filtro);
		cout << "\nResultados de busqueda cargados!\n";
		busqueda->inOrden();
		delete busqueda;
		busqueda = new ArbolAVL<Contenido*>(imprimir);
		//busqueda->mostrar();
		//delete busqueda;
		system("pause>null");
	}

	void menuBusqueda() {
		int filtro;
		do
		{
			system("cls");
			cout << "\nBusqueda\n";
			cout << "\n1. Buscar mensajes por autor";
			cout << "\n2. Buscar mensajes por direccion de correo";
			cout << "\n3. Buscar mensajes por asunto";
			cout << "\n4. Buscar mensajes por fecha";
			cout << "\n0. Cancelar\n";
			cout << "\nOpcion: "; cin >> filtro;
			if (!filtro) break;
			busquedaPorFiltro(filtro);
		} while (true);
	}
};