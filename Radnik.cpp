#include "Radnik.h"
#include <iomanip>

using namespace std;

Radnik::Radnik() {
	this->ime = "John";
	this->prezime = "Doe";
	this->datumRodjenja = "01.01.1900.";
	this->datumZposlenja = "01.01.2000.";
	this->brTelefona = "060 / 000 - 000";
	this->adresa = "Zenica bb";
	this->eMailAdresa="john.doe@********.com";
	this->kod = "0000";
	this->vrsta = StalnoZaposlen;
}

void Radnik::setIme() {
	cout << "Unesi ime: ";
	getline(cin,this->ime);
}

void Radnik::setPrezime() {
	cout << "Unesi prezime: ";
	getline(cin, this->prezime);
}

void Radnik::setDatumRodjenja() {
	cout << "Unesi datum rodjenja: ";
	getline(cin,this->datumRodjenja);
}

void Radnik::setDatumZposlenja() {
	cout << "Unesi datum zaposlenja: ";
	getline(cin, this->datumZposlenja);
}

void Radnik::setBrTelefona() {
	cout << "Unesi broj telefona: ";
	getline(cin , this->brTelefona);
}

void Radnik::setAdresa() {
	cout << "Unesi adresu: ";
	getline(cin ,this->adresa);
}

void Radnik::seteMailAdresa() {
	cout << "Unesi e-mail adresu: ";
	getline(cin ,this->eMailAdresa);
}

void Radnik::setKod() {
	cout << "Unesi pristupni kod: ";
	getline(cin ,this->kod);
}

void Radnik::setVrsta() {
	int v;
	do
	{
		cout << "Unesi vrstu zaposlenja (0. Stalni radnik, 1. Sezonski ranik): ";
		cin >> v;
	} while (v<0 || v>1);
	this->vrsta = static_cast<VrstaRadnika>(v);
}

string Radnik::getIme() {
	return this->ime;
}

string Radnik::getPrezime() {
	return this->prezime;
}

string Radnik::getDatumRodjenja() {
	return this->datumRodjenja;
}

string Radnik::getDatumZaposlenja() {
	return this->datumZposlenja;
}

string Radnik::getBrTelefona() {
	return this->brTelefona;
}

string Radnik::getAdresa() {
	return this->adresa;
}

string Radnik::geteMailAdresa() {
	return this->eMailAdresa;
}

string Radnik::getKod() {
	return this->kod;
}

VrstaRadnika& Radnik::getVrstaRadnika() {
	return this->vrsta;
}

void Radnik::setRadnik(){
	this->setIme();
	this->setPrezime();
	this->setDatumRodjenja();
	this->setDatumZposlenja();
	this->setBrTelefona();
	this->setAdresa();
	this->seteMailAdresa();
	this->setKod();
	this->setVrsta();
}

ostream& operator<<(ostream& stream, Radnik& r) {
	if (r.getVrstaRadnika() == StalnoZaposlen) {
		stream << "\t" << "Stalno zaposlen" <<"\t";
	}
	else {
		stream <<"\t"<< "Sezonski radnik" << "\t";
	}
	stream << "\t" << r.getIme() << "\t" << r.getPrezime() << "\t" << r.getDatumRodjenja() << "\t" << r.getDatumZaposlenja() 
		   << "\t\t" << r.getBrTelefona() << "\t" << r.getAdresa() << "\t" << r.geteMailAdresa() << "\t" <<r.getKod()<< endl;;
	return stream;
}

