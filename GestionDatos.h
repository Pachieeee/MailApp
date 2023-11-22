#ifndef __GESTION_H__
#define __GESTION_H__

#include"Grafo.h"
#include<iostream>
#include <fstream>	//Gestion de Archivo
#include <string>	//getline
#include <sstream>	//stream

using namespace std;

class GestionDatos
{
private:
	CGrafo<int>* G = NULL;
	string nombre_archivo_2;

	// Matriz de Adyacencia
	int num_nodos = 9;
	int MatrizAdy[9][9];

public:
	GestionDatos();
	~GestionDatos();

	void Grafo_GenerarDatos();
	void Grafo_MostrarDatos();
	void CaminoCostoMinimo(int nodoInicio);

	void Grafo_LeerDatosDeArchivo();
	void Grafo_GenerarDatos_MatrizAdyacencia();
	void Grafo_MostrarMatrizAdyacencia();
	void Grafo_GenerarDatos_desde_MatrizAdy();

};

GestionDatos::GestionDatos()
{
	G = new CGrafo<int>();
	nombre_archivo_2 = "GrafoDatos_MatrizAdy.csv";
}
GestionDatos::~GestionDatos() 
{
	if (G != NULL) delete G;
}

void GestionDatos::Grafo_GenerarDatos()
{
	//Agregar Vértices
	G->adicionarVertice(0); //indice=0
	G->adicionarVertice(1); //indice=1
	G->adicionarVertice(2); //indice=2
	G->adicionarVertice(3); //indice=3
	G->adicionarVertice(4); //indice=4
	G->adicionarVertice(5); //indice=5
	G->adicionarVertice(6); //indice=6
	G->adicionarVertice(7); //indice=7
	G->adicionarVertice(8); //indice=8

	//Agregar los arcos
		// G->adicionarArco(posVertice, Vertice);
		// G->modificarArco(posVertice, posArco, pesoArco);

	//Vertice 0
	G->adicionarArco(0, 1); //0 -> 1, Arco posicion 0
	G->modificarArco(0, 0, 4);
	G->adicionarArco(0, 7);	//0 -> 7, Arco posicion 1
	G->modificarArco(0, 1, 8);

	//Vertice 1
	G->adicionarArco(1, 0); //1 -> 0, Arco posicion 0
	G->modificarArco(1, 0, 4);
	G->adicionarArco(1, 2); //1 -> 2, Arco posicion 1
	G->modificarArco(1, 1, 8);
	G->adicionarArco(1, 7); //1 -> 7, Arco posicion 2
	G->modificarArco(1, 2, 11);

	//Vertice 2
	G->adicionarArco(2, 1); //2 -> 1, Arco posicion 0
	G->modificarArco(2, 0, 8);
	G->adicionarArco(2, 3); //2 -> 3, Arco posicion 1
	G->modificarArco(2, 1, 7);
	G->adicionarArco(2, 8); //2 -> 8, Arco posicion 2
	G->modificarArco(2, 2, 2);

	//Vertice 3
	G->adicionarArco(3, 2); //3 -> 2, Arco posicion 0
	G->modificarArco(3, 0, 7);
	G->adicionarArco(3, 4); //3 -> 4, Arco posicion 1
	G->modificarArco(3, 1, 9);
	G->adicionarArco(3, 5); //3 -> 5, Arco posicion 2
	G->modificarArco(3, 2, 14);

	//Vertice 4
	G->adicionarArco(4, 3); //4 -> 3, Arco posicion 0
	G->modificarArco(4, 0, 9);
	G->adicionarArco(4, 5); //4 -> 5, Arco posicion 1
	G->modificarArco(4, 1, 10);

	//Vertice 5
	G->adicionarArco(5, 2); //5 -> 2, Arco posicion 0
	G->modificarArco(5, 0, 4);
	G->adicionarArco(5, 3); //5 -> 3, Arco posicion 1
	G->modificarArco(5, 1, 14);
	G->adicionarArco(5, 4); //5 -> 4, Arco posicion 2
	G->modificarArco(5, 2, 10);
	G->adicionarArco(5, 6); //5 -> 6, Arco posicion 3
	G->modificarArco(5, 3, 2);

	//Vertice 6
	G->adicionarArco(6, 5); //6 -> 5, Arco posicion 0
	G->modificarArco(6, 0, 2);
	G->adicionarArco(6, 7); //6 -> 7, Arco posicion 1
	G->modificarArco(6, 1, 1);
	G->adicionarArco(6, 8); //6 -> 8, Arco posicion 2
	G->modificarArco(6, 2, 6);

	//Vertice 7
	G->adicionarArco(7, 0); //7 -> 0, Arco posicion 0
	G->modificarArco(7, 0, 8);
	G->adicionarArco(7, 1); //7 -> 1, Arco posicion 1
	G->modificarArco(7, 1, 11);
	G->adicionarArco(7, 6); //7 -> 6, Arco posicion 2
	G->modificarArco(7, 2, 1);
	G->adicionarArco(7, 8); //7 -> 8, Arco posicion 3
	G->modificarArco(7, 3, 7);

	//Vertice 8
	G->adicionarArco(8, 2); //8 -> 2, Arco posicion 0
	G->modificarArco(8, 0, 2);
	G->adicionarArco(8, 6); //8 -> 6, Arco posicion 1
	G->modificarArco(8, 1, 6);
	G->adicionarArco(8, 7); //8 -> 7, Arco posicion 2
	G->modificarArco(8, 2, 7);
}

void GestionDatos::Grafo_LeerDatosDeArchivo()
{
	ifstream archIN;
	archIN.open(nombre_archivo_2, ios::in); //Apertura
	
	if (!archIN.is_open())
	{
		cout << "Error: No se pudo abrir el archivo !!!" << endl;
		exit(1);
	}

	string linea;
	char delimitador = '|';

	// Encabezado: Leemos la primer l nea para descartarla, pues es el encabezado
	//getline(archIN, linea);

	// Contenido: Leemos todas las lineas
	int f = 0; // Numero de Lineas del Archivo
	while (getline(archIN, linea))
	{
		stringstream stream(linea); // Convertir la cadena a un stream

		string col;
		// Extraer todos los valores de esa fila
		for (int c = 0; c < num_nodos; c++) // Recorremos las columna de la linea(fila)
		{
			getline(stream, col, delimitador);
			MatrizAdy[f][c] = stoi(col); // string to int
		}
		++f; //Aumentamos la Fila
	}

	archIN.close();
}

void GestionDatos::Grafo_MostrarMatrizAdyacencia()
{
	// Mostramos la Matriz de Adyacencia
	cout << "\n\n[Matriz de Adyacencia - Paises Aliados]" << endl;
	for (int i = 0; i < num_nodos; i++)
	{
		for (int j = 0; j < num_nodos; j++)
		{
			cout.width(3);
			cout << MatrizAdy[i][j];
		}
		cout << endl;
	}
}

void GestionDatos::Grafo_GenerarDatos_desde_MatrizAdy()
{
	int posVertice;
	int posArco;

	for (int i = 0; i < num_nodos; i++)
	{
		//Agregar Vértices
		posVertice = G->adicionarVertice(i); //indice i

		for (int j = 0; j < num_nodos; j++)
		{
			//Agregar los arcos
			//		G->adicionarArco(posVertice, Vertice);
			//		G->modificarArco(posVertice, posArco, pesoArco);

			if (MatrizAdy[i][j] != 0) // Si son vertices adyacentes
			{
				posArco = G->adicionarArco(i, j); //i -> j, Arco posicion i
				G->modificarArco(posVertice, posArco, MatrizAdy[i][j]);
			}
		}
	}
}

void GestionDatos::Grafo_GenerarDatos_MatrizAdyacencia()
{
	// Leemos los datos del grafo desde el archivo a la Matriz de Adyacencia
	Grafo_LeerDatosDeArchivo();

	// Mostrar Matruz de Adyacencia
	Grafo_MostrarMatrizAdyacencia();

	// Cargamos la Matriz de Adyacencia en el Grafo
	Grafo_GenerarDatos_desde_MatrizAdy();
}

void GestionDatos::Grafo_MostrarDatos() 
{
	//Imprimir los vértices con sus arcos
	for (int i = 0; i < G->cantidadVertices(); ++i) {
		cout << "Pais[" << i << "]: " << G->obtenerVertice(i) << endl;
		for (int j = 0; j < G->cantidadArcos(i); j++)
		{
			cout << "\tRed[" << j << "]: " << G->obtenerVerticeLlegada(i, j) << ", tiempo para enviar un mensaje: " << G->obtenerArco(i, j) << " ";
		}
		cout << endl;
	}
}

void GestionDatos::CaminoCostoMinimo(int nodoInicio)
{
	// Dijkstra desde el Origen: Vertice: 0
	G->dijkstra(nodoInicio);
}

#endif // __GESTION_H__