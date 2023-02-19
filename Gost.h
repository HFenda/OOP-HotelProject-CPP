#pragma once
#include<iostream>
#include<string>
#include"Soba.h"

using namespace std;
class Gost
{
private:
	string ime;
	string prezime;
	string datumRodjenja;
	string brTelefona;
	string adresa;
	string eMailAdresa;
	int brNocenja;
	bool parking;
	string checkInDatum;
public:
	Gost();
	void setIme();
	void setPrezime();
	void setDatumRodjenja();
	void setBrTelefona();
	void setAdresa();
	void seteMailAdresa();
	void setBrNocenja();
	void setParking();
	void setCheckInDatum();
	string getIme();
	string getPrezime();
	string getDatumRodjenja();
	string getBrTelefona();
	string getAdresa();
	string geteMailAdresa();
	int getBrNocenja();
	bool getParking();
	string getCheckInDatum();
	friend ostream& operator<<(ostream& stream, Gost& g); //ispisi gosta
	friend istream& operator>>(istream& stream, Gost& g); //dodaj gosta
	//void operator!(); //izbrisi gosta
	~Gost() = default;
};
