/*
 * ArchivoGenerico.cpp
 *
 *  Created on: 15/06/2013
 *      Author: Guido
 */

#include "ArchivoGenerico.h"
#include "BitStream.h"

ArchivoGenerico::Escritor::Escritor() {

}

ArchivoGenerico::Escritor::~Escritor() {
	archivo.close();
}

void ArchivoGenerico::Escritor::escribirStream(BitStream* bitStream) {
	this->stream.appendStream(bitStream);
}

void ArchivoGenerico::Escritor::escribirUnsigned(unsigned int integer) {
	this->stream.appendInteger(integer);
	/*char* array = 0;
	ArchivoGenerico::empaquetarUnsigned(array, integer);
	archivo.write(array, sizeof(unsigned int));
	delete[] array;*/
}

void ArchivoGenerico::Escritor::escribirSize(size_t size) {
	this->stream.appendSize(size);
	/*char* array = 0;
	ArchivoGenerico::empaquetarSize(array, size);
	archivo.write(array, sizeof(size_t));
	delete[] array;*/
}

void ArchivoGenerico::Escritor::escribirString(std::string string) {
	this->stream.appendString(string);
	/*char* array = 0;
	ArchivoGenerico::empaquetarString(array, string);
	archivo.write(array, string.size());
	delete[] array;*/
}

void ArchivoGenerico::Escritor::escribirBit(tBit bit) {
	this->stream.appendBit(bit);
}

int ArchivoGenerico::Escritor::abrir(std::string ruta) {
	archivo.open(ruta.c_str(), std::ios::in);
}

int ArchivoGenerico::Escritor::cerrar() {
	archivo.close();
}

/*IMPORTANTE
 *Solo se bajan cosas a disco cuando se usa esto*/
void ArchivoGenerico::Escritor::flush() {
	char* array = 0;
	unsigned int size = 0;
	this->stream.flush(array, size);
	archivo.write(array, size);
}

void ArchivoGenerico::Escritor::rellenarBits() {
	this->stream.rellenarBits();
}
