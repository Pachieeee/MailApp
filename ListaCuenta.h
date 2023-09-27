#pragma once
#include "Cuenta.h"

template <class T>
class NodoS {
public:
	T elem;
	NodoS<T>* sig;
public:
	NodoS(T elem, NodoS<T>* sig = NULL) :
		elem(elem), sig(sig) {}
};

template <class T>
class ListaSimple {
private:
	NodoS<T>* ini;
	int lon;
	function<bool(string, string, string, string)> verificar;

public:
	ListaSimple() {
		ini = NULL;
		lon = 0;
		verificar = [](string correoNodo, string contraNodo, string correoVal, string contraVal) {
			if (correoNodo == correoVal && contraNodo == contraVal)
				return true;
			else
				return false;
			};
	}

	~ListaSimple() {
		NodoS<T>* temp;
		while (ini != NULL) {
			temp = ini;
			ini = ini->sig;
			delete temp;
			temp = NULL;
		}
		ini = NULL;
	}

	int getLon() { return lon; }

	void pushFront(T val) {
		NodoS<T>* nodo = new NodoS<T>(val);

		if (ini = NULL)
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
			NodoS<T>* aux = ini;
			for (int i = 1; i < pos; i++)
				aux = aux->sig;
			NodoS<T>* nuevo = new NodoS<T>(val);
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

	//Se planea usar para eliminar una cuenta
	void popFront() {
		if (lon > 0) {
			NodoS<T>* nodo = ini;
			ini = ini->sig;
			delete nodo;
			lon--;
		}
	}
	void popPos(int pos) {
		if (pos == 0) popFront();
		else if (pos >= 1 && pos < lon) {
			NodoS<T>* nodo = ini;
			NodoS<T>* for_remove;
			for (int i = 1; i < pos; i++)
				nodo = nodo->sig;
			for_remove = nodo->sig;
			nodo->sig = for_remove->sig;
			delete for_remove;
			lon--;
		}
	}
	void popBack() {
		popPos(lon - 1);
	}

	string searchCorreoExiste(string val) {
		NodoS<T>* nodo = ini;
		while (nodo != nullptr) {
			Cuenta* cuenta_nodo = (Cuenta*)(nodo->elem);
			if (cuenta_nodo->getCorreo() == val) {
				return val;
			}
			nodo = nodo->sig;
		}
		return "No";
	}

	void mostrar() {
		int cont = 0;
		NodoS<T>* nodo = ini;
		do {
			cout << "\nUsuario " << cont << ": ";
			Cuenta* cta = (Cuenta*)(nodo->elem);
			cout << cta->getNombre() << ", " << cta->getApellido() << ", " << cta->getCorreo() << ", " << cta->getID();
			nodo = nodo->sig;
			cont++;
		} while (nodo != nullptr);
		cout << endl;
	}

	T getNodo(int pos) {
		if (pos >= 0 && pos < lon) {
			NodoS<T>* nodo = ini;
			for (int i = 0; i < pos; i++) {
				nodo = nodo->sig;
			}
			return nodo->elem;
		}
		else {
			return nullptr;
		}
	}

	int iniciarSesion(string correo, string contra) {
		NodoS<T>* nodo = ini;
		while (nodo != nullptr) {
			Cuenta* cuentaNodo = (Cuenta*)(nodo->elem);
			if (verificar(cuentaNodo->getCorreo(), cuentaNodo->getContra(), correo, contra)) { 
				cout << "\nInicio de sesion correcto! Registrado como ";
				cout << cuentaNodo->getNombre() << " " << cuentaNodo->getApellido();
				return cuentaNodo->getID();
			}
			nodo = nodo->sig;
		}
		return -1;
	}
};