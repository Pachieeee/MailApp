#pragma once

#include "../ListaCorreo.h"
#include "../Contenido.h"
#include "../Inicializador.h"
class CPapelera
{
private:
	ListaDoble<Contenido*>* papelera;
	Inicializador iniT;
	int idUsuario;
public:
	CPapelera(int id) {
		papelera = new ListaDoble<Contenido*>();
		this->idUsuario = id;
	}
	~CPapelera() {
		papelera->~ListaDoble();
	}

	void iniciarContenidoPapelera() {
		cout << "\nCargando correo papelera...";
		string direccion = "Datos/" + to_string(idUsuario) + ".txt";
		iniT.inicializarCorreo(papelera, direccion, "T");
		cout << "Correo papelera cargado!";
	}

	void mostrarContenidoPapelera() {
		papelera->mostrar();
	}
};