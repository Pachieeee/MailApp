 #pragma once

#include "ListaCorreo.h"
#include "Contenido.h"
#include "Inicializador.h"
class CFijado
{
private:
	ListaDoble<Contenido*>* fijado;
	Inicializador iniF;
	int idUsuario;
public:
	CFijado(int id) {
		fijado = new ListaDoble<Contenido*>();
		this->idUsuario = id;
	}
	~CFijado() {
		fijado->~ListaDoble();
	}

	void iniciarContenidoFijado() {
		cout << "\nCargando correo fijado...";
		string direccion = "Datos/" + to_string(idUsuario) + ".txt";
		iniF.inicializarCorreo(fijado, direccion, "F");
		cout << "Correo fijado cargado";
	}

	void mostrarContenidoFijado() {
		fijado->mostrar();
	}
};