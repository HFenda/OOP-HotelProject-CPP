#include "Soba.h"

Soba::Soba() {
	this->brKreveta = 1;
	this->stanje= slobodna;
	this->sprat = 1;
	this->brSobe = 0;
	this->saPogledom = 0;
	this->cijenaNocenja = 0;
}

int Soba::getBrSobe() {
	return this->brSobe;
}

int Soba::getSprat() {
	return this->sprat;
}

int Soba::getBrKreveta() {
	return this->brKreveta;
}

bool Soba::getSaPogledom() {
	 return this->saPogledom;
}

float Soba::getCijenaNocenja() {
	return this->cijenaNocenja;
}

StanjeSobe& Soba::getStanje() {
	return this->stanje;
}

