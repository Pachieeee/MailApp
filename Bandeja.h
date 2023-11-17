#pragma once
#include "ListaSeccion.h"
#include "Inicializador.h"
using namespace std;

class Bandeja
{
private:
	ListaDoble<Contenido*>* bandeja;
	ListaSimpleS<Contenido*>* seccion;
	Inicializador iniBand;
	int idUsuario;
public:
	Bandeja(int id) {
		bandeja = new ListaDoble<Contenido*>();
		seccion = new ListaSimpleS<Contenido*>();
		this->idUsuario = id;
	}
	
	~Bandeja() {
		bandeja->~ListaDoble();
	}

	void limpiarSeccion() {
		seccion->~ListaSimpleS();
	}

	void iniciarBandeja() {
		cout << "\nCargando bandeja...";
		string direccion = "BD/" + to_string(idUsuario) + ".csv";
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

	void iniciarContenido(string band) {
		Contenido* test;
		for (int i = 0; i < bandeja->getLon(); i++) {
			test = (Contenido*)(bandeja->getNodo(i)->elem);
			if (test->getTipo() == band) {
				seccion->pushBack(test);
			}
		}
	}

	void mostrarContenido(int pag, int limite = 10, int ampliar = 11) {
		cout << "\n===========================================================\n";
		for (int i = 0; i < limite; i++) {

			if (i == ampliar)
				seccion->vistaAmplia(i + (pag * 10));
			else
				seccion->vistaSimple(i + (pag * 10));
			cout << "\n===========================================================\n";
		}
	}
	void mostrarBandeja(string tipo) {
		bandeja->mostrar(tipo);
	}
};