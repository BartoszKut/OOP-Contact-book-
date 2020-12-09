#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>
#include "UzytkownikMenedzer.h"
#include "AdresatMenedzer.h"



using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami)
    {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        adresatMenedzer.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    };

    void rejestracjaUzytkownika();
    int logowanieUzytkownika();
    void wypiszWszytkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    int wylogowywanieUzytkownika();
};

#endif
