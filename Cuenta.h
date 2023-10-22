#pragma once

class Cuenta
{
private:
	//string nombre;
	string apellido;
	string correo;
	string contra;
	string cifrado;
	string tipo;
	string pais;
	int ID;
public:
	Cuenta() {
		//this->nombre = "";
		this->apellido = "";
		this->correo = "";
		this->contra = "";
		this->cifrado = "";
		this->tipo = "";
		this->pais = "";
		this->ID = 0;
	}
	Cuenta(int ID, string apellido, string correo, string contra, string cifrado, string tipo, string pais) {
		//this->nombre = nombre;
		this->apellido = apellido;
		this->correo = correo;
		this->contra = contra;
		this->ID = ID;
		this->cifrado = cifrado;
		this->tipo = tipo;
		this->pais = pais;
	}
	

	//string getNombre() { return this->nombre; }
	string getApellido() { return this->apellido; }
	string getCorreo() { return this->correo; }
	string getContra() { return this->contra; }
	string getCifrado() { return this->cifrado; }
	string getTipo() { return this->tipo; }
	string getPais() { return this->pais; }
	int getID() { return this->ID; }
};