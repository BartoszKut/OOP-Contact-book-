#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"
#include "MetodyPomocnicze.h"


using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
    AdresatMenedzer* adresatMenedzer;
    const string nazwaPlikuZAdresatami;

   public:
    /*KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami)
    : uzytkownikMenedzer(nazwaPlikuZUzytkownikami), adresatMenedzer(nazwaPlikuZAdresatami)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    };*/
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami, string NAZWAPLIKUZADRESATAMI) :
		uzytkownikMenedzer(nazwaPlikuZUzytkownikami), nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {};
	~KsiazkaAdresowa() {
		delete adresatMenedzer;
	}

    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszytkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    //int wylogujUzytkownika();
    void czyUzytkownikJestZalogowany();
    void wypiszWszystkichAdresatow();
    void dodajAdresata();
    char wybierzOpcjeZMenuGlownego();
    int pobierzIdZalogowanegoUzytkownika();
};

#endif
