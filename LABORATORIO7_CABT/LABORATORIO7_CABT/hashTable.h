#pragma once

#include <iostream>
#include <list>
#include <cstring>

using namespace std;

class hashTable
{

	//DECLARACIÓN DE COMPONENTES NECESARIOS PARA REALIZAR NUESTRA HASH TABLE
public:
	static const int hashGroups = 10;
	list<pair<int, int>> table[hashGroups]; //List 1, Index 0, List 2, Index 1...

	//DECLARACIÓN DE LOS MÉTODOS QUE EMPLEAREMOS EN NUESTRO PROGRAMA
public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, int value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();
};

//MÉTODO PARA VALIDAR SI LA LISTA ESTA VACÍA
bool hashTable::isEmpty() const {
	int sum{};
	for (int i{}; i < hashGroups; i++) {
		sum = sum + table[i].size();
	}

	if (!sum) {
		return true;
	}

	return false;
}

//MÉTODO PARA ESTABLECER LA FUNCIÓN HASH
int hashTable::hashFunction(int key) {
	return key % hashGroups;
}

//MÉTODO PARA PODER INSERTAR UN ELEMENTO EN NUESTRA LISTA
void hashTable::insertItem(int key, int value) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (; bItr != end(cell); bItr++) {
		
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			cout << "[WARNING] Key exists. Value replaced" << "\r\n";
			break;
		}
	}

	if (!keyExists) {
		cell.emplace_back(key, value);
	}

	return;
}

//MÉTODO PARA ELIMINAR ELEMENTOS DE NUESTRA LISTA
void hashTable::removeItem(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;

	for (; bItr != end(cell); bItr++) {

		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "[INFO] value removed." << "\r\n";
			break;
		}
	}

	if (!keyExists) {
		cout << "[WARNING] Key not found. Pair not removed" << "\r\n";
	}

	return;
}

//MÉTODO PARA PODER IMPRIMIR NUESTRA TABLA HASH
void hashTable::printTable() {
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "[INFO] Key: " << bItr->first << " Value: " << bItr->second << "\r\n";
		}
	}

	return;
}