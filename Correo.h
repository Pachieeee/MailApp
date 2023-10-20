#pragma once
#include "Inbox/CPrincipal.h"
#include "Inbox/CSpam.h"
#include "Inbox/CEnviado.h"
#include "Inbox/CPapelera.h"
#include "Inbox/CFijado.h"
#include "Busqueda.h"
class Correo {
private:
	int usuario; //a
	CPrincipal* principal;
	CSpam* spam;
	CEnviado* enviado;
	CPapelera* papelera;
	CFijado* fijado;
	Busqueda* busqueda;
public:
	Correo() {
	}
	Correo(int ID) {
		principal = new CPrincipal(ID);
		spam = new CSpam(ID);
		enviado = new CEnviado(ID);
		papelera = new CPapelera(ID);
		fijado = new CFijado(ID);
		busqueda = new Busqueda(ID);
	}
	~Correo() {
		principal->~CPrincipal();
		spam->~CSpam();
		enviado->~CEnviado();
		papelera->~CPapelera();
		fijado->~CFijado();
		busqueda->~Busqueda();
	}
	void iniciarContenido() {
		principal->iniciarContenidoPrincipal();
		spam->iniciarContenidoSpam();
		enviado->iniciarContenidoEnviado();
		papelera->iniciarContenidoPapelera();
		fijado->iniciarContenidoFijado();
		cout << endl;
		system("pause");
	}

	void manejarPrincipal() {
		char charac = '1';
		int pag = 0; //La pagina en la que se encuentra el usuario (max 10 corres/pag)
		int limite = 10; //El limite de correos que se puede presentar. (temp)
		int ampliar = 11; //What the fuck is this
		int cantCorreos = principal->retornarCantCorreos(); // 
		while (tolower(charac) != 'x') {
			system("cls");
			//revisar limite de los correos
			limite = cantCorreos - pag * 10;
			if (limite > 10) limite = 10;
			principal->mostrarContenidoPrincipal(pag, limite, ampliar);
			if (pag > 0) {
				cout << "\na: Pagina anterior (" << pag - 1 << ")";
			}
			if (pag < cantCorreos / 10) {
				cout << "\ns: Pagina siguiente (" << pag + 1 << ")";
			}
			cout << "\nx: Volver al menu\n\n";
			cout << pag*10+1 << " - " << pag * 10 + limite << " / " << cantCorreos << endl;
			cout << "Opcion: "; charac = cin.get();
			//Pagina anterior
			if (tolower(charac) == 'a' && pag > 0) {
				pag--;
				ampliar = 11;
			}
			//Pagina siguiente
			else if (tolower(charac) == 's' && pag < cantCorreos/10) {
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

	void manejarOpc(int op) {
		switch (op) {
		case 1:
			system("cls");
			manejarPrincipal();
			//principal->mostrarContenidoPrincipal(0);
			break;
		case 2:
			system("cls");
			fijado->mostrarContenidoFijado();
			break;
		case 3:
			system("cls");
			spam->mostrarContenidoSpam();
			break;
		case 4:
			system("cls");
			enviado->mostrarContenidoEnviado();
			break;
		case 5:
			system("cls");
			papelera->mostrarContenidoPapelera();
			break;
		case 6:
			system("cls");;
			principal->ordenarPorInicialAutor();
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

	int menuCliente(string nombre) {
		int op;
		system("cls");
		cout << "Bienvenido, " << nombre;
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

	void manejarCorreo(string nombre) {
		int op;
		iniciarContenido();
		do {
			op = menuCliente(nombre);
			manejarOpc(op);
			system("pause");
		} while (op > 0 && op < 8);
	}
};