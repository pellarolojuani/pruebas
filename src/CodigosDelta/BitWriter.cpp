/*
 * BitWriter.cpp
 *
 *  Created on: 17/06/2013
 *      Author: matias
 */

#include "BitWriter.h"

BitWriter::BitWriter() {
	// TODO Auto-generated constructor stub

}

BitWriter::~BitWriter() {
	// TODO Auto-generated destructor stub
}

void BitWriter::crearBuffer(int size) {
	this->cadena = new char[size];
	for (int i= 0; i<size; i++){
		cadena[i] = 0;
	}
	this->mask = 1;
	this->posicion = 0;
}

void BitWriter::grabarBit(bool bit) {
	//Me aseguro que true sea 1
	char mask = 0;
	if (bit != 0)
		mask = 1;
	//Desplazo el bit a la posicion correspondiente
	unsigned int i;
	for (i = 0; i< (posicion & 7); i++){ //&7 es como hacer %8
		mask = mask << 1;
	}
	//Lo guardo en el char correspondiente y lo pongo en la cadena
	char nuevo = (this->cadena[posicion >> 3]) | mask; // >> 3 es como hacer /8
	this->cadena[posicion/8] = nuevo;
	//Avanzo posicion
	posicion++;
}

char* BitWriter::obtenerCadena() {
	return this->cadena;
}


