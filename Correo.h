#pragma once
#include "Bandeja.h"
#include "Busqueda.h"
class Correo {
private:
	int usuario;
	Bandeja* inbox;
	Busqueda* busqueda;
public:
	Correo() {
	}
	Correo(int ID) {
		inbox = new Bandeja(ID);
		busqueda = new Busqueda(ID);
	}
	~Correo() {
		inbox->~Bandeja();
		busqueda->~Busqueda();
	}

	void manejarBandeja(string band) {
		char charac = '1'; //Opcion elegida por el usuario
		int pag = 0; //La pagina en la que se encuentra el usuario (max 10 corres/pag)
		int limite = 10; //El limite de correos que se puede presentar en la pagina (segun la pagina)
		int ampliar = 11; //Amplia el correo especificado
		int cantCorreos = inbox->retornarCantCorreos(band);
		if (cantCorreos == 0) {
			cout << "Esta seccion se encuentra vacia. Regresando al inbox.\n";
			return;
		}
		inbox->iniciarContenido(band);

		while (tolower(charac) != 'x') {
			system("cls");
			//revisar limite de los correos
			limite = cantCorreos - pag * 10;
			if (limite > 10) limite = 10;
			inbox->mostrarContenido(pag, limite, ampliar);
			if (pag > 0) { //Mostrara solo si se encuentra en una pagina que no es primera
				cout << "\na: Pagina anterior (" << pag - 1 << ")";
			}
			else if (pag < cantCorreos / 10) { //Mostrara las paginas siguientes hasta el limite de correos
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
		inbox->limpiarSeccion();
	}
	void manejarOpc(int op) {
		switch (op) {
		case 1:
			system("cls");
			manejarBandeja("P");
			break;
		case 2:
			system("cls");
			manejarBandeja("F");
			break;
		case 3:
			system("cls");
			manejarBandeja("S");
			break;
		case 4:
			system("cls");
			manejarBandeja("E");
			break;
		case 5:
			system("cls");
			manejarBandeja("T");
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

	int menuCliente(string apellido) {
		int op;
		system("cls");
		cout << "Bienvenido, " << apellido;
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

	void manejarCorreo(string apellido) {
		int op;
		inbox->iniciarBandeja();
		do {
			op = menuCliente(apellido);
			manejarOpc(op);
			system("pause");
		} while (op > 0 && op < 8);
	}
};