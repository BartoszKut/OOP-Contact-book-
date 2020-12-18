#include "PlikTekstowy.h"


bool PlikTekstowy::czyPlikJestPusty() {
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true) {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}


string PlikTekstowy::pobierzNazwePliku() {
    return NAZWA_PLIKU;
}


void PlikTekstowy::dopisz(string tekst) {
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

    if (plikTekstowy.good() == true)        {
        if (czyPlikJestPusty())
            plikTekstowy << "To jest poczatek pliku" << endl;

        plikTekstowy << tekst << endl;
    }
    plikTekstowy.close();
}