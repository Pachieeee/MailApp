#pragma once

class Cuenta
{
private:
	int ID;
	string cargo;
	string apellido;
	string correo;
	string contrasena;
	int claveCesar;
	string esAliadoPalestino;
	string pais;
	string fechaCreacion;
public:
	Cuenta() {
		this->ID = 0;
		this->cargo = "";
		this->apellido = "";
		this->correo = "";
		this->contrasena = "";
		this->claveCesar = 0;
		this->esAliadoPalestino = "";
		this->pais = "";
		this->fechaCreacion= "";
	}
	Cuenta(int ID, string cargo, string apellido, string correo, string contrasena, int claveCesar, string esAliadoPalestino, string pais, string fechaCreacion) {
		this->ID = ID;
		this->cargo = cargo;
		this->apellido = apellido;
		this->correo = correo;
		this->contrasena = contrasena;
		this->claveCesar = claveCesar;
		this->esAliadoPalestino = esAliadoPalestino;
		this->pais = pais;
		this->fechaCreacion=fechaCreacion;
	}
	
	int getID() { return this->ID; }
	string getCargo() { return this -> cargo; }
	string getApellido() { return this->apellido; }
	string getCorreo() { return this->correo; }
	string getContrasena() { return this->contrasena; }
	int getClaveCesar() { return this->claveCesar; }
	string getEsAliadoPalestino() { return this->esAliadoPalestino; }
	string getPais() { return this->pais; }
	string getFechaCreacion(){ return this-> fechaCreacion; }
};