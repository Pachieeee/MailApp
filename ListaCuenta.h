#pragma once
#include "Cuenta.h"

using namespace std;

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
		if (getLon() == 0) {
			cout << "Lista vacía. Intente ingresar nuevos usuarios.";
			return;
		}

		NodoS<T>* nodo = ini;
		stack<NodoS<T>*> pila;

		while (nodo != nullptr) {
			pila.push(nodo);
			nodo = nodo->sig;
		}
		cout << "ID, Pais, Cargo, Apellido, Correo, Aliado Palestino?, Fecha de Creacion "<< endl;
		while (!pila.empty()) {
			nodo = pila.top();
			pila.pop();
			Cuenta* cta = (Cuenta*)(nodo->elem);
			cout << cta->getID() << ", " << cta->getPais() << ", " << cta->getCargo() << ", "  << cta->getApellido() << ", " << cta->getCorreo() << ", " << cta->getEsAliadoPalestino() << ", " << cta->getFechaCreacion() << endl;
		}
		cout << endl;
	}


	NodoS<T>* findByValue(const T& val) {
		NodoS<T>* nodo = ini;
		while (nodo != nullptr) {
			if (nodo->elem == val) {
				return nodo;
			}
			nodo = nodo->sig;
		}
		return nullptr;
	}

	void swapNodes(NodoS<T>* nodo1, NodoS<T>* nodo2) {
		T temp = nodo1->elem;
		nodo1->elem = nodo2->elem;
		nodo2->elem = temp;
	}

	bool comparePorApellido(Cuenta* cuenta1, Cuenta* cuenta2) {
		return cuenta1->getApellido() < cuenta2->getApellido();
	}


	T* toArray() {
		T* arr = new T[lon];
		NodoS<T>* current = ini;
		int index = 0;
		while (current != nullptr) {
			arr[index] = current->elem;
			current = current->sig;
			index++;
		}
		return arr;
	}

	void heapify(T* arr, int n, int i) {
		int largest = i;
		int left = 2 * i + 1;
		int right = 2 * i + 2;

		if (left < n && comparePorApellido(arr[left], arr[largest])) {
			largest = left;
		}

		if (right < n && comparePorApellido(arr[right], arr[largest])) {
			largest = right;
		}

		if (largest != i) {
			swapNodes(findByValue(arr[i]), findByValue(arr[largest]));
			swap(arr[i], arr[largest]);
			heapify(arr, n, largest);
		}
	}


	void heapSort() {
		T* arr = toArray();
		int n = lon;

		for (int i = n / 2 - 1; i >= 0; i--) {
			heapify(arr, n, i);
		}

		for (int i = n - 1; i > 0; i--) {
			swap(arr[0], arr[i]);
			swapNodes(findByValue(arr[0]), findByValue(arr[i]));
			heapify(arr, i, 0);
		}

		delete[] arr;
	}


	void mostrarOrdenadoPorHeapSort() {
		heapSort();
		cout << "Heap sort aplicado" << endl;
		mostrar();
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
			if (verificar(cuentaNodo->getCorreo(), cuentaNodo->getContrasena(), correo, contra)) { 
				cout << "\nInicio de sesion correcto! Registrado como ";
				cout << cuentaNodo->getCargo() << " " << cuentaNodo->getApellido();
				return cuentaNodo->getID();
			}
			nodo = nodo->sig;
		}
		return -1;
	}
};