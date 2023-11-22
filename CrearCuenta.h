#pragma once
#include "Cuenta.h"
#include "ListaCuenta.h"
#include "Inicializador.h"

template <class T>
class CrearCuenta
{
private:
	Inicializador guardar;
	function<bool(string, string)> compCorreoExiste;
public:
	CrearCuenta() {
		compCorreoExiste = [](string correoNuevo, string correoExiste) {
			if (correoNuevo == correoExiste) return true;
			else return false;
			};
	}


	bool esCorreoValido(string correo){
		regex patronCorreoElectronico("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
		if (regex_match(correo, patronCorreoElectronico)) return true;
		else return false;
	}

	bool esApellidoValido(string apellido){
		if(apellido.length() < 2) return false;
		else return true;
	}


	bool esCuentaValida(string apellido, string correo, ListaSimple<Cuenta*>* lista){

		bool esValido = true;

		if(!esApellidoValido(apellido)) {
			cout << "\nEl apellido debe tener por lo menos 2 caracteres.";
			esValido = false;
		}

		if(!esCorreoValido(correo)) {
			cout << "\nPor favor, ingrese un correo electronico valido.";
			esValido = false;
		}

		if(compCorreoExiste(correo, lista->searchCorreoExiste(correo))){
			cout << "\nSe ha hallado una cuenta existente con ese correo.\n";
			esValido = false;
			return esValido;
		}
		return esValido;
	}

	bool compAliadoPalestino(string correo) {
		regex patronCorreoElectronico("^[a-zA-Z0-9._%+-]+@palestina.mil");
		if (regex_match(correo, patronCorreoElectronico)) return true;
		else return false;
	}

	char ceroIzquierda(int x) {
		if (x / 10 == 0) return '0';
		else return NULL;
	}

	string obtenerFechaActual() {
		time_t t = time(nullptr);
		tm* now = localtime(&t);

		string fechaActual = to_string(now->tm_year + 1900) + "/" + ceroIzquierda(now->tm_mon + 1) + to_string(now->tm_mon + 1) + "/" + ceroIzquierda(now->tm_mday) + to_string(now->tm_mday);

		cout << "Fecha actual: " << fechaActual << endl;
		return fechaActual;
	}


	void crearCuentaCompleta(ListaSimple<Cuenta*>* lista, tm* tPtr) {
		string cargo, apellido, correo, contrasena, pais;
		int  claveCesar = 5;
		string esAliadoPalestino = "NO";
		string fechaCreacion = obtenerFechaActual();
		cout << "Pais: "; cin >> pais;
		cout << "Cargo: "; cin >> cargo;
		cout << "Apellido: "; cin >> apellido;
		cout << "Correo: "; cin >> correo;
		cout << "Contrasena: "; cin >> contrasena;
		if(compAliadoPalestino(correo)) esAliadoPalestino = "SI";

		if (esCuentaValida(apellido, correo, lista)) {
			lista->pushBack(new Cuenta(lista->getLon(), cargo, apellido, correo, contrasena, claveCesar, esAliadoPalestino, pais, fechaCreacion));
			guardar.guardarCuenta(
				to_string(lista->getLon() - 1) + "," + cargo + "," + apellido + "," + correo + "," + contrasena + "," + to_string(claveCesar) + "," + esAliadoPalestino + "," + pais + ", " + fechaCreacion , 
				lista->getLon() - 1);
			// 0,Coronel,Ali,ali@palestina.mil,pass,123,1,Iran
			cout << "\nLa cuenta fue creada y guardada!\n";
		}

	}
};