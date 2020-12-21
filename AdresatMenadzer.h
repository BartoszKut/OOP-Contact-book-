#ifndef ADRESATMENADZER_H
#define ADRESATMENADZER_H

#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenadzer.h"
#include "MetodyPomocnicze.h"

using namespace std;

class AdresatMenadzer {
	const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
	vector <Adresat> adresaci;

	Adresat podajDaneNowegoAdresata();

	void wyswietlDaneAdresata(Adresat adresat);
	void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);//nowo dodane
	int podajIdWybranegoAdresata();//nowo dodane
	PlikZAdresatami plikZAdresatami;
public:
	/*AdresatMenadzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};*/
	AdresatMenadzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) :
		plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
	{
		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
	};

    int pobierzIdOstatniegoAdresata();
	void dodajAdresata();
	void wyswietlWszystkichAdresatow();
	void wyszukajAdresatowPoImieniu();
	void wyszukajAdresatowPoNazwisku();
    int usunAdresata();
	void edytujAdresata();
};



#endif
