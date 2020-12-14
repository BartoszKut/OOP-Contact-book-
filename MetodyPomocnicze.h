#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <algorithm>


using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    char wybierzOpcjeZMenuGlownego();
    char wczytajZnak();
};

#endif
