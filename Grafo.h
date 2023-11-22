#ifndef __GRAFO_HPP__
#define __GRAFO_HPP__

#include <vector>
#include <climits>
using namespace std;

//#define V 9

template<class T, T vacio = -1>
class CGrafo {
private:
	class CArco {
	public:
		T info;
		int v; //indice del vertice de llegada del Arco
		CArco(int vLlegada) {
			info = vacio;
			v = vLlegada;
		}
	};

	class CVertice {
	public:
		T info;
		vector<CArco*>* ady; //Lista(Vector) de adyacencia
		CVertice() {
			info = vacio;
			ady = new vector<CArco*>();
		}
	};

	//Vector(o "Lista") de vértices
	vector<CVertice*>* vertices;

public:
	CGrafo() {
		vertices = new vector<CVertice*>();
	}

	//Operaciones del Grafo
	int adicionarVertice(T info) {
		CVertice* vert = new CVertice();
		vert->info = info;
		vertices->push_back(vert);
		return vertices->size() - 1; //retorna posicion del vertice agregado (al final)
	}

	int cantidadVertices() {
		return vertices->size();
	}

	T obtenerVertice(int v) { //Obtener Vertice dado su posicion en el vector
		return (vertices->at(v))->info;
	}
	void modificarVertice(int v, T info) { //"v" es el indice/posicion del vector de Vertices
		(vertices->at(v))->info = info;
	}
	//Operaciones del arco
	int adicionarArco(int v, int vLlegada) { //v: posicion del vertice | vLlegada: vertice de llegada del Arco
		CVertice* ver = vertices->at(v);
		//Crear el objeto ARCO
		CArco* arc = new CArco(vLlegada);
		ver->ady->push_back(arc);
		return ver->ady->size() - 1; //Indice del Arco ingresado
	}

	int cantidadArcos(int v) {
		return (vertices->at(v))->ady->size();
	}

	//Peso del Arco
	T obtenerArco(int v, int apos) { //v: posicion del vertice | apos: posicion del arco
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->info;
	}

	void modificarArco(int v, int apos, T info) {	//v: posicion del vertice | apos: posicion de la lista de adyacencia
		CVertice* ver = vertices->at(v);
		(ver->ady->at(apos))->info = info;
	}

	int obtenerVerticeLlegada(int v, int apos) { //v: posicion del vertice | apos: posicion del arco
		CVertice* ver = vertices->at(v);
		return (ver->ady->at(apos))->v; //indice del vertice de llegada
	}

	int obtenerVerticeLlegada2(int v, int dst) { //v: posicion del vertice | info: peso del arco
		CVertice* ver = vertices->at(v);
		for (int j = 0; j < cantidadArcos(v); j++)
		{
			int verticeLlegada = (ver->ady->at(j))->v;
			if (verticeLlegada == dst) // si el indice de la Lista de Ady es igual al vertice destino
			{
				return j; //indice del vertice de llegada
			}
		}
		return -1; // No estan conectados v -> dst
	}


	// ------- Algoritmo Dijkstra --------

	// A utility function to print the constructed distance
	// array
	void printSolutionDijkstra(int dist[])
	{
		const int V = cantidadVertices();
		cout << "\n\n[Pais] \t -  [Costo por enviar un mensaje entre un pais aliado a Palestina]" << endl;
        vector<string> paisesAliados = {"Siria", "EE.UU.", "Francia", "Alemania", "Espan;a", "Irlanda", "Dinamarca", "Colombia", "Cuba"};
		for (int i = 0; i < V; i++)
            cout << paisesAliados[i] << " \t\t\t\t" << dist[i] << endl;
        cout << "\n --------------------------------------------------------------------------------"
	};

	// A utility function to find the vertex with minimum
	// distance value, from the set of vertices not yet included
	// in shortest path tree
	int minDistance(int dist[], bool sptSet[])
	{
		// Initialize min value
		int min = INT_MAX, min_index;
		const int V = cantidadVertices();
		for (int v = 0; v < V; v++)
			if (sptSet[v] == false && dist[v] <= min)
				min = dist[v], min_index = v;

		return min_index;
	}

	///*
	// Function that implements Dijkstra's single source
	// shortest path algorithm for a graph represented using
	// adjacency matrix representation
	void dijkstra(int src)
	{
		//const int V = cantidadVertices();
		const int V = 9;
		int dist[V];	// The output array.  dist[i] will hold the
						// shortest
						// distance from src to i

		bool sptSet[V]; // sptSet[i] will be true if vertex i is
						// included in shortest
		// path tree or shortest distance from src to i is
		// finalized

		// Initialize all distances as INFINITE and stpSet[] as
		// false
		for (int i = 0; i < V; i++)
			dist[i] = INT_MAX, sptSet[i] = false;

		// Distance of source vertex from itself is always 0
		dist[src] = 0;

		// Find shortest path for all vertices
		for (int count = 0; count < V - 1; count++) {
			// Pick the minimum distance vertex from the set of
			// vertices not yet processed. u is always equal to
			// src in the first iteration.
			int u = minDistance(dist, sptSet);
			//cout << "u = " << u << endl; //For TEST

			// Mark the picked vertex as processed
			sptSet[u] = true;

			// Update dist value of the adjacent vertices of the
			// picked vertex.
			for (int v = 0; v < V; v++)
			{
				// Update dist[v] only if is not in sptSet,
				// there is an edge from u to v, and total
				// weight of path from src to  v through u is
				// smaller than current value of dist[v]

				//cout << "\tv = " << v << endl;	//For TEST
				int j = obtenerVerticeLlegada2(u, v); // [REZC] Pos del vertice de Llegada en la ListAdy de los Arcos del vertice origen
				//cout << "\tj[antes] = " << j << endl;	//For TEST

				if (j != -1 && !sptSet[v] && obtenerArco(u, j)
					&& dist[u] != INT_MAX
					&& dist[u] + obtenerArco(u, j) < dist[v])
				{
					//cout << "\tj[IF] = " << j << endl;	//For TEST
					dist[v] = dist[u] + obtenerArco(u, j);
				}

			}
		}

		// print the constructed distance array
		printSolutionDijkstra(dist);
	}
	//*/
};

#endif // !__GRAFO_HPP__