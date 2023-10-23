// #ifndef __HASHTABLA_HPP__
// #define __HASHTABLA_HPP__
// #include <iostream>
// #include <vector>
// #include <list>
// #include <string>
// #include "Cuenta.h"

// using namespace std;

// class HashTableA_usuarios {
// private:
// 	vector<list<Cuenta>> theLists;   // Tabla: vector cuyo cada elemento es una Lista de Nodos Hash(key, value)
// 	int  currentSize;	//TamaÃ±o del vector

// public:
// 	explicit HashTableA_usuarios(int size = 11) : currentSize{ 0 }
// 	{
// 		theLists.resize(11);	//Resize al vector, para que tenga 101 elementos: 101 listas de Nodos Hash(key, value)
// 	}

// 	void makeEmpty()
// 	{
// 		for (auto& thisList : theLists)
// 			thisList.clear();
// 	}

// 	bool insert(Cuenta&& x)
// 	{
// 		auto& whichList = theLists[myhash(x.getDni())]; //Del vector, obtenemos la lista de elementos segÃºn el hash(indice) obtenido

// 		whichList.push_back(x); //Agregamos el nuevo elemento(key, value) a la lista del hash(indice)

// 		return true;
// 	}

// 	void DispAll() {
// 		int pos = 0;
// 		for (auto& thisList : theLists) {		// Recorremos el vector<>
// 			cout << "Key: " + to_string(pos) << " | ";
// 			for (auto& it : theLists[pos]) {	// Recorremos la Lista de cada indice del vector	
// 				cout << it.getDni() << ",";		// Imprime key
// 				//cout << "(" << it.getKey() << ", " << it.getValue() << "); ";	// Imprime (key,value)
// 			}
// 			cout << endl;
// 			pos++;
// 		}
// 	}

// 	void buscar(string key) {

// 		int pos = 0;
// 		pos = myhash(key);	//Obtenemos el indice de la Tabla (pos) a partir de la Funcion HASH
// 		cout << "Key: " + to_string(pos) << " | ";
// 		for (auto& it : theLists[pos]) {	// Recorremos la Lista de cada indice del vector	
// 			if (it.getDni() == key)
// 				cout << "(" << it.getDni() << ", " << it.getNombre() << ", " << it.getApellido() << ", " << it.getEdad() << "); ";	// Imprime (key,values)
// 		}
// 		cout << endl;
// 	}


// private:

// 	size_t myhash(const string key) const {
// 		cout << "---------------------------" << endl;
// 		size_t hashVal;
// 		string strKey = key;
// 		cout << "dni:" << strKey << endl;
// 		int sumLtrs = 0;
// 		// Dispersion
// 		for (const char ltr : strKey){
// 			sumLtrs+=int(ltr);
// 		}
// 		cout << "suma letras: " << sumLtrs << endl;
// 		// Compresion
// 		hashVal = sumLtrs % theLists.size();	
// 		cout << "hashVal" << hashVal << endl;
// 		return(hashVal);	
// 	}
// };

// #endif