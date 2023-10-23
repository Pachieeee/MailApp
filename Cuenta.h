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
	bool esAliadoPalestino;
	string pais;
public:
	Cuenta() {
		this->ID = 0;
		this->cargo = "";
		this->apellido = "";
		this->correo = "";
		this->contrasena = "";
		this->claveCesar = 0;
		this->esAliadoPalestino = false;
		this->pais = "";
	}
	Cuenta(int ID, string cargo, string apellido, string correo, string contrasena, int claveCesar, bool esAliadoPalestino, string pais) {
		this->ID = ID;
		this->cargo = cargo;
		this->apellido = apellido;
		this->correo = correo;
		this->contrasena = contrasena;
		this->claveCesar = claveCesar;
		this->esAliadoPalestino = esAliadoPalestino;
		this->pais = pais;
	}
	

	int getID() { return this->ID; }
	string getCargo() { return this -> cargo; }
	string getApellido() { return this->apellido; }
	string getCorreo() { return this->correo; }
	string getContrasena() { return this->contrasena; }
	int getClaveCesar() { return this->claveCesar; }
	bool getEsAliadoPalestino() { return this->esAliadoPalestino; }
	string getPais() { return this->pais; }
};