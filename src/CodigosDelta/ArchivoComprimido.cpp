/*
 * ArchivoGamma.cpp
 *
 *  Created on: 19/06/2013
 *      Author: matias
 */

#include "ArchivoComprimido.h"
#include <iostream>
#include "../NombresArchivos.h"


ArchivoComprimido::ArchivoComprimido() {
	this->abrir();
}

ArchivoComprimido::~ArchivoComprimido() {
	this->cerrar();
}

void ArchivoComprimido::abrir() {
	this->file.open(constantes::NombresArchivos::archivoComprimido, std::fstream::in | std::fstream::out | std::fstream::binary);
}

void ArchivoComprimido::cerrar() {
	if (file.is_open())
			file.close();
}

void ArchivoComprimido::setPosicion(long posicion){
	file.seekp(posicion);
}

int ArchivoComprimido::guardarVector(std::vector<unsigned int> vector) {
	char* destino;
	int posPrincipio = file.tellp();
	//Le agrego el tamaño al principio de todo
	vector.insert(vector.begin(),vector.size());
	//Codifico el vector
	unsigned int bits = gamma.codificar(vector.data(), vector.size(), destino);
	unsigned int bytes = (bits - 1)/8 + 1;
	//Lo guardo al archivo
	file.write(destino, bytes);

	return posPrincipio;
}

std::vector<unsigned int> ArchivoComprimido::levantarVector(int posicion) {
	file.clear();
	std::vector<unsigned int> result;
	this->setPosicion(posicion);
	//Armo un buff generoso para el primer número
	char* buf = new char[8];
	file.read(buf, 8);
	file.clear();
	//Leo el largo de la lista (y le agrego el 1er número, que representa el largo)
	int size = gamma.decodificar(buf) + 1;
	//Ahora leo todos los números
	this->setPosicion(posicion);
	delete[] buf;
	buf = new char[size * 8];
	file.read(buf, size * 8);
	file.clear();
	int* intArray = this->gamma.decodificar(buf, size);
	//Y los agrego al vector
	result = std::vector<unsigned int>(intArray + 1, intArray + size);
	delete[] buf;
	return result;
}
