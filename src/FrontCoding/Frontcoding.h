/*
 * Frontcoding.h
 *
 *  Created on: Jun 14, 2013
 *      Author: lucia
 */

#include <iostream>
#include <string.h>
#include <stdio.h>
#include <sstream>
#include <stdlib.h>
#include <string>

#ifndef FRONTCODING_H_
#define FRONTCODING_H_
using namespace std;
namespace frontcoding {

class Frontcoding {
public:

	Frontcoding(FILE* nombreArchivoLexico, FILE* nombreArchivoTabla );

	string compararPorCharDistintos(string uno, string dos, int* cantidad);
	int guardarEnArchivo(string str, int charsDistintos, int offset, int offsetPosiciones);

	void agregarPalabra(string palabra, int offsetPosiciones);

	virtual ~Frontcoding();
private:
	FILE* archIntlexico;
	FILE* archIntTabla;
	string palabraAnterior;
	int offset;

};

} /* namespace frontcoding */
#endif /* FRONTCODING_H_ */
