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
	string fechaEnvio;
	Contenido *next;
	Contenido *prev;
public:
	Contenido() {
		tipo = "";
		autor = "";
		correoAutor = "";
		asunto = "";
		mensaje = "";
		fechaEnvio = "";
	}
	Contenido(string tipo, string autor, string correo, string asunto, string mensaje, string fecha) {
		this->tipo = tipo;
		this->autor = autor;
		this->correoAutor = correo;
		this->asunto = asunto;
		this->mensaje = mensaje;
		this->fechaEnvio = fecha;
	}
	string getAutor() { return this->autor; }
	string getTipo() {return this-> tipo; }
	string getCorreoAutor() {return this-> correoAutor;}
	string getAsunto() {return this-> asunto; }
	string getMensaje() {return this-> mensaje; }
	string getFechaEnvio() { return this-> fechaEnvio; }

	// ??
	void getResumen() {
		cout << autor << " - " << asunto;
	}
	string getTipo() { return this->tipo; }

	void getContenido() {
		cout << "   DE: " << autor << "(" << correoAutor << ")" << fechaEnvio;
		cout << "\n   ----------------------------------------------------------";
		cout << "\n   ASUNTO:" << asunto;
		cout << "\n   ----------------------------------------------------------";
		cout << "\n   " << mensaje;
	}
};