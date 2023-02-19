#pragma once
#include <string>
#include<iostream>
#include<vector>

using namespace std;

enum VrstaRadnika{StalnoZaposlen= 0, Senzonski = 1};

class Radnik
{
private:
	string ime;
	string prezime;
	string datumRodjenja;
	string datumZposlenja;
	string brTelefona;
	string adresa;
	string eMailAdresa;
	string kod;
	vector<Radnik> radnici;
	VrstaRadnika vrsta;
public:
	Radnik();
	void setIme();
	void setPrezime();
	void setDatumRodjenja();
	void setDatumZposlenja();
	void setBrTelefona();
	void setAdresa();
	void seteMailAdresa();
	void setKod();
	void setVrsta();
	string getIme();
	string getPrezime();
	string getDatumRodjenja();
	string getDatumZaposlenja();
	string getBrTelefona();
	string getAdresa();
	string geteMailAdresa();
	string getKod();
	VrstaRadnika& getVrstaRadnika();
	void setRadnik();
	friend ostream& operator<<(ostream& stream, Radnik& r);
	~Radnik()= default;
};