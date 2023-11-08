#pragma once
#include "Cuenta.h"
#include "Contenido.h"
#include "ListaCuenta.h"
#include "ListaCorreo.h"
#include "ArbolBusqueda.h"
#include "HashTableA_usuarios.h"
#include <sys/stat.h>

#define nombre_archivo "usuarios.csv"

struct stat buffer;

class Inicializador
{
private:
	ifstream lector;
	ofstream guardado;
public:
	Inicializador() {
		CrearCarpeta();
	}
	void CrearCarpeta() {
		if (stat("BD", &buffer)) system("mkdir BD");
	}

	void inicializarCuentas(ListaSimple<Cuenta*>* lista) {
		lector.open("BD/Cuentas.csv", ios::in);
		if (!lector.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!" << endl;
		}
		char delimitador = ','; //Separador de cada columna de la lÃ­nea
		HashTableA_usuarios ht = HashTableA_usuarios();
		if (lector.is_open()) {
			string id, cargo, apellido, correo, contrasena, claveCesar, esAliadoPalestino, pais, fechaCreacion;
			while (!lector.eof()) {
				getline(lector, id, delimitador);
				if (id == "") break;
				getline(lector, cargo, delimitador);
				getline(lector, apellido, delimitador);
				getline(lector, correo, delimitador);
				getline(lector, contrasena, delimitador);
				getline(lector, claveCesar, delimitador);
				getline(lector, esAliadoPalestino, delimitador);
				getline(lector, pais, delimitador);
				getline(lector, fechaCreacion);
				// Pendiente: Migrar la lista a Hash Table
				lista->pushBack(new Cuenta(stoi(id), cargo, apellido, correo, contrasena, stoi(claveCesar), esAliadoPalestino, pais, fechaCreacion));

				ht.insert(Cuenta(stoi(id), cargo, apellido, correo, contrasena, stoi(claveCesar), esAliadoPalestino, pais, fechaCreacion));		
			}
			lector.close();
		}
	}

	void inicializarCorreo(ListaDoble<Contenido*>* bandeja, string direc) {
		lector.open(direc, ios::in);
		if (lector.is_open()) {
			string tipo, aut, corA, asu, mens;
			

			while (!lector.eof()) {
				getline(lector, tipo, '|');
				getline(lector, aut, '|');
				getline(lector, corA, '|');
				getline(lector, asu, '|');
				getline(lector, mens);

				bandeja->pushBack(new Contenido(tipo, aut, corA, asu, mens));
				if (tipo == "") break;
				else
					getline(lector, tipo);
			}
		}
	}

	//void inicializarBusqueda(ListaDoble<Contenido*>* bandeja, string direc, string obj, int filtro) {
	//	lector.open(direc, ios::in);
	//	if (lector.is_open()) {
	//		string tipo, aut, corA, asu, mens;

	//		while (!lector.eof()) {
	//			getline(lector, tipo, '|');
	//			getline(lector, aut, '|');
	//			getline(lector, corA, '|');
	//			getline(lector, asu, '|');
	//			getline(lector, mens);
	//			switch (filtro)
	//			{
	//			case 1:
	//				if (aut == obj) {
	//					bandeja->pushBack(new Contenido(tipo, aut, corA, asu, mens));
	//				}
	//				break;
	//			case 2:
	//				if (corA == obj) {
	//					bandeja->pushBack(new Contenido(tipo, aut, corA, asu, mens));
	//				}
	//				break;
	//			}
	//		}
	//		lector.close();
	//	}
	//}

	void inicializarBusqueda(ArbolAVL<Contenido*>* busqueda, string direc,string obj, int filtro) {
		lector.open(direc, ios::in);
		char delimit = '|';
		if (lector.is_open()) {
			string tipo, autor, correoAutor, asunto, mensaje;
			while (!lector.eof()) {
				getline(lector, tipo, delimit);
				getline(lector, autor, delimit);
				getline(lector, correoAutor, delimit);
				getline(lector, asunto, delimit);
				getline(lector, mensaje, delimit);
				switch (filtro)
				{
				case 1:
					if (autor == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, asunto, mensaje));
					break;
				case 2:
					if (correoAutor == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, asunto, mensaje));
					break;
				case 3:
					if (asunto == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, asunto, mensaje));
					break;
				}
			}
			lector.close();
		}
	}

	void guardarCuenta(string line, int id) {
		guardado.open("BD/Cuentas.txt", ios_base::app);
		guardado << line << endl;
		guardado.close();
		string nuevoUsuario = "BD/" + to_string(id) + ".txt";
		guardado.open(nuevoUsuario, ios::out);
		guardado.close();
	}
};