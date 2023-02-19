#include "Hotel.h"
#include<iomanip>

void Hotel::setRadnici() {
	shared_ptr<Radnik> temp = make_shared<Radnik>();
	temp->setRadnik();
	this->getRadnici().push_back(*temp);
}

vector<Radnik>& Hotel::getRadnici() {
	return this->radnici;
}

void Hotel::ispisiSveRadnike() {
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	cout.width(8); cout << "R/Br";
	cout.width(10); cout << "Ime";
	cout.width(16); cout << "Prezime";
	cout.width(16); cout << "D. rodjenja";
	cout.width(18); cout << "D. zaposelenja";
	cout.width(16); cout << "Br. telefona";
	cout.width(16); cout << "Adresa";
	cout.width(16); cout << "E-mail";
	cout.width(16); cout << "Kod";
	cout.width(18); cout << "Vrsta radnika\n";
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < this->getRadnici().size() ; i++) {
		if (this->getStandardSobe()[i].stanje == slobodna)
		{
			cout.width(8); cout << i + 1<<".";
			cout.width(10); cout << this->getRadnici()[i].getIme();
			cout.width(16); cout << this->getRadnici()[i].getPrezime();
			cout.width(18); cout << this->getRadnici()[i].getDatumRodjenja();
			cout.width(16); cout << this->getRadnici()[i].getDatumZaposlenja();
			cout.width(16); cout << this->getRadnici()[i].getBrTelefona();
			cout.width(16); cout << this->getRadnici()[i].getAdresa();
			cout.width(16); cout << this->getRadnici()[i].geteMailAdresa();
			cout.width(16); cout << this->getRadnici()[i].getKod();
			if (this->getRadnici()[i].getVrstaRadnika()==0) {
				cout.width(18); cout << "Stalni\n";
			}
			else {
				cout.width(18); cout << "Sezonski\n";
			}
		}
		cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------------\n";
	}
}

void Hotel::postaviStandardSobe() {
	this->getStandardSobe().resize(5);
	for (int i = 0; i < 5; i++) {
		this->getStandardSobe()[i].brSobe = i + 1;
		this->getStandardSobe()[i].sprat = 1;
		this->getStandardSobe()[i].stanje = slobodna;
		if (i < 3) {
			this->getStandardSobe()[i].brKreveta = 1;
			this->getStandardSobe()[i].saPogledom = 0;
			this->getStandardSobe()[i].kingSizeKrevet = 0;
			this->getStandardSobe()[i].flatScreenTV = 0;
			this->getStandardSobe()[i].cijenaNocenja = 50;
		}
		else {
			this->getStandardSobe()[i].brKreveta = 2;
			this->getStandardSobe()[i].saPogledom = 1;
			this->getStandardSobe()[i].kingSizeKrevet = 1;
			this->getStandardSobe()[i].flatScreenTV = 1;
			this->getStandardSobe()[i].cijenaNocenja = 80;
		}
	}
}

vector<StandardSoba>& Hotel::getStandardSobe() {
	return this->standardSobe;
}

void Hotel::ispisiStandardSobe() {
	cout << "------------------------------------------------------STANDARD SOBE----------------------------------------------------\n\n";
	cout.width(6); cout << "R/br";
	cout.width(14); cout << "Broj sobe";
	cout.width(14); cout << "Sprat";
	cout.width(14); cout << "Broj kreveta";
	cout.width(14); cout << "Pogled";
	cout.width(14); cout << "Stanje";
	cout.width(14); cout << "King-size";
	cout.width(14); cout << "FlatScreen TV";
	cout.width(14); cout << "KM/noc\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		cout.width(6); cout << i + 1;
		cout.width(14); cout << this->getStandardSobe()[i].brSobe;
		cout.width(14); cout << this->getStandardSobe()[i].sprat;
		cout.width(14); cout << this->getStandardSobe()[i].brKreveta;
		cout.width(14); cout << this->getStandardSobe()[i].saPogledom;
		if (this->getStandardSobe()[i].stanje == 0) {
			cout.width(14); cout << "Slobodna";
		}
		else if (this->getStandardSobe()[i].stanje == 1) {
			cout.width(14); cout << "Zauzeta";
		}

		if (this->getStandardSobe()[i].kingSizeKrevet == 0)
		{
			cout.width(14); cout << "NE";
		}
		else {
			cout.width(14); cout << "DA";
		}

		if (this->getStandardSobe()[i].flatScreenTV == 0) {
			cout.width(14); cout << "NE";
		}
		else {
			cout.width(14); cout << "DA";
		}
		cout.width(14); cout << this->getSuiteSobe()[i].cijenaNocenja << "\n";

	}
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}

void Hotel::postaviDeluxeSobe() {
	this->getDeluxeSobe().resize(5);
	for (int i = 0; i < 5; i++) {
		this->getDeluxeSobe()[i].brSobe = i + 6;
		this->getDeluxeSobe()[i].sprat = 2;
		this->getDeluxeSobe()[i].stanje = slobodna;
		if (i < 3) {
			this->getDeluxeSobe()[i].brKreveta = 1;
			this->getDeluxeSobe()[i].saPogledom = 1;
			this->getDeluxeSobe()[i].mreza5G = 0;
			this->getDeluxeSobe()[i].SPApristup = 0;
			this->getDeluxeSobe()[i].cijenaNocenja = 120;
		}
		else {
			this->getDeluxeSobe()[i].brKreveta = 2;
			this->getDeluxeSobe()[i].saPogledom = 1;
			this->getDeluxeSobe()[i].mreza5G = 1;
			this->getDeluxeSobe()[i].SPApristup = 1;
			this->getDeluxeSobe()[i].cijenaNocenja = 150;
		}
	}
}

vector<DeluxeSoba>& Hotel::getDeluxeSobe() {
	return this->deluxSobe;
}

void Hotel::ispisiDeluxeSobe() {
	cout << "------------------------------------------------------DELUXE SOBE------------------------------------------------------\n\n";
	cout.width(6); cout << "R/br";
	cout.width(14); cout << "Broj sobe";
	cout.width(14); cout << "Sprat";
	cout.width(14); cout << "Broj kreveta";
	cout.width(14); cout << "Pogled";
	cout.width(14); cout << "Stanje";
	cout.width(14); cout << "5G mreza";
	cout.width(14); cout << "SPA pristup";
	cout.width(14); cout << "KM/noc\n";
	cout << "------------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		cout.width(6); cout << i + 1;
		cout.width(14);  cout << this->getDeluxeSobe()[i].brSobe;
		cout.width(14); cout << this->getDeluxeSobe()[i].sprat;
		cout.width(14); cout << this->getDeluxeSobe()[i].brKreveta;
		cout.width(14); cout << this->getDeluxeSobe()[i].saPogledom;
		if (this->getDeluxeSobe()[i].stanje == 0) {
			cout.width(14); cout << "Slobodna";
		}
		else if (this->getDeluxeSobe()[i].stanje == 1) {
			cout.width(14); cout << "Zauzeta";
		}
		if (this->getDeluxeSobe()[i].mreza5G == 0)
		{
			cout.width(14); cout << "NE";
		}
		else {
			cout.width(14); cout << "DA";
		}

		if (this->getDeluxeSobe()[i].SPApristup == 0) {
			cout.width(14); cout << "NE";
		}
		else {
			cout.width(14); cout << "DA";
		}
		cout.width(14); cout << this->getDeluxeSobe()[i].cijenaNocenja << "\n";

	}
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}


void Hotel::postaviSuiteSobe() {
	this->getSuiteSobe().resize(5);
	for (int i = 0; i < 5; i++) {
		this->getSuiteSobe()[i].brSobe = i + 11;
		this->getSuiteSobe()[i].sprat = 3;
		this->getSuiteSobe()[i].stanje = slobodna;
		if (i < 3) {
			this->getSuiteSobe()[i].brKreveta = 1;
			this->getSuiteSobe()[i].saPogledom = 1;
			this->getSuiteSobe()[i].brSoba = 3;
			this->getSuiteSobe()[i].brKupatila = 3;
			this->getSuiteSobe()[i].cijenaNocenja = 180;
		}
		else {
			this->getSuiteSobe()[i].brKreveta = 2;
			this->getSuiteSobe()[i].saPogledom = 1;
			this->getSuiteSobe()[i].brSoba= 2;
			this->getSuiteSobe()[i].brKupatila = 2;
			this->getSuiteSobe()[i].cijenaNocenja = 240;
		}
	}
}

vector<SuiteSoba>& Hotel::getSuiteSobe() {
	return this->suiteSobe;
}

void Hotel::ispisiSuiteSobe() {
	cout << "------------------------------------------------------SUITE SOBE-------------------------------------------------------\n\n";
	cout.width(6); cout << "R/br";
	cout.width(14); cout << "Broj sobe";
	cout.width(14); cout << "Sprat";
	cout.width(14); cout << "Broj kreveta";
	cout.width(14); cout << "Pogled";
	cout.width(14); cout << "Stanje";
	cout.width(14); cout << "Broj soba";
	cout.width(14); cout << "Broj kupatila";
	cout.width(14); cout << "KM/noc\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		cout.width(6); cout << i + 1;
		cout.width(14); cout << this->getSuiteSobe()[i].brSobe;
		cout.width(14); cout << this->getSuiteSobe()[i].sprat;
		cout.width(14); cout << this->getSuiteSobe()[i].brKreveta;
		cout.width(14); cout << this->getSuiteSobe()[i].saPogledom;
		if (this->getSuiteSobe()[i].stanje == 0) {
			cout.width(14); cout << "Slobodna";
		}
		else if (this->getSuiteSobe()[i].stanje == 1) {
			cout.width(14); cout << "Zauzeta";
		}
		cout.width(14); cout << this->getSuiteSobe()[i].brSoba;
		cout.width(14); cout << this->getSuiteSobe()[i].brKupatila;
		cout.width(14); cout << this->getSuiteSobe()[i].cijenaNocenja << "\n";
	}
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}

void Hotel::ispisSvihSoba() {
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	this->ispisiStandardSobe();
	this->ispisiDeluxeSobe();
	this->ispisiSuiteSobe();
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}

void Hotel::ispisiSlobodneStandardSobe() {
	cout << "------------------------------------------------------STANDARD SOBE----------------------------------------------------\n\n";
	cout.width(6); cout << "R/br";
	cout.width(14); cout << "Broj sobe";
	cout.width(14); cout << "Sprat";
	cout.width(14); cout << "Broj kreveta";
	cout.width(14); cout << "Pogled";
	cout.width(14); cout << "Stanje";
	cout.width(14); cout << "King-size";
	cout.width(14); cout << "FlatScreen TV";
	cout.width(14); cout << "KM/noc\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		if (this->getStandardSobe()[i].stanje==slobodna)
		{
			cout.width(6); cout << i + 1;
			cout.width(14); cout << this->getStandardSobe()[i].brSobe;
			cout.width(14); cout << this->getStandardSobe()[i].sprat;
			cout.width(14); cout << this->getStandardSobe()[i].brKreveta;
			cout.width(14); cout << this->getStandardSobe()[i].saPogledom;
			if (this->getStandardSobe()[i].stanje == 0) {
				cout.width(14); cout << "Slobodna";
			}
			else if (this->getStandardSobe()[i].stanje == 1) {
				cout.width(14); cout << "Zauzeta";
			}

			if (this->getStandardSobe()[i].kingSizeKrevet == 0)
			{
				cout.width(14); cout << "NE";
			}
			else {
				cout.width(14); cout << "DA";
			}

			if (this->getStandardSobe()[i].flatScreenTV == 0) {
				cout.width(14); cout << "NE";
			}
			else {
				cout.width(14); cout << "DA";
			}
			cout.width(14); cout << this->getSuiteSobe()[i].cijenaNocenja << "\n";
		}
		

	}
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}

void Hotel::ispisiSlobodneDeluxeSobe() {
	cout << "------------------------------------------------------DELUXE SOBE------------------------------------------------------\n\n";
	cout.width(6); cout << "R/br";
	cout.width(14); cout << "Broj sobe";
	cout.width(14); cout << "Sprat";
	cout.width(14); cout << "Broj kreveta";
	cout.width(14); cout << "Pogled";
	cout.width(14); cout << "Stanje";
	cout.width(14); cout << "5G mreza";
	cout.width(14); cout << "SPA pristup";
	cout.width(14); cout << "KM/noc\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		if (this->getDeluxeSobe()[i].stanje==slobodna)
		{
			cout.width(6); cout << i + 1;
			cout.width(14);  cout << this->getDeluxeSobe()[i].brSobe;
			cout.width(14); cout << this->getDeluxeSobe()[i].sprat;
			cout.width(14); cout << this->getDeluxeSobe()[i].brKreveta;
			cout.width(14); cout << this->getDeluxeSobe()[i].saPogledom;
			if (this->getDeluxeSobe()[i].stanje == 0) {
				cout.width(14); cout << "Slobodna";
			}
			else if (this->getDeluxeSobe()[i].stanje == 1) {
				cout.width(14); cout << "Zauzeta";
			}
			if (this->getDeluxeSobe()[i].mreza5G == 0)
			{
				cout.width(14); cout << "NE";
			}
			else {
				cout.width(14); cout << "DA";
			}

			if (this->getDeluxeSobe()[i].SPApristup == 0) {
				cout.width(14); cout << "NE";
			}
			else {
				cout.width(14); cout << "DA";
			}
			cout.width(14); cout << this->getDeluxeSobe()[i].cijenaNocenja << "\n";
		}
	}
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}

void Hotel::ispisiSlobodneSuiteSobe() {
	cout << "------------------------------------------------------SUITE SOBE-------------------------------------------------------\n\n";
	cout.width(6); cout << "R/br";
	cout.width(14); cout << "Broj sobe";
	cout.width(14); cout << "Sprat";
	cout.width(14); cout << "Broj kreveta";
	cout.width(14); cout << "Pogled";
	cout.width(14); cout << "Stanje";
	cout.width(14); cout << "Broj soba";
	cout.width(14); cout << "Broj kupatila";
	cout.width(14); cout << "KM/noc\n";
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	for (int i = 0; i < 5; i++) {
		if (this->getSuiteSobe()[i].stanje==slobodna) {
			cout.width(6); cout << i + 1;
			cout.width(14); cout << this->getSuiteSobe()[i].brSobe;
			cout.width(14); cout << this->getSuiteSobe()[i].sprat;
			cout.width(14); cout << this->getSuiteSobe()[i].brKreveta;
			cout.width(14); cout << this->getSuiteSobe()[i].saPogledom;
			if (this->getSuiteSobe()[i].stanje == 0) {
				cout.width(14); cout << "Slobodna";
			}
			else if (this->getSuiteSobe()[i].stanje == 1) {
				cout.width(14); cout << "Zauzeta";
			}
			cout.width(14); cout << this->getSuiteSobe()[i].brSoba;
			cout.width(14); cout << this->getSuiteSobe()[i].brKupatila;
			cout.width(14); cout << this->getSuiteSobe()[i].cijenaNocenja << "\n";
		}
		
	}
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
}

void Hotel::ispisSvihSlobodnihSoba() {
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";
	this->ispisiSlobodneStandardSobe();
	this->ispisiSlobodneDeluxeSobe();
	this->ispisiSlobodneSuiteSobe();
	cout << "-----------------------------------------------------------------------------------------------------------------------\n";

}

void Hotel::pretragaGostaPoSobama(Gost& g) {
	for (int i = 0; i < 5; i++)
	{
		if (this->getStandardSobe()[i].gostSobe.getIme()==g.getIme()) {
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout<< setw(16)<<"Ime"<< setw(16) << "Prezime"<< setw(16) << "Datum rodjenja"<< setw(16) << "Br. telefona"
				<< setw(16) << "Adresa"<< setw(16) << "E-mail adresa"<< setw(16) << "Broj nocenja"<< setw(16) <<"Parking"<< setw(16)<< "Check-in datum\n";
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << g;
		}
		if (this->getDeluxeSobe()[i].gostSobe.getIme() == g.getIme()) {
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << setw(16) << "Ime" << setw(16) << "Prezime" << setw(16) << "Datum rodjenja" << setw(16) << "Br. telefona"
				<< setw(16) << "Adresa" << setw(16) << "E-mail adresa" << setw(16) << "Broj nocenja" << setw(16) << "Parking" << setw(16) << "Check-in datum\n";
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << g;
		}
		if (this->getSuiteSobe()[i].gostSobe.getIme() == g.getIme()) {
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
			cout << setw(16) << "Ime" << setw(16) << "Prezime" << setw(16) << "Datum rodjenja" << setw(16) << "Br. telefona"
				<< setw(16) << "Adresa" << setw(16) << "E-mail adresa" << setw(16) << "Broj nocenja" << setw(16) << "Parking" << setw(16) << "Check-in datum\n";
			cout << g;
		}
	}
}
