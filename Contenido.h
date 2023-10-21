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
	Contenido(string tipo, string autor, string correo, string asunto, string mensaje) {
		this->tipo = tipo;
		this->autor = autor;
		this->correoAutor = correo;
		this->asunto = asunto;
		this->mensaje = mensaje;
	}

	string getAutor() { return this->autor; }
	string getTipo() { return this->tipo; }
	void getContenido() {
		cout << "\nDE: " << autor << "(" << correoAutor << ")";
		cout << "\n-------------------------------------------------------------";
		cout << "\nASUNTO:" << asunto;
		cout << "\n-------------------------------------------------------------";
		cout << "\n" << mensaje;
	}
};