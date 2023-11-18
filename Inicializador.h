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
		HashTableA_usuarios ht = HashTableA_usuarios();
		if (lector.is_open()) {
			string linea;
			string id, cargo, apellido, correo, contrasena, claveCesar, esAliadoPalestino, pais, fechaCreacion;

			while (getline(lector, linea)) {
				stringstream stream(linea);
				getline(stream, id, ',');
				getline(stream, cargo, ',');
				getline(stream, apellido, ',');
				getline(stream, correo, ',');
				getline(stream, contrasena, ',');
				getline(stream, claveCesar, ',');
				getline(stream, esAliadoPalestino, ',');
				getline(stream, pais, ',');
				getline(stream, fechaCreacion, ',');
				// Pendiente: Migrar la lista a Hash Table
				lista->pushBack(new Cuenta(stoi(id), cargo, apellido, correo, contrasena, stoi(claveCesar), esAliadoPalestino, pais, fechaCreacion));
				ht.insert(Cuenta(stoi(id), cargo, apellido, correo, contrasena, stoi(claveCesar), esAliadoPalestino, pais, fechaCreacion));
			}
			lector.close();
		}
	}
	/*
	void inicializarCorreo(ListaDoble<Contenido*>* bandeja, string direc) {
		lector.open(direc, ios::in);
		if (lector.is_open()) {
			string linea; //sstream
			string tipo, aut, corA, asu, mens, fecha; //datos

			while (getline(lector, linea)) {
				stringstream stream(linea);
				getline(stream, tipo, '|');
				getline(stream, aut, '|');
				getline(stream, corA, '|');
				getline(stream, asu, '|');
				getline(stream, mens, '|');
				getline(stream, fecha, '|');
				bandeja->pushBack(new Contenido(tipo, aut, corA, asu, mens, fecha));
			}
			lector.close();
		}
	}
	*/
	void inicializarCorreo(ListaDoble<Contenido*>* bandeja, string direc, int idUsuario) {
		lector.open("BD/Correos.csv", ios::in);
		if (lector.is_open()) {
			string linea; //sstream
			string id, tipo, aut, corA, asu, mens, fecha; //datos

			while (getline(lector, linea)) {
				stringstream stream(linea);
				getline(stream, id, '|');
				if (stoi(id) == idUsuario) { //Si la ID corresponde al usuario
					getline(stream, tipo, '|');
					getline(stream, aut, '|');
					getline(stream, corA, '|');
					getline(stream, asu, '|');
					getline(stream, mens, '|');
					getline(stream, fecha, '|');
					bandeja->pushBack(new Contenido(tipo, aut, corA, asu, mens, fecha));
				}
			}
			lector.close();
		}
	}

	void inicializarBusqueda(ArbolAVL<Contenido*>* busqueda, string direc,string obj, int filtro) {
		lector.open(direc, ios::in);
		if (lector.is_open()) {
			string linea;
			string tipo, autor, correoAutor, asunto, mensaje, fecha;
			while (getline(lector, linea)) {
				stringstream stream(linea);
				getline(stream, tipo, '|');
				getline(stream, autor, '|');
				getline(stream, correoAutor, '|');
				getline(stream, asunto, '|');
				getline(stream, mensaje, '|');
				getline(stream, fecha, '|');
				switch (filtro)
				{
				case 1:
					if (autor == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, asunto, mensaje, fecha));
					break;
				case 2:
					if (correoAutor == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, asunto, mensaje, fecha));
					break;
				case 3:
					if (asunto == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, asunto, mensaje, fecha));
					break;
				}
			}
			lector.close();
		}
	}

	void guardarCuenta(string line, int id) {
		guardado.open("BD/Cuentas.csv", ios_base::app);
		guardado << line << endl;
		guardado.close();
	}
};