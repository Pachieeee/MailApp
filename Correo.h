#pragma once
#include "Bandeja.h"
#include "Busqueda.h"
#include "EnviarCorreoQueue.h"
class Correo {
private:
	int usuario;
	EnviarCorreoQueue* sendMail;
	Bandeja* inbox;
	Busqueda* busqueda;
	ListaDoble<Contenido*>* LSCorreo;
	Inicializador* generar;		
public:
	Correo() {
		LSCorreo = new ListaDoble<Contenido*>();
		generar = new Inicializador();
	}
	Correo(int ID) {
		inbox = new Bandeja(ID);
		busqueda = new Busqueda(ID);
	}
	~Correo() {
		inbox->~Bandeja();
		busqueda->~Busqueda();
	}
	void manejarPrincipal() {
		char charac = '1';
		int pag = 0; //La pagina en la que se encuentra el usuario (max 10 corres/pag)
		int limite = 10; //El limite de correos que se puede presentar. (temp)
		int ampliar = 11; //What the fuck is this
		int cantCorreos = inbox->retornarCantCorreos("P");
		while (tolower(charac) != 'x') {
			system("cls");
			//revisar limite de los correos
			limite = cantCorreos - pag * 10;
			if (limite > 10) limite = 10;
			inbox->mostrarContenidoPrincipal(pag, limite, ampliar);
			
			if (pag > 0) {
				cout << "\na: Pagina anterior (" << pag - 1 << ")";
			}
			if (pag < cantCorreos / 10) {
				cout << "\ns: Pagina siguiente (" << pag + 1 << ")";
			}
			cout << "\nx: Volver al menu\n\n";
			cout << pag * 10 + 1 << " - " << pag * 10 + limite << " / " << cantCorreos << endl;
			cout << "Opcion: "; charac = cin.get();
			//Pagina anterior
			if (tolower(charac) == 'a' && pag > 0) {
				pag--;
				ampliar = 11;
			}
			//Pagina siguiente
			else if (tolower(charac) == 's' && pag < cantCorreos / 10) {
				pag++;
				ampliar = 11;
			}
			//Numero de correo en pagina actual
			else if (charac > 47 && charac < 58) {
				ampliar = (int)charac - 49;
				if (ampliar == -1)
					ampliar = 9;
			}
		}
	}
	//  tipo, autor, correoAutor
	// id, esAliadoPalestino, correoAutor, apellido, op)
	void manejarOpc(int id, string esAliadoPalestino, string correoAutor, string apellido, int op) {
		switch (op) {
		case 0:
			system("cls");
			cout << "Ingresaste a la funcion para enviar correo" << endl;
			// sendMail->iniciarContenidoEnviado();
			sendMail->enqueue(id, esAliadoPalestino, correoAutor, apellido);
			break;
		case 1:
			system("cls");
			//manejarPrincipal);
			//inbox->mostrarBandeja('P');
			manejarPrincipal();
			break;
		case 2:
			system("cls");
			inbox->mostrarBandeja("F");
			break;
		case 3:
			system("cls");
			inbox->mostrarBandeja("S");
			break;
		case 4:
			system("cls");
			inbox->mostrarBandeja("E");
			break;
		case 5:
			system("cls");
			inbox->mostrarBandeja("T");
			break;
		case 6:
			system("cls");;
			inbox->ordenarPorInicialAutor();
			break;
		case 7:
			system("cls");
			busqueda->menuBusqueda();
			break;
		case 8:
			break;
		default:
			cout << "Opcion erronea.";
			break;
		}
	}

	int menuCliente(string apellido, string cargo) {
		int op;
		system("cls");
		//! El cargo y apellido sale mal
		cout << "\nBienvenido, " << cargo << " "<< apellido;
		cout << "\n0. [Enviar mensaje]";
		cout << "\n1. Ver inbox principal";
		cout << "\n2. Ver inbox fijado";
		cout << "\n3. Ver inbox spam";
		cout << "\n4. Ver inbox enviado";
		cout << "\n5. Ver inbox papelera";
		cout << "\n6. Ordenar principal por autor";
		cout << "\n7. Buscar mensaje";
		cout << "\n8. Cerrar sesion";
		cout << "\nOpcion: "; cin >> op;
		return op;
	}

	void manejarCorreo(int id, string esAliadoPalestino, string correoAutor, string apellido, string cargo) {
		int op;
		inbox->iniciarBandeja();
		//! Inicializar correos mal
		// generar->inicializarCorreos(LSCorreo);
		do {
			op = menuCliente(apellido, cargo);
			manejarOpc(id, esAliadoPalestino, correoAutor, apellido, op);
			system("pause");
		} while (op > 0 && op < 8);
	}
};