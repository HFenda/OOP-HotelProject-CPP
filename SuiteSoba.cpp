#include "SuiteSoba.h"

int SuiteSoba::getBrSoba() {
	return this->brSoba;
}

int SuiteSoba::getBrKupatila() {
	return this->brKupatila;
}

void SuiteSoba::dodajGostaUSobu(Gost& g) {
	this->gostSobe = g;
}