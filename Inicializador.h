#pragma once
#include "Cuenta.h"
#include "Contenido.h"
#include "ListaCuenta.h"
#include "ListaCorreo.h"
#include "ArbolBusqueda.h"
#include "HashTableA_usuarios.h"
#include <sys/stat.h>

#define nombre_archivo "usuarios.csv"

struct stat buffer;

class Inicializador
{
private:
	ifstream lector;
	ofstream guardado;
	ofstream guardaCorreo;
public:
	Inicializador() {
		CrearCarpeta();
		guardaCorreo.open("BD/Correos.csv", ios_base::app);
	}
	void CrearCarpeta() {
		if (stat("BD", &buffer)) system("mkdir BD");
	}

	void generarCuentas() {
		srand(time(NULL));
		//Limpia los datos
		guardado.open("BD/Cuentas.csv", ios::trunc);
		guardado.close();

		//Genera
		guardado.open("BD/Cuentas.csv", ios::in);
		if (guardado.is_open()) {
			time_t t = time(NULL);
			tm* tPtr = localtime(&t);
			vector<string> cargos = { "Presidente", "General", "Coronel", "Teniente", "Subteniente" };
			vector<string> apellidos =
			{ "Verona", "Arevalo", "Quispe", "Belleza", "Sihuincha", "Pacheco", "Carranza", "Chavez",
			"Fernandez", "Linares", "Gutierrez", "Astuyauri", "Julca", "Ramirez", "Morales", "Rojas",
			"Puican", "Romero", "Salas", "Gomez", "Perez", "Jaque", "Yauri", "Cabrera" };
			string fecha = to_string(tPtr->tm_mday) + "/" + to_string(tPtr->tm_mon + 1) + "/" + to_string(tPtr->tm_year + 1900);
			int id = 0;
			string cargo, apellido, correoB, correo;
			char correoA;

			for (int i = 0; i < 50; i++) {
				cargo = cargos[rand() % cargos.size()]; //Elige cargo
				apellido = apellidos[rand() % apellidos.size()]; //Elige apellido
				correoA = tolower(cargo[0]); //Agarra el primer caracter
				correoB = apellido; //Copia el apellido para transformar
				transform(correoB.begin(), correoB.end(), correoB.begin(), ::tolower); //Apellido en minusculas
				correo = correoA + correoB + "@palestina.mil"; //Generar correo

				guardado << id << ',' << cargo << ',' << apellido << ',' << correo << ",12345,5,SI,Palestina," << fecha << "\n";
				id++;
			}
			guardado.close();
		}
	}

	void generarCorreos(int cant, ListaSimple<Cuenta*>* LSCuenta) {
		srand(time(NULL));
		guardado.open("BD/Correos.csv", ios::trunc);
		guardado.close();

		guardado.open("BD/Correos.csv", ios::in);
		if (guardado.is_open()) {
			time_t t = time(NULL);
			tm* tPtr = localtime(&t);
			string fecha = to_string(tPtr->tm_mday) + "/" + to_string(tPtr->tm_mon + 1) + "/" + to_string(tPtr->tm_year + 1900);
			//Datos
			int id; char tipo; Cuenta* autor, *destino; string asunto, conten;
			//Vectores
			vector<char> tipos = { 'P', 'E', 'S', 'F', 'T' };
			vector<string> asuntos = { "Informacion Confidencial", "Fecha de reunion establecida", "URGENTE", "Revisar cuanto antes",
			"Burrito", "Test de envio de correo", "ACCION", "Firmar documento adjuntado", "SOLICITUD DE PERMISO", "Pregunta sobre la reunion",
			"Actualizacion de estado", "Solicitud de vacaciones", "Informe de implementacion laboral"};
			vector<string> contenido = { "Si", "Apruebo esto", "Muchas gracias", "Saludos", "lol", "Aeaaaa", "Responder por favor",
			"Mover la armada cuanto antes"};

			for (int i = 0; i < 10000; i++) {
				autor = LSCuenta->getNodo(rand() % cant);
				destino = LSCuenta->getNodo(rand() % cant);
				id = rand() % cant;
				tipo = tipos[rand() % tipos.size()];
				asunto = asuntos[rand() % asuntos.size()];
				conten = contenido[rand() % contenido.size()];
				guardado << id << '|' << tipo << "|" << autor->getCargo() << " " << autor->getApellido() << "|" << autor->getCorreo() << "|" << destino->getCorreo() << "|" << asunto << "|" << conten << "|" << fecha << "\n";
			}
			guardado.close();
		}
	}
	void inicializarCuentas(ListaSimple<Cuenta*>* lista) {
		lector.open("BD/Cuentas.csv", ios::in);
		if (!lector.is_open())
		{
			cout << "Error: No se pudo abrir el archivo !!!" << endl;
		}
		HashTableA_usuarios ht = HashTableA_usuarios();
		if (lector.is_open()) {
			string linea;
			string id, cargo, apellido, correo, contrasena, claveCesar, esAliadoPalestino, pais, fechaCreacion;

			while (getline(lector, linea)) {
				stringstream stream(linea);
				getline(stream, id, ',');
				getline(stream, cargo, ',');
				getline(stream, apellido, ',');
				getline(stream, correo, ',');
				getline(stream, contrasena, ',');
				getline(stream, claveCesar, ',');
				getline(stream, esAliadoPalestino, ',');
				getline(stream, pais, ',');
				getline(stream, fechaCreacion, ',');
				lista->pushBack(new Cuenta(stoi(id), cargo, apellido, correo, contrasena, stoi(claveCesar), esAliadoPalestino, pais, fechaCreacion));
				ht.insert(Cuenta(stoi(id), cargo, apellido, correo, contrasena, stoi(claveCesar), esAliadoPalestino, pais, fechaCreacion));
			}
			lector.close();
		}
	}
	void inicializarCorreo(ListaDoble<Contenido*>* bandeja, string direc, int idUsuario) {
		lector.open("BD/Correos.csv", ios::in);
		if (lector.is_open()) {
			string linea; //sstream
			string id, tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio;
			char delimit = '|';
			while (getline(lector, linea)) {
				stringstream stream(linea);
				getline(stream, id, delimit);
				if (stoi(id) == idUsuario) { //Si la ID corresponde al usuario
					getline(stream, tipo, delimit);
					getline(stream, autor, delimit);
					getline(stream, correoAutor, delimit);
					getline(stream, correoDestino, delimit);
					getline(stream, asunto, delimit);
					getline(stream, mensaje, delimit);
            getline(stream, fechaEnvio, delimit);
					bandeja->pushBack(new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio));
				}
			}
			lector.close();
		}
	}

	void inicializarBusqueda(ArbolAVL<Contenido*>* busqueda, string direc,string obj, int filtro) {
		lector.open(direc, ios::in);
		if (lector.is_open()) {
			string tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio;
			char delimit = '|';
			while (!lector.eof()) {
				getline(lector, tipo, delimit);
				getline(lector, autor, delimit);
				getline(lector, correoAutor, delimit);
				getline(lector, correoDestino, delimit);
				getline(lector, asunto, delimit);
				getline(lector, mensaje, delimit);
				getline(lector, fechaEnvio, delimit);
				switch (filtro)
				{
				//! Sebas, factoriza el codigo
				case 1:
					if (autor == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio));
					break;
				case 2:
					if (correoAutor == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio));
					break;
				case 3:
					if (asunto == obj) busqueda->Insertar(new Contenido(tipo, autor, correoAutor, correoDestino, asunto, mensaje, fechaEnvio));
					break;
				}
			}
			lector.close();
		}
	}

	void guardarCuenta(string line, int id) {
		guardado.open("BD/Cuentas.csv", ios_base::app);
		guardado << line << endl;
		guardado.close();
	}

	void guardarCorreo(string line, int id){
		//guardaCorreo.open("BD/Correos.csv", ios_base::app);
		cout << "Guardando:\n" << line;
		guardaCorreo << line << endl;
		guardaCorreo.close();
		return;
	}
};