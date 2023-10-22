#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Contenido
{
private:
	string tipo;
	string autor;
	string correoAutor;
	string asunto;
	string mensaje;
public:
	Contenido() {
		tipo = "";
		autor = "";
		correoAutor = "";
		asunto = "";
		mensaje = "";
	}
	Contenido(string tipo, string autor, string correo, string asunto, string mensaje) {
		this->tipo = tipo;
		this->autor = autor;
		this->correoAutor = correo;
		this->asunto = asunto;
		this->mensaje = mensaje;
	}
	string getAutor() { return this->autor; }
	void getResumen() {
		cout << autor << " - " << asunto;
	}
	string getTipo() { return this->tipo; }
	void getContenido() {
		cout << "   DE: " << autor << "(" << correoAutor << ")";
		cout << "\n   ----------------------------------------------------------";
		cout << "\n   ASUNTO:" << asunto;
		cout << "\n   ----------------------------------------------------------";
		cout << "\n   " << mensaje;
	}
};