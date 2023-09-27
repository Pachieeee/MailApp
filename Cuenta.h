#pragma once

class Cuenta
{
private:
	string nombre;
	string apellido;
	string correo;
	string contra;
	int ID;
public:
	Cuenta() {
		this->nombre = "";
		this->apellido = "";
		this->correo = "";
		this->contra = "";
		this->ID = 0;
	}
	Cuenta(string nombre, string apellido, string correo, string contra, int ID) {
		this->nombre = nombre;
		this->apellido = apellido;
		this->correo = correo;
		this->contra = contra;
		this->ID = ID;
	}

	string getNombre() { return this->nombre; }
	string getApellido() { return this->apellido; }
	string getCorreo() { return this->correo; }
	string getContra() { return this->contra; }
	int getID() { return this->ID; }
};