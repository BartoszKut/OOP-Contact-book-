#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}


int KsiazkaAdresowa::logowanieUzytkownika()
 {
     uzytkownikMenedzer.logowanieUzytkownika();
     if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
	{
		adresatMenedzer = new AdresatMenedzer(nazwaPlikuZAdresatami, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
	}
 }


 void KsiazkaAdresowa::wypiszWszytkichUzytkownikow()
 {
     uzytkownikMenedzer.wypiszWszytkichUzytkownikow();
 }


 void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
 {
     uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
 }

/*int KsiazkaAdresowa::wylogujUzytkownika()
 {
     uzytkownikMenedzer.wylogujUzytkownika();
 }*/

 void KsiazkaAdresowa::czyUzytkownikJestZalogowany()
{
	uzytkownikMenedzer.czyUzytkownikJestZalogowany();
}


void KsiazkaAdresowa::wypiszWszystkichAdresatow()
{
	adresatMenedzer->wyswietlWszystkichAdresatow();
}


void KsiazkaAdresowa::dodajAdresata()
{
	if (uzytkownikMenedzer.czyUzytkownikJestZalogowany())
	{
		adresatMenedzer->dodajAdresata();
	}
	else
	{
		cout << "Zaloguj sie by dodac adresata." << endl;
		system("pause");
	}
}


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
	MetodyPomocnicze::wybierzOpcjeZMenuGlownego();
}

int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany == false)
        return 0;
}











