#pragma once
#include <algorithm>

using namespace std;

template<class T>
class NodoB {
public:
	T elemento;
	NodoB* izq;
	NodoB* der;

	NodoB() {
		izq = nullptr;
		der = nullptr;
	}
};

template<class T>
class ArbolAVL {
private:
	NodoB<T>* raiz;

	void(*procesar)(T); 
	int _altura(NodoB<T>* nodo) {
		int h = 0;
		if (nodo != NULL) {
			int hizq = _altura(nodo->izq);
			int hder = _altura(nodo->der);
			int max_h = max(hizq, hder);
			h = max_h + 1;
		}
		return h;
	}

	void _rotarDerecha(NodoB<T>*& nodo) {
		NodoB<T>* p = nodo->izq;
		nodo->izq = p->der;
		p->der = nodo;
		nodo = p;
	}

	void _rotarIzquierda(NodoB<T>*& nodo) {
		NodoB<T>* p = nodo->der;
		nodo->der = p->izq;
		p->izq = nodo;
		nodo = p;
	}

	void _balanceo(NodoB<T>*& nodo) {
		int hizq = _altura(nodo->izq);
		int hder = _altura(nodo->der);
		int fb = hder - hizq;
		if (fb > 1) {
			int hhizq = _altura(nodo->der->izq);
			int hhder = _altura(nodo->der->der);
			if (hhizq > hhder) {
				_rotarDerecha(nodo->der);
			}
			_rotarIzquierda(nodo);
		}
		else if (fb < -1) {
			int hhizq = _altura(nodo->izq->izq);
			int hhder = _altura(nodo->izq->der);
			if (hhizq < hhder) {
				_rotarIzquierda(nodo->izq);
			}
			_rotarDerecha(nodo);
		}
	}

	bool _insertar(NodoB<T>*& nodo, T e) {
		if (nodo == nullptr) { //Nuevo elemento
			nodo = new NodoB<T>();
			nodo->elemento = e;
			return true;
		}
		else if (e == nodo->elemento) {
			return false;
		}
		else if (e < nodo->elemento) {
			_insertar(nodo->izq, e);
		}
		else if (e > nodo->elemento) {
			_insertar(nodo->der, e);
		}
		_balanceo(nodo);
		return true;
	}

	void _inOrden(NodoB<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrden(nodo->izq);
		procesar(nodo->elemento);
		_inOrden(nodo->der);
	}

	void _inOrdenH(NodoB<T>* nodo) {
		if (nodo == nullptr) return;
		_inOrdenH(nodo->izq);
		//procesar(nodo->altura);
		procesar(to_string(_altura(nodo)));
		_inOrdenH(nodo->der);
	}

	void _preOrden(NodoB<T>* nodo) {	//Raiz => Izq => Der
		if (nodo == nullptr) return;
		procesar(nodo->elemento);
		_preOrden(nodo->izq);
		_preOrden(nodo->der);
	}

	void _postOrden(NodoB<T>* nodo) {	//Izq => Der => Raiz
		if (nodo == nullptr) return;
		_postOrden(nodo->izq);
		_postOrden(nodo->der);
		procesar(nodo->elemento);
	}

public:
	ArbolAVL(void(*nuevaFuncion)(T)) {
		this->procesar = nuevaFuncion;
		this->raiz = nullptr;
	}

	~ArbolAVL() {}

	bool Insertar(T e) {
		return _insertar(raiz, e);
	}

	void inOrden() {
		_inOrden(raiz);
	}

	void inOrdenH() {
		_inOrdenH(raiz);
	}

	void preOrden() {
		_preOrden(raiz);
	}

	void postOrden() {
		_postOrden(raiz);
	}
};