#pragma once
#include<iostream>
#include"Gost.h"


using namespace std;

enum StanjeSobe { slobodna = 0, zauzeta = 1};
class Gost;
class Soba
{
public:
	int brSobe;
	int sprat;
	int brKreveta;
	bool saPogledom;
	float cijenaNocenja;
	StanjeSobe stanje;

	Soba();
	int getBrSobe();
	int getSprat();
	int getBrKreveta();
	bool getSaPogledom();
	float getCijenaNocenja();
	StanjeSobe& getStanje();
	virtual void dodajGostaUSobu(Gost& g) = 0 ;
	~Soba() = default;
};