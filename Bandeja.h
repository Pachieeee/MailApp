#pragma once

#include "Inicializador.h"
using namespace std;

class Bandeja
{
private:
	ListaDoble<Contenido*>* bandeja;
	Inicializador iniBand;
	int idUsuario;
public:
	Bandeja(int id) {
		bandeja = new ListaDoble<Contenido*>();
		this->idUsuario = id;
	}
	~Bandeja() {
		bandeja->~ListaDoble();
	}

	void iniciarBandeja() {
		cout << "\nCargando bandeja...";
		string direccion = "BD/" + to_string(idUsuario) + ".txt";
		iniBand.inicializarCorreo(bandeja, direccion);
		cout << "Bandeja cargada!";
	}

	int retornarCantCorreos(string X) {
		int cont = 0;
		Contenido* aux = nullptr;
		for (int i = 0; i < bandeja->getLon(); i++) {
			aux = bandeja->getNodo(i)->elem;
			if (aux->getTipo() == X) {
				cont++;
			}
		}
		return cont;
	}

	void ordenarPorInicialAutor() {
		bandeja->quickSort();
		cout << "Correo organizado!";
	}
	void mostrarContenidoPrincipal(int pag, int limite = 10, int ampliar = 11) {
		//principal->mostrar();
		cout << "\n===========================================================\n";
		for (int i = 0; i < limite; i++) {

			if (i == ampliar)
				bandeja->vistaAmplia(i + (pag * 10));
			else
				bandeja->vistaSimple(i + (pag * 10));
			cout << "\n===========================================================\n";
		}
	}
	void mostrarBandeja(string tipo) {
		bandeja->mostrar(tipo);
	}
};