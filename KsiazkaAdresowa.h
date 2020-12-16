#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenadzer.h"
#include "AdresatMenadzer.h"
#include "MetodyPomocnicze.h"


using namespace std;

class KsiazkaAdresowa{
    UzytkownikMenadzer uzytkownikMenadzer;
    AdresatMenadzer* adresatMenadzer;
    const string NAZWA_PLIKU_Z_ADRESATAMI;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami) :
		uzytkownikMenadzer(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami)
	 {
		adresatMenadzer = NULL;
	};
	~KsiazkaAdresowa() {
		delete adresatMenadzer;
		adresatMenadzer = NULL;
	}

	void czyUzytkownikJestZalogowany();
	void rejestracjaUzytkownika();
	void logowanieUzytkownika();
	void wylogowanieUzytkownika();
	void zmianaHaslaZalogowanegoUzytkownika();
	void wypiszWszystkichUzytkownikow();
	void wypiszWszystkichAdresatow();
	void dodajAdresata();
	void wyszukajAdresatowPoImieniu();
	void wyszukajAdresatowPoNazwisku();
	char wybierzOpcjeZMenuGlownego();
	int pobierzIdZalogowanegoUzytkownika();
	char wybierzOpcjeZMenuUzytkownika();
	int pobierzIdOstatniegoAdresata();
};

#endif
