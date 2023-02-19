#pragma once
#include"Soba.h"

class DeluxeSoba : public Soba
{
public:
	Gost gostSobe;
	bool mreza5G;
	bool SPApristup;
	bool get5G();
	bool getSPApristup();
	void dodajGostaUSobu(Gost& g) ;
};

