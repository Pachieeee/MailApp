#pragma once
#include "Contenido.h"
#include <iostream>
#include <fstream>
#include <string>

template<class T>
class Nodo {
public:
	T elem;
	Nodo<T>* ant;
	Nodo<T>* sig;

public:
	Nodo(T elem, Nodo<T>* ant = NULL, Nodo<T>* sig = NULL) :
		elem(elem), ant(ant), sig(sig) {}
};

template<class T>
class ListaDoble {
private:
	Nodo<T>* ini;
	int lon;
	//function<bool(char, char)> compararOrdenAlfabetico;

	bool compararOrdenAlfabetico(T a, T b) {
		char letraA = a->getAutor()[0];
		char letraB = b->getAutor()[0];
		return letraA < letraB;
	}

	Nodo<T>* particion(Nodo<T>* menor, Nodo<T>* mayor) {
		T pivote = mayor->elem; //pivote
		Nodo<T>* i = menor->ant; //indice de los menores
		for (Nodo<T>* j = menor; j != mayor; j = j->sig) {
			if (compararOrdenAlfabetico(j->elem, pivote)) {
				i = (i == nullptr) ? menor : i->sig;
				swap(i->elem, j->elem);
			}
		}
		i = (i == nullptr) ? menor : i->sig;
		swap(i->elem, mayor->elem);
		return i;
	}
	void _quickSort(Nodo<T>* bajo, Nodo<T>* alto) {
		if (bajo != nullptr && alto != nullptr && bajo != alto && bajo->ant != alto) {
			Nodo<T>* pivote = particion(bajo, alto);

			_quickSort(bajo, pivote->ant);
			_quickSort(pivote->sig, alto);
		}
	}
public:
	ListaDoble() {
		ini = NULL;
		lon = 0;
		/*compararOrdenAlfabetico = [](char autorA, char autorB) {
			return autorA < autorB;
			};*/
	}
	~ListaDoble() {
		Nodo<T>* temp;
		while (ini != NULL) {
			temp = ini;
			ini = ini->sig;
			delete temp;
			temp = NULL;
		}
		delete ini;
		ini = NULL;
	}

	/*static bool compararAutores(const Contenido& autorA, const Contenido& autorB) {
		return compararOrdenAlfabetico(autorA.getAutor()[0], autorB.getAutor()[0]);
	}*/

	void mostrar() {
		Nodo<T>* nodo = ini;
		if (lon == 0) {
			cout << "No hay correos disponibles\n";
			return;
		}
		do {

			Contenido* contenido = (Contenido*)(nodo->elem);
			contenido->getContenido();
			cout << "\n===================================================================================\n";
			nodo = nodo->sig;
		} while (nodo != nullptr);
		cout << endl;
	}
	void pushFront(T v) {
		Nodo<T>* nodo = new Nodo<T>(v);

		if (ini == NULL)
			ini = nodo;
		else {
			ini->ant = nodo;
			nodo->sig = ini;
		}
		ini = nodo;
		nodo = NULL;
		++lon;
	}

	void pushPos(T v, int pos) {
		if (pos > lon) return;
		if (pos == 0) {
			pushFront(v);
		}
		else {
			Nodo<T>* aux = ini;
			for (int i = 1; i < pos; i++)
				aux = aux->sig;

			Nodo<T>* nuevo = new Nodo<T>(v);

			if (nuevo != nullptr) {
				nuevo->sig = aux->sig;
				nuevo->ant = aux;

				if (aux->sig != nullptr)
					aux->sig->ant = nuevo;
				aux->sig = nuevo;
				++lon;
			}
		}
	}
	void pushBack(T v) {
		pushPos(v, lon);
	}

	void popFront() {
		if (lon > 0) {
			Nodo<T>* nodo = ini;
			ini = ini->sig;
			delete nodo;
			lon--;
		}
	}
	void popPos(int pos) {
		if (pos == 0)
			popFront();
		else if (pos >= 1 && pos < lon) {
			Nodo<T>* nodo = ini;
			Nodo<T>* for_remove;
			for (int i = 1; i < pos; i++) {
				nodo = nodo->sig;
			}
			for_remove = nodo->sig;
			nodo->sig = for_remove->sig;
			if (for_remove->sig != nullptr)
				for_remove->sig->ant = nodo;

			delete for_remove;
			lon--;
		}
	}
	void popBack() {
		popPos(lon - 1);
	}

	T getNodo(int pos) {
		if (pos >= 0 && pos < lon) {
			Nodo<T>* nodo = ini;
			for (int i = 0; i < pos; i++) {
				nodo = nodo->sig;
			}
			return nodo->elem;
		}
		else {
			return nullptr;
		}
	}
	T buscar(T v) {
		Nodo<T>* nodo = ini;
		while (nodo != nullptr) {
			Contenido* contenido = (Contenido*)(nodo->elem);
			cout << contenido->getContenido();
			nodo = nodo->sig;
		}
		return nullptr;
	}

	Nodo<T>* getTail(Nodo<T>* nodo) {
		while (nodo != nullptr && nodo->sig != nullptr) {
			nodo = nodo->sig;
		}
		return nodo;
	}

	void quickSort() {
		_quickSort(ini, getTail(ini));
	}
};