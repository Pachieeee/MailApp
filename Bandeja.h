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
		string direccion = "Datos/" + to_string(idUsuario) + ".txt";
		iniBand.inicializarCorreo(bandeja, direccion);
		cout << "Bandeja cargada!";
	}

	void ordenarPorInicialAutor() {
		bandeja->quickSort();
		cout << "Correo organizado!";
	}

	void mostrarBandeja(string tipo) {
		bandeja->mostrar(tipo);
	}
};