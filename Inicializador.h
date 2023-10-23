#pragma once
#include "Cuenta.h"
#include "Contenido.h"
#include "ListaCuenta.h"
#include "ListaCorreo.h"
class Inicializador
{
private:
	ifstream lector;
	ofstream guardado;
public:
	Inicializador() {
		CrearCarpeta();
	}
	void CrearCarpeta(string nombreCarpeta = "BD") {
		int resultado = system(("mkdir " + nombreCarpeta).c_str());
	}

	void inicializarCuentas(ListaSimple<Cuenta*>* lista) {
		lector.open("BD/Cuentas.txt", ios::in);
		if (lector.is_open()) {
			//string nom, ape, cor, con;
			//string id;
			//id, cargo, apellido, correo, contrase�a, clave caesar, tipocorreo, fecha
			// string id, ape, cor, con, cla, tipo, pais, fecha;
			string id, cargo, apellido, correo, contrasena, claveCesar, esAliadoPalestino, pais;

			while (!lector.eof()) {
				getline(lector, id, ',');
				if (id == "") break;
				getline(lector, cargo, ',');
				getline(lector, apellido, ',');
				getline(lector, correo, ',');
				getline(lector, contrasena, ',');
				getline(lector, claveCesar, ',');
				getline(lector, esAliadoPalestino);
				getline(lector, pais);
				//getline(lector, fecha);
				//lista->pushBack(new Cuenta(nom, ape, cor, con, stoi(id)));
				lista->pushBack(new Cuenta(stoi(id), cargo, apellido, correo, contrasena, stoi(claveCesar), true, pais));
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