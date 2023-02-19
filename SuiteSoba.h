#pragma once
#include "Soba.h"

class SuiteSoba : public Soba
{
public:
	Gost gostSobe;
	int brSoba;
	int brKupatila;
	void setBrSoba();
	void setBrKupatila();
	int getBrSoba();
	int getBrKupatila();
	void dodajGostaUSobu(Gost& g);

};

