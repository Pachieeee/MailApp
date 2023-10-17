#pragma once

#include <iostream>
#include <fstream>
#include <string>

class Contenido
{
private:
	string autor;
	string correoAutor;
	string asunto;
	string mensaje;
public:
	Contenido() {
		autor = "";
		correoAutor = "";
		asunto = "";
		mensaje = "";
	}
	
	Contenido(string autor, string correo, string asunto, string mensaje) {
		this->autor = autor;
		this->correoAutor = correo;
		this->asunto = asunto;
		this->mensaje = mensaje;
	}

	string getAutor() { return this->autor; }
	void getResumen() {
		cout << autor << " - " << asunto;
	}
	void getContenido() {
		cout << "   DE: " << autor << "(" << correoAutor << ")";
		cout << "\n   ----------------------------------------------------------";
		cout << "\n   ASUNTO:" << asunto;
		cout << "\n   ----------------------------------------------------------";
		cout << "\n   " << mensaje;
	}
};