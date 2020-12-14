#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "Adresat.h"
#include "PlikZAdresatami.h"
#include "UzytkownikMenedzer.h"


using namespace std;

class AdresatMenedzer
{
    const int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector<Adresat> adresaci;

    Adresat podajDaneNowegoAdresata();
    int pobierzIdOstatniegoAdresata();
    void wyswietlDaneAdresata(Adresat adresat);
    PlikZAdresatami plikZAdresatami;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int IDZALOGOWANEGOUZYTKOWNIKA) :
		plikZAdresatami(nazwaPlikuZAdresatami), idZalogowanegoUzytkownika(IDZALOGOWANEGOUZYTKOWNIKA)
	{
		adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
	};
    //AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};

    //int wczytajAdresatowZalogowanegoUzytkownikaZPliku();

    int dodajAdresata();
    void wyswietlWszystkichAdresatow();
    //string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

};

#endif
