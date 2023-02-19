#include "DeluxeSoba.h"


bool DeluxeSoba::get5G() {
	return this->mreza5G;
}

bool DeluxeSoba::getSPApristup() {
	return this->SPApristup;
}

void DeluxeSoba::dodajGostaUSobu(Gost& g) {
	this->gostSobe = g;
}
