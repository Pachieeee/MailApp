#pragma once

#include "ListaCorreo.h"
#include "Contenido.h"
#include "Inicializador.h"
class CEnviado
{
private:
	ListaDoble<Contenido*>* enviado;
	Inicializador iniE;
	int idUsuario;
public:
	CEnviado(int id) {
		enviado = new ListaDoble<Contenido*>();
		this->idUsuario = id;
	}
	~CEnviado() {
		enviado->~ListaDoble();
	}

	void iniciarContenidoEnviado() {
		cout << "\nCargando correo enviado...";
		string direccion = "Datos/" + to_string(idUsuario) + ".txt";
		iniE.inicializarCorreo(enviado, direccion, "E");
		cout << "Correo enviado cargado!";
	}

	void mostrarContenidoEnviado() {
		enviado->mostrar();
	}
};