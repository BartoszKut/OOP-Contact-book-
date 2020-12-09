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
    int konwersjaStringNaInt(string liczba);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
};

#endif
