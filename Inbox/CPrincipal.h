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

	int retornarCantCorreos() {
		return principal->getLon();
	}

	void iniciarContenidoPrincipal() {
		cout << "\nCargando correo principal...";
		string direccion = "BD/" + to_string(idUsuario) + ".txt";
		iniP.inicializarCorreo(principal, direccion, "P");
		cout << "Correo principal cargado!";
	}

	void ordenarPorInicialAutor() {
		principal->quickSort();
		cout << "Correo organizado!";
	}

	void mostrarContenidoPrincipal(int pag, int limite = 10, int ampliar = 11) {
		//principal->mostrar();
		cout << "\n===========================================================\n";
		for (int i = 0; i < limite; i++) {

			if (i == ampliar)
				principal->vistaAmplia(i + (pag * 10));
			else
				principal->vistaSimple(i + (pag * 10));
			cout << "\n===========================================================\n";
		}
	}
};