#include "Gost.h"
#include<iomanip>

using namespace std;

Gost::Gost() {
	this->ime = "Jane";
	this->prezime = "Doe";
	this->datumRodjenja = "01.01.1900.";
	this->brTelefona = "060 / 000 - 000";
	this->adresa = "Zenica bb";
	this->eMailAdresa = "jane.doe@********.com";
	this->brNocenja = 1;
	this->parking = 0;
}


void Gost::setIme() {
	cout << "Unesi ime: ";
	getline(cin, this->ime);
}

void Gost::setPrezime() {
	cout << "Unesi prezime: ";
	getline(cin, this->prezime);
}

void Gost::setDatumRodjenja() {
	cout << "Unesi datum rodjenja: ";
	getline(cin, this->datumRodjenja);
}

void Gost::setBrTelefona() {
	cout << "Unesi broj telefona: ";
	getline(cin, this->brTelefona);
}

void Gost::setAdresa() {
	cout << "Unesi adresu: ";
	getline(cin, this->adresa);
}

void Gost::seteMailAdresa() {
	cout << "Unesi e-mail adresu: ";
	getline(cin, this->eMailAdresa);
}

void Gost::setBrNocenja() {
	cout << "Unesite broj nocenja: ";
	cin >> this->brNocenja;
}

void Gost::setParking() {
	int izbor;
	do
	{
		cout << "Unesite da li gost koristi parking (0.Ne, 1.Da): ";
		cin >> izbor;
	} while (izbor<0 || izbor>1);
	this->parking = izbor;
}

void Gost::setCheckInDatum() {
	cout << "Unesite check-in datum: ";
	cin >> this->checkInDatum;
}

string Gost::getIme() {
	return this->ime;
}

string Gost::getPrezime() {
	return this->prezime;
}

string Gost::getDatumRodjenja() {
	return this->datumRodjenja;
}

string Gost::getBrTelefona() {
	return this->brTelefona;
}

string Gost::getAdresa() {
	return this->adresa;
}

string Gost::geteMailAdresa() {
	return this->eMailAdresa;
}

int Gost::getBrNocenja() {
	return this->brNocenja;
}

bool Gost::getParking() {
	return this->parking;
}

string Gost::getCheckInDatum() {
	return this->checkInDatum;
}

ostream& operator<<(ostream& stream, Gost& g) {
	stream<<"--------------------------------------------------------------------------------------------------------------------------------------------------\n";
	stream << setw(16)<< g.getIme() << setw(16) << g.getPrezime() << setw(16) << g.getDatumRodjenja() << setw(16) << g.getBrTelefona()
		   << setw(16) << g.getAdresa() << setw(16) << g.geteMailAdresa() << setw(16)  <<g.getBrNocenja();
	if (g.getParking() == 0) {
		stream << setw(15)<< "Da\t";
	}
	else {
		stream << setw(15)<< "Ne\t";
	}
	stream << setw(15) << g.getCheckInDatum() << "\n";
	stream << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
	return stream;
}

istream& operator>>(istream& stream, Gost& g) {
	g.setIme();
	g.setPrezime();
	g.setDatumRodjenja();
	g.setBrTelefona();
	g.setAdresa();
	g.seteMailAdresa();
	g.setBrNocenja();
	g.setParking();
	g.setCheckInDatum();

	return stream;
}

