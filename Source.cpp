#include<iostream>
#include<string>
#include "Hotel.h"
#include "Radnik.h"
#include "Gost.h"
#include <fstream>
#include <iomanip>

using namespace std;

void ispisiPocetniMeni() {
    cout << "	***RECEPCIONER MENI***\n";
    cout << "1. Uloguj se\n";				// log in za recepcionera
    cout << "2. Dodaj recepcionera\n";		// dodaj recepcionera
    cout << "3. Izbrisi recepcionera\n";	// izbrisi recepcionera
    cout << "4. Pregled recepcionera\n";    // lista svih recepcionera
    cout << "5. Kraj\n";                    // kraj programa
}

void ispisiGlavniMeni() {
    cout << "	***MENI***\n";
    cout << "1. Registar gostiju\n";		// otvara txt file
    cout << "2. Check-in\n";				// pocetka unos podataka gosta
    cout << "3. Pregled soba\n";            // pregled svih slobodnih soba
    cout << "4. Pretraga po gostima\n";		// pretraga gosta po imenu
    cout << "5. Pretraga po sobama\n";		// pretraga gosta po broju sobe u kojoj se nalazi
    cout << "6. Check-out\n";				// brisanje gosta i uklanjanje iz sobe
    cout << "7. Kraj\n";                    // kraj programa
}

int main() {
    int izborPocetni, izborGlavni; // varijable za prolazak kroz menije

    string kod; // kod za pristup (unosimo kod i provjeravamo da li se podudara sa nekim od kodova radnika)

    Hotel mojHotel; // kreiranje hotela

    cout<<"\t***Unos podataka glavnog recepcionara!***\n"; // unos glavnog recepcionere koji ima autoritet da upravlja pocetnim menijem
    mojHotel.setRadnici();
    system("cls");
    
    mojHotel.postaviStandardSobe();     //kreiranje soba
    mojHotel.postaviDeluxeSobe();
    mojHotel.postaviSuiteSobe();
    
    bool ispravan=false;  // varijabla koja provjerava da li je kod koji smo unijeli jedan od kodova radnika

    Gost g; // gost kojeg unosimo i spremamo u sobu
    
    int izborSobe;  // varijabla za izbor rednog broja sobe koju bira gost

    bool zauzetaSoba = false; // varijabla za provjeru da li je soba zauzeta

    ofstream registar;
    registar.open("registarHotela.txt", ios::app);  //kreiranje txt file-a

    string naziv;   // string za spajanje imena i prezimena



    do {
        try {
            ispisiPocetniMeni();
            cout<<"Unesi izbor: ";
            cin >> izborPocetni;
            if (izborPocetni< 1 || izborPocetni>5) {
                throw "Odabrali ste nemoguc izbor u meniju!";
            }
            switch (izborPocetni)
            {
            case 1: // case za log-in za glavni meni (pristup imaju svi sa kodom)

                system("cls");
                cout << "Unesi kod: ";
                cin >> kod;

                for (int i = 0; i < mojHotel.getRadnici().size(); i++) {

                    if (mojHotel.getRadnici()[i].getKod() == kod) {
                        ispravan = true;
                    }

                }

                if (ispravan == false){
                    throw "Unijeli ste nepostojeci kod!\n";
                }
               
                do {

                    try {
                        system("cls");
                        ispisiGlavniMeni();
                        cout << "Unesi izbor: ";
                        cin >> izborGlavni;
                        if (izborGlavni< 1 || izborGlavni>7) {
                            throw "Odabrali ste nemoguc izbor u meniju!";
                        }
                        switch (izborGlavni)
                        {
                        case 1: // case kojin otvara file na lokaciji

                            system("cls");
                            if (registar.is_open()) {
                                registar.close();
                                int result = system("C:\\Users\\xy\\source\\repos\\OOP-Projekat1.0\\OOP-Projekat1.0\\registarHotela.txt");
                            }
                            system("pause");
                            system("cls");
                            registar.open("registarHotela.txt", ios::app);

                            break;
                        case 2: // case za unos novog gosta i spremanje u datoteku registar

                            system("cls");
                            cin.ignore();
                            cin >> g;
                            registar << g.getIme() << " " << g.getPrezime() << " " << g.getDatumRodjenja() << " " << g.getBrTelefona() << " " << g.getAdresa() << " "
                                << g.geteMailAdresa() << " " << g.getBrNocenja() << " " << g.getParking() << " " << g.getCheckInDatum() << "\n";

                            do
                            {
                                do
                                {
                                    system("cls");
                                    mojHotel.ispisSvihSoba();
                                    cout << "Izaberi broj sobe: ";
                                    cin >> izborSobe;
                                    zauzetaSoba = false;
                                    if (izborSobe - 1 < 5) {
                                        if (mojHotel.getStandardSobe()[izborSobe - 1].stanje == zauzeta)
                                        {
                                            zauzetaSoba = true;
                                            cout << izborSobe << ". Standard soba je zauzeta!\n";
                                            system("pause");
                                        }
                                    }
                                    if (izborSobe - 1 < 10 && izborSobe - 1 > 4)
                                    {
                                        if (mojHotel.getDeluxeSobe()[izborSobe - 6].stanje == zauzeta)
                                        {
                                            zauzetaSoba = true;
                                            cout << izborSobe << ". Deluxe soba je zauzeta!\n";
                                            system("pause");
                                        }
                                    }
                                    if (izborSobe - 1 < 15 && izborSobe - 1 > 9)
                                    {
                                        if (mojHotel.getSuiteSobe()[izborSobe - 11].stanje == zauzeta)
                                        {
                                            zauzetaSoba = true;
                                            cout << izborSobe << ". Suite soba je zauzeta!\n";
                                            system("pause");
                                        }
                                    }
                                } while (izborSobe < 1 || izborSobe>15);
                            } while (zauzetaSoba == true);

                            if (izborSobe > 0 && izborSobe < 6) {
                                //Soba* temp = &mojHotel.getStandardSobe()[izborSobe - 1];
                                //temp->dodajGostaUSobu(g);
                                mojHotel.getStandardSobe()[izborSobe - 1].dodajGostaUSobu(g);
                                mojHotel.getStandardSobe()[izborSobe - 1].stanje = zauzeta;
                            }
                            else if (izborSobe > 5 && izborSobe < 11) {
                                //Soba* temp = &mojHotel.getDeluxeSobe()[izborSobe - 6];
                                //temp->dodajGostaUSobu(g);
                                mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe = g;
                                mojHotel.getDeluxeSobe()[izborSobe - 6].stanje = zauzeta;
                            }
                            else {
                                //Soba* temp = &mojHotel.getSuiteSobe()[izborSobe - 11];
                                //temp->dodajGostaUSobu(g);
                                mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe = g;
                                mojHotel.getSuiteSobe()[izborSobe - 11].stanje = zauzeta;
                            }

                            break;
                        case 3: //case za pregled svih slobodnih soba

                            system("cls");
                            mojHotel.ispisSvihSlobodnihSoba();

                            break;
                        case 4: //case za pretragu gosta po imenu

                            system("cls");
                            cin.ignore();
                            g.setIme();
                            system("cls");
                            mojHotel.pretragaGostaPoSobama(g);

                            break;
                        case 5: //case za pretragu gosta po broju sobe

                            do
                            {
                                system("cls");
                                cout << "Unesi broj sobe trazenog gosta: ";
                                cin >> izborSobe;
                            } while (izborSobe < 1 || izborSobe>15);
                            system("cls");
                            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
                            cout << setw(16) << "Ime" << setw(16) << "Prezime" << setw(16) << "D. rodjenja" << setw(16) << "Br. telefona"
                                << setw(16) << "Adresa" << setw(16) << "E-mail" << setw(16) << "Br. nocenja" << setw(16) << "Parking" << setw(16) << "D. Check-in" << "\n";
                            cout << "--------------------------------------------------------------------------------------------------------------------------------------------------\n";
                            if (izborSobe > 0 && izborSobe < 6) {
                                cout << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe;
                            }
                            else if (izborSobe > 5 && izborSobe < 11) {
                                cout << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe;
                            }
                            else {
                                cout << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe;
                            }

                            break;
                        case 6: //case za check-out i ispis racuna u txt file

                            do
                            {
                                system("cls");
                                mojHotel.ispisSvihSoba();
                                cout << "Unesi broj sobe koja se oslobadja: ";
                                cin >> izborSobe;
                                if (izborSobe < 1 || izborSobe > 15)
                                {
                                    cout << "Pogresan izbor!";
                                    system("pause");
                                }
                            } while (izborSobe < 1 || izborSobe>15);
                            if (izborSobe > 0 && izborSobe < 6) {
                                mojHotel.getStandardSobe()[izborSobe - 1].stanje = slobodna;
                                cout << "Cijena boravka: " << mojHotel.getStandardSobe()[izborSobe - 1].cijenaNocenja * mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getBrNocenja() << "KM\n";
                                naziv = mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getIme() + mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getPrezime();
                                fstream racun;
                                racun.open(naziv + "txt", ios::out);
                                racun << setw(20) << "Racun\n"
                                    << "--------------------------------------------------------------------------\n"
                                    << "Ime:" << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getIme() << "\nPrezime: " << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getPrezime() << "\nD. rodjenja:" << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getDatumRodjenja() << "\nBr. telefona:"
                                    << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getBrTelefona() << "\nAdresa:" << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getAdresa() << "\nE-mail:" << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.geteMailAdresa() << "\nBr. nocenja:"
                                    << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getBrNocenja() << "\nParking:" << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getParking() << "\nD. Check-in:" << mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getCheckInDatum() << "\n"
                                    << "Cijena boravka: " << mojHotel.getStandardSobe()[izborSobe - 1].cijenaNocenja * mojHotel.getStandardSobe()[izborSobe - 1].gostSobe.getBrNocenja() << "KM\n"
                                    << "--------------------------------------------------------------------------\n";


                            }else if (izborSobe > 5 && izborSobe < 11) {
                                mojHotel.getDeluxeSobe()[izborSobe - 6].stanje = slobodna;
                                cout << "Cijena boravka: " << mojHotel.getDeluxeSobe()[izborSobe - 6].cijenaNocenja * mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getBrNocenja() << "KM\n";
                                naziv = mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getIme() + mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getPrezime();
                                fstream racun;
                                racun.open(naziv + "txt", ios::out);
                                racun << setw(20) << "Racun\n"
                                    << "--------------------------------------------------------------------------\n"
                                    << "Ime:" << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getIme() << "\nPrezime: " << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getPrezime() << "\nD. rodjenja:" << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getDatumRodjenja() << "\nBr. telefona:"
                                    << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getBrTelefona() << "\nAdresa:" << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getAdresa() << "\nE-mail:" << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.geteMailAdresa() << "\nBr. nocenja:"
                                    << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getBrNocenja() << "\nParking:" << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getParking() << "\nD. Check-in:" << mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getCheckInDatum() << "\n"
                                    << "Cijena boravka: " << mojHotel.getDeluxeSobe()[izborSobe - 6].cijenaNocenja * mojHotel.getDeluxeSobe()[izborSobe - 6].gostSobe.getBrNocenja() << "KM\n"
                                    << "--------------------------------------------------------------------------\n";
                            }else {
                                mojHotel.getSuiteSobe()[izborSobe - 11].stanje = slobodna;
                                cout << "Cijena boravka: " << mojHotel.getSuiteSobe()[izborSobe - 11].cijenaNocenja * mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getBrNocenja() << "KM\n";
                                naziv = mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getIme() + mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getPrezime();
                                fstream racun;
                                racun.open(naziv + "txt", ios::out);
                                racun << setw(20) << "Racun\n"
                                    << "--------------------------------------------------------------------------\n"
                                    << "Ime:" << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getIme() << "\nPrezime: " << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getPrezime() << "\nD. rodjenja:" << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getDatumRodjenja() << "\nBr. telefona:"
                                    << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getBrTelefona() << "\nAdresa:" << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getAdresa() << "\nE-mail:" << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.geteMailAdresa() << "\nBr. nocenja:"
                                    << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getBrNocenja() << "\nParking:" << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getParking() << "\nD. Check-in:" << mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getCheckInDatum() << "\n"
                                    << "Cijena boravka: " << mojHotel.getSuiteSobe()[izborSobe - 11].cijenaNocenja * mojHotel.getSuiteSobe()[izborSobe - 11].gostSobe.getBrNocenja() << "KM\n"
                                    << "--------------------------------------------------------------------------\n";
                            }
                        
                            break;
                        case 7:

                            return 0;

                            break;
                        default:
                            break;
                        }

                    }
                    catch (const char* Greska) {
                        cout << "Greska u programu: " << Greska << endl;
                    }

                    system("pause");
                    system("cls");
                } while (izborGlavni != 7);

                break;
            case 2: // case za unos novog recepcionera (unosi samo glavni recepcioner)

                system("cls");
                cout << "Unesi kod glavnog recepcionara: ";
                cin >> kod;
                if (kod != mojHotel.getRadnici()[0].getKod())
                {
                    throw "Unijeli ste pogresan kod!\n";
                }
                
                mojHotel.ispisiSveRadnike();
                cin.ignore();
                mojHotel.setRadnici();

                break;
            case 3: // case za brisanje recepcionera (unosi samo glavni recepcioner)

                system("cls");
                cout << "Unesi kod glavnog recepcionara: ";
                cin >> kod;
                if (kod != mojHotel.getRadnici()[0].getKod())
                {
                    throw "Unijeli ste pogresan kod!\n";
                }

                system("cls");
                int izbrisi;
                mojHotel.ispisiSveRadnike();
                cout << "Izaberi radnika kojeg zelis izbrisati: ";
                cin >> izbrisi;
                if (izbrisi == 1) {
                    throw "Ne mozete izbrisati glavnog recepcionera!\n";
                }
                mojHotel.getRadnici().erase(mojHotel.getRadnici().begin() + izbrisi - 1);

                break;
            case 4: // case ispis svih recepcionera (unosi samo glavni recepcioner)

                system("cls");
                cout << "Unesi kod glavnog recepcionara: ";
                cin >> kod;
                if (kod != mojHotel.getRadnici()[0].getKod())
                {
                    throw "Unijeli ste pogresan kod!\n";
                }

                system("cls");
                mojHotel.ispisiSveRadnike();

                break;
            case 5:

                return 0;

                break;
            default:
                break;
            }

        }
        catch (const char* Greska) {
            cout << "Greska u programu: " << Greska << endl;
        }

        system("pause");
        system("cls");
    } while (izborPocetni != 5);

    system("pause");
    return 0;
}