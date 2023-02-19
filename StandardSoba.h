#pragma once
#include "Soba.h"

class StandardSoba : public Soba
{
public:
	Gost gostSobe;
	bool kingSizeKrevet;
	bool flatScreenTV;
	bool getKingSizeKrevet();
	bool getFlatScreenTV();
	void dodajGostaUSobu(Gost& g);
};

