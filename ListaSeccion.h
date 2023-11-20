#pragma once
#include "Contenido.h"

using namespace std;

template <class T>
class NodoSe {
public:
	T elem;
	NodoSe<T>* sig;
public:
	NodoSe(T elem, NodoSe<T>* sig = NULL) :
		elem(elem), sig(sig) {}
};

template <class T>
class ListaSimpleS {
private:
	NodoSe<T>* ini;
	int lon;

public:
	ListaSimpleS() {
		ini = NULL;
		lon = 0;
	}

	~ListaSimpleS() {
		NodoSe<T>* temp;
		while (ini != NULL) {
			temp = ini;
			ini = ini->sig;
			delete temp;
			temp = NULL;
		}
		ini = NULL;
		lon = 0;
	}

	int getLon() { return lon; }

	void pushFront(T val) {
		NodoSe<T>* nodo = new NodoSe<T>(val);

		if (ini == NULL)
			ini = nodo;
		else
			nodo->sig = ini;
		ini = nodo;
		nodo = NULL;
		++lon;
	}

	void pushPos(T val, int pos) {
		if (pos > lon) return;
		if (pos == 0) pushFront(val);
		else {
			NodoSe<T>* aux = ini;
			for (int i = 1; i < pos; i++)
				aux = aux->sig;
			NodoSe<T>* nuevo = new NodoSe<T>(val);
			if (nuevo != nullptr) {
				nuevo->sig = aux->sig;
				aux->sig = nuevo;
				++lon;
			}
		}
	}
	void pushBack(T val) {
		pushPos(val, lon);
	}


	NodoSe<T>* getNodo(int pos) {
		if (pos >= 0 && pos < lon) {
			NodoSe<T>* nodo = ini;
			for (int i = 0; i < pos; i++) {
				nodo = nodo->sig;
			}
			return nodo;
		}
		else {
			return nullptr;
		}
	}
	void vistaSimple(int pos) {
		NodoSe<T>* nodo = getNodo(pos);
		Contenido* contenido = (Contenido*)(nodo->elem);
		contenido->getResumen();
	}
	void vistaAmplia(int pos) {
		NodoSe<T>* nodo = getNodo(pos);
		Contenido* contenido = (Contenido*)(nodo->elem);
		contenido->getContenido();
	}
};