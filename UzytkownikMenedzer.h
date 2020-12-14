#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"


using namespace std;

class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector<Uzytkownik> uzytkownicy;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami) : plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
		idZalogowanegoUzytkownika = 0;
		uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
	};
    int logowanieUzytkownika();
    int wylogujUzytkownika();
    bool czyUzytkownikJestZalogowany();
    int pobierzIdZalogowanegoUzytkownika();
    void wczytajUzytkownikowZPliku();
    void rejestracjaUzytkownika();
    void wypiszWszytkichUzytkownikow();
    void zmianaHaslaZalogowanegoUzytkownika();
    void zapiszWszystkichUzytkownikowDoPliku();


    //int ustawIdZalogowanegoUzytkownika();
};

#endif
