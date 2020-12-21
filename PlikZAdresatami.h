#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"

using namespace std;

class PlikZAdresatami : public PlikTekstowy {
	const string NAZWA_PLIKU_Z_ADRESATAMI;
	int idOstatniegoAdresata;
	const string nazwaTymczasowegoPlikuZAdresatami;

	string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
	int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
	string pobierzLiczbe(string tekst, int pozycjaZnaku);
	Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
public:
	//PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {};
	PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) , nazwaTymczasowegoPlikuZAdresatami("Adresaci_tymczasowo.txt")
	{
		idOstatniegoAdresata = pobierzIdOstatniegoAdresata();
	}; // nowy konstruktor
	bool dopiszAdresataDoPliku(Adresat adresat);
	vector<Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
	void zaktualizujDaneWybranegoAdresata(Adresat adresat);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    int pobierzIdOstatniegoAdresata();
    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);
};




#endif
