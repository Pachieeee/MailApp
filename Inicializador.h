#pragma once
#include "Cuenta.h"
#include "Contenido.h"
#include "ListaCuenta.h"
#include "ListaCorreo.h"
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
		lector.open("BD/Cuentas.txt", ios::in);
		if (lector.is_open()) {
			string id, cargo, apellido, correo, contrasena, claveCesar, esAliadoPalestino, pais, fechaCreacion;

			while (!lector.eof()) {
				getline(lector, id, ',');
				if (id == "") break;
				getline(lector, cargo, ',');
				getline(lector, apellido, ',');
				getline(lector, correo, ',');
				getline(lector, contrasena, ',');
				getline(lector, claveCesar, ',');
				getline(lector, esAliadoPalestino, ',');
				getline(lector, pais);
				getline(lector, fechaCreacion);
				lista->pushBack(new Cuenta(stoi(id), cargo, apellido, correo, contrasena, stoi(claveCesar), esAliadoPalestino, pais, fechaCreacion));
			}
			lector.close();
		}
		// ------------------------------------------------
		// ifstream archIN;
		// archIN.open(nombre_archivo, ios::in); //Apertura

		// if (!archIN.is_open())
		// {
		// 	cout << "Error: No se pudo abrir el archivo !!!" << endl;
		// 	exit(1);
		// }

		// string linea;
		// char delimitador = ','; //Separador de cada columna de la lÃ­nea

		// // Encabezado: Leemos la primera lÃ­nea para descartarla, pues es el encabezado
		// getline(archIN, linea);

		// // Contenido: Leemos todas las lÃ­neas
		// HashTableA_usuarios ht = HashTableA_usuarios();
		
		// while (getline(archIN, linea))
		// {
		// 	stringstream stream(linea); // Convertir la cadena a un stream

		// 	string col1, col2, col3, col4;
		// 	// Extraer todos los valores de esa fila [considerando 4 columans]
		// 	getline(stream, col1, delimitador);
		// 	getline(stream, col2, delimitador);
		// 	getline(stream, col3, delimitador);
		// 	getline(stream, col4, delimitador);

		// 	ht.insert(Cuenta(col1, col2, col3, stoi(col4)));		
		// }

		// // Cerramos Archivo
		// archIN.close();
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

	void inicializarBusqueda(ListaDoble<Contenido*>* bandeja, string direc, string obj, int filtro) {
		lector.open(direc, ios::in);
		if (lector.is_open()) {
			string tipo, aut, corA, asu, mens;

			while (!lector.eof()) {
				getline(lector, tipo, '|');
				getline(lector, aut, '|');
				getline(lector, corA, '|');
				getline(lector, asu, '|');
				getline(lector, mens);
				switch (filtro)
				{
				case 1:
					if (aut == obj) {
						bandeja->pushBack(new Contenido(tipo, aut, corA, asu, mens));
					}
					break;
				case 2:
					if (corA == obj) {
						bandeja->pushBack(new Contenido(tipo, aut, corA, asu, mens));
					}
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