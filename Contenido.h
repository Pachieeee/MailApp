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
	string correoDestino;
	string asunto;
	string mensaje;
	string fechaEnvio;
public:
	Contenido *next;
	Contenido *prev;
	Contenido() {
		tipo = "";
		autor = "";
		correoAutor = "";
		correoDestino = "";
		asunto = "";
		mensaje = "";
		fechaEnvio = "";
	}
	Contenido(string tipo, string autor, string correoAutor, string correoDestino, string asunto, string mensaje, string fechaEnvio) {
		this->tipo = tipo;
		this->autor = autor;
		this->correoAutor = correoAutor;
		this->correoDestino = correoDestino;
		this->asunto = asunto;
		this->mensaje = mensaje;
		this->fechaEnvio = fechaEnvio;
	}
	string getAutor() { return this->autor; }
	string getTipo() {return this-> tipo; }
	string getCorreoAutor() {return this-> correoAutor;}
	string getCorreoDestino() {return this-> correoDestino;}
	string getAsunto() {return this-> asunto; }
	string getMensaje() {return this-> mensaje; }
	string getFechaEnvio() { return this-> fechaEnvio; }

	// ??
	void getResumen() {
		cout << autor << " - " << asunto;
	}
	string getTipo() { return this->tipo; }

	void getContenido() {
		cout << "\n   DE: " << autor << "(" << correoAutor << ")" << fechaEnvio;
		cout << "\n   PARA: " << "(" << correoDestino << ")" ;
		cout << "\n   ----------------------------------------------------------";
		cout << "\n   ASUNTO:" << asunto;
		cout << "\n   ----------------------------------------------------------";
		cout << "\n   " << mensaje;
	}
};