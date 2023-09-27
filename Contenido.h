#pragma once
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
	void getContenido() {
		cout << "\nDE: " << autor << "(" << correoAutor << ")";
		cout << "\n-------------------------------------------------------------";
		cout << "\nASUNTO:" << asunto;
		cout << "\n-------------------------------------------------------------";
		cout << "\n" << mensaje;
	}
};