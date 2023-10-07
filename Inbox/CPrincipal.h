#pragma once

#include "../ListaCorreo.h"
#include "../Contenido.h"
#include "../Inicializador.h"
class CPrincipal
{
private:
	ListaDoble<Contenido*>* principal;
	Inicializador iniP;
	int idUsuario;
public:
	CPrincipal(int id) {
		principal = new ListaDoble<Contenido*>();
		this->idUsuario = id;
	}
	~CPrincipal() {
		principal->~ListaDoble();
	}

	void iniciarContenidoPrincipal() {
		cout << "\nCargando correo principal...";
		string direccion = "Datos/" + to_string(idUsuario) + ".txt";
		iniP.inicializarCorreo(principal, direccion, "P");
		cout << "Correo principal cargado!";
	}

	void ordenarPorInicialAutor() {
		principal->quickSort();
		cout << "Correo organizado!";
	}

	void mostrarContenidoPrincipal() {
		principal->mostrar();
	}
};