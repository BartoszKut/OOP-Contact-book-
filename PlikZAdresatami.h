#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MetodyPomocnicze.h"
#include "Adresat.h"


using namespace std;

class PlikZAdresatami
{
    const string nazwaPlikuZAdresatami;
    int idZalogowanegoUzytkownika;
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI) : nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI){};
    wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    void dopiszAdresataDoPliku(Adresat adresat);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
};

#endif
