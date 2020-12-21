#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {
    const string NAZWA_PLIKU;
public:
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {}
    string pobierzNazwePliku();
    bool czyPlikJestPusty();
    void dopisz(string tekst);//nie rozumiem zadania tej funkcji
    void usunPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazwePliku(string staraNazwa, string nowaNazwa);//obiet metody moga isc do prywantych
};

#endif
