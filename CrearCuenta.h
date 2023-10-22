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

	bool esNombreValido(string nombre){
		if(nombre.length() < 3) return false;
		else return true;
	}

	bool esApellidoValido(string apellido){
		if(apellido.length() < 2) return false;
		else return true;

	}

	// bool esContrasenaValida(string contra){

	// }

	bool esCuentaValida(string apellido, string correo, ListaSimple<Cuenta*>* lista){

		bool esValido = true;

		/*if (!esNombreValido(nombre)) {
			cout << "\nEl nombre debe tener por lo menos 3 caracteres";
			esValido = false;
		}*/
		if(!esApellidoValido(apellido)) {
			cout << "\nEl apellido debe tener por lo menos 2 caracteres.";
			esValido = false;
		}

		if(!esCorreoValido(correo)) {
			cout << "\nPor favor, ingrese un correo electronico valido.";
			esValido = false;
		}

		// if(!esContrasenaValida(contra)) cout << "\nLa contrasena debe tener mas de 8 caracteres"
		// 
		if(compCorreoExiste(correo, lista->searchCorreoExiste(correo))){
			cout << "\nSe ha hallado una cuenta existente con ese correo.\n";
			esValido = false;
			return esValido;
		}
		return esValido;
	}


	void crearCuentaCompleta(ListaSimple<Cuenta*>* lista) {
		//string nombre, apellido, correo, contra;
		string apellido, correo, contra, cifrado, tipo, pais;
		//cout << "Nombre: "; cin >> nombre;
		cout << "Apellido: "; cin >> apellido;
		cout << "Correo: "; cin >> correo;
		cout << "Password: "; cin >> contra;
		cout << "Cifrado a usar: "; cin >> cifrado;
		cout << "Tipo: "; cin >> tipo;
		cout << "Pais: "; cin >> pais;

		if (esCuentaValida(apellido, correo, lista)) {
			lista->pushBack(new Cuenta(lista->getLon(), apellido, correo, contra, cifrado, tipo, pais));
			guardar.guardarCuenta(to_string(lista->getLon() - 1) + "," + tipo + "," + pais + "," + apellido + "," + correo + "," + contra + "," + cifrado, lista->getLon() - 1);
			cout << "\nLa cuenta fue creada y guardada!\n";
		}
	}
};