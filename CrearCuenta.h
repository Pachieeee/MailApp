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

	bool verificarCorreoExistente(string correo, ListaSimple<Cuenta*>* lista) {
		return compCorreoExiste(correo, lista->searchCorreoExiste(correo));
	}

	void crearCuentaCompleta(ListaSimple<Cuenta*>* lista) {
		string nombre, apellido, correo, contra;
		cout << "Nombre: "; cin >> nombre;
		cout << "Apellido: "; cin >> apellido;
		cout << "Correo: "; cin >> correo;
		cout << "Password: "; cin >> contra;
		if (!verificarCorreoExistente(correo, lista)) {
			lista->pushBack(new Cuenta(nombre, apellido, correo, contra, lista->getLon()));
			guardar.guardarCuenta(nombre + "," + apellido + "," + correo + "," + contra + "," + to_string(lista->getLon()-1), lista->getLon()-1);

			cout << "\nLa cuenta fue creada y guardada!\n";
		}
		else
			cout << "\nSe ha hallado una cuenta existente con ese correo.\n";
	}
};