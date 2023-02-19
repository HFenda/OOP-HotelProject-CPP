#include "StandardSoba.h"

bool StandardSoba::getKingSizeKrevet() {
	return this->kingSizeKrevet;
}

bool StandardSoba::getFlatScreenTV() {
	return this->flatScreenTV;
}

void StandardSoba::dodajGostaUSobu(Gost& g) {
	this->gostSobe = g;
}