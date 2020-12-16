#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika(){
	uzytkownikMenadzer.rejestracjaUzytkownika();
}


void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
	uzytkownikMenadzer.wypiszWszystkichUzytkownikow();
}


void KsiazkaAdresowa::logowanieUzytkownika(){
	uzytkownikMenadzer.logowanieUzytkownika();

	if (uzytkownikMenadzer.czyUzytkownikJestZalogowany())	{
		adresatMenadzer = new AdresatMenadzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika());
	}
}


void KsiazkaAdresowa::wylogowanieUzytkownika(){
	uzytkownikMenadzer.wylogujUzytkownika();
	delete adresatMenadzer;
	adresatMenadzer = NULL;
}


void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
	uzytkownikMenadzer.zmianaHaslaZalogowanegoUzytkownika();
}


void KsiazkaAdresowa::dodajAdresata(){
	if (uzytkownikMenadzer.czyUzytkownikJestZalogowany()){
		adresatMenadzer->dodajAdresata();
	}
	else{
		cout << "Zaloguj sie by dodac adresata." << endl;
		system("pause");
	}
}


void KsiazkaAdresowa::czyUzytkownikJestZalogowany(){
	uzytkownikMenadzer.czyUzytkownikJestZalogowany();
}


void KsiazkaAdresowa::wypiszWszystkichAdresatow(){
	adresatMenadzer->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu(){
    adresatMenadzer->wyszukajAdresatowPoImieniu();
}


void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku(){
    adresatMenadzer->wyszukajAdresatowPoNazwisku();
}


char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego(){
    MetodyPomocnicze::wybierzOpcjeZMenuGlownego();
}


int KsiazkaAdresowa::pobierzIdZalogowanegoUzytkownika(){
    uzytkownikMenadzer.pobierzIdZalogowanegoUzytkownika();
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika() {
    MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
}

int KsiazkaAdresowa::pobierzIdOstatniegoAdresata() {
    adresatMenadzer->pobierzIdOstatniegoAdresata();
}
