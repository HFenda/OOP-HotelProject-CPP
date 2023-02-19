#pragma once
#include <iostream>
#include<vector>
#include "Radnik.h"
#include "StandardSoba.h"
#include "DeluxeSoba.h"
#include "SuiteSoba.h"
#include "Gost.h"
#include "Soba.h"

using namespace std;

class Hotel
{
private:
	Radnik radnik;
	vector<Radnik> radnici;
	vector<StandardSoba> standardSobe;
	vector<DeluxeSoba> deluxSobe;
	vector<SuiteSoba> suiteSobe;
public:
	void setRadnici();
	vector<Radnik>& getRadnici();
	void ispisiSveRadnike();

	void postaviStandardSobe();
	vector<StandardSoba>& getStandardSobe();
	void ispisiStandardSobe();

	void postaviDeluxeSobe();
	vector<DeluxeSoba>& getDeluxeSobe();
	void ispisiDeluxeSobe();

	void postaviSuiteSobe();
	vector<SuiteSoba>& getSuiteSobe();
	void ispisiSuiteSobe();

	void ispisiSlobodneStandardSobe();
	void ispisiSlobodneDeluxeSobe();
	void ispisiSlobodneSuiteSobe();

	void ispisSvihSlobodnihSoba();
	void ispisSvihSoba();

	void pretragaGostaPoSobama(Gost& g);
};

