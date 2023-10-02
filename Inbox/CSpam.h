#pragma once

#include "ListaCorreo.h"
#include "Contenido.h"
#include "Inicializador.h"
class CSpam
{
private:
	ListaDoble<Contenido*>* spam;
	Inicializador iniS;
	int idUsuario;
public:
	CSpam(int id) {
		spam = new ListaDoble<Contenido*>();
		this->idUsuario = id;
	}
	~CSpam() {
		spam->~ListaDoble();
	}

	void iniciarContenidoSpam() {
		cout << "\nCargando correo spam...";
		string direccion = "Datos/" + to_string(idUsuario) + ".txt";
		iniS.inicializarCorreo(spam, direccion, "S");
		cout << "Correo spam cargado!";
	}

	void mostrarContenidoSpam() {
		spam->mostrar();
	}
};