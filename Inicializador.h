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
			string tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio;
			while (!lector.eof()) {
				getline(lector, tipo, '|');
				getline(lector, autor, '|');
				getline(lector, correoAutor, '|');
				getline(lector, correoDestino, '|');
				getline(lector, asunto, '|');
				getline(lector, mensaje, '|');
				getline(lector, fechaEnvio, '|');

				bandeja->pushBack(new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio));
				if (tipo == "") break;
				else
					getline(lector, tipo);
			}
		}
	}

	void inicializarBusqueda(ArbolAVL<Contenido*>* busqueda, string direc,string obj, int filtro) {
		lector.open(direc, ios::in);
		char delimit = '|';
		if (lector.is_open()) {
			string tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio;
			while (!lector.eof()) {
				getline(lector, tipo, delimit);
				getline(lector, autor, delimit);
				getline(lector, correoAutor, delimit);
				getline(lector, correoDestino, delimit);
				getline(lector, asunto, delimit);
				getline(lector, mensaje, delimit);
				getline(lector, fechaEnvio, delimit);
				switch (filtro)
				{
				//! Sebas, factoriza el codigo
				case 1:
					if (autor == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio));
					break;
				case 2:
					if (correoAutor == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio));
					break;
				case 3:
					if (asunto == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio));
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
		string nuevoUsuario = "BD/" + to_string(id) + ".csv";
		guardado.open(nuevoUsuario, ios::out);
		guardado.close();
	}

	void guardarCorreo(string line, int id){
		guardado.open("BD/Correos.csv", ios_base::app);
		guardado << line << endl;
		guardado.close();
		string nuevoUsuario = "BD/" + to_string(id) + ".csv";
		guardado.open(nuevoUsuario, ios::out);
		guardado.close();
	}
};