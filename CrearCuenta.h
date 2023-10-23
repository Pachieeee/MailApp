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


	void crearCuentaCompleta(ListaSimple<Cuenta*>* lista) {
		string cargo, apellido, correo, contrasena, pais;
		int  claveCesar = 5;
		bool esAliadoPalestino = false;
		cout << "Pais: "; cin >> pais;
		cout << "Cargo: "; cin >> cargo;
		cout << "Apellido: "; cin >> apellido;
		cout << "Correo: "; cin >> correo;
		cout << "Contrasena: "; cin >> contrasena;

		if (esCuentaValida(apellido, correo, lista)) {
			lista->pushBack(new Cuenta(lista->getLon(), cargo, apellido, correo, contrasena, claveCesar, esAliadoPalestino, pais));
			guardar.guardarCuenta(to_string(lista->getLon() - 1) + "," + cargo + "," + apellido + "," + correo + "," + to_string(claveCesar) + "," + pais , lista->getLon() - 1);
			cout << "\nLa cuenta fue creada y guardada!\n";
		}
	}
};