#include "AdresatMenedzer.h"


int AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}


int AdresatMenedzer::dodajAdresata()
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    dopiszAdresataDoPliku(adresat);

    return ++idOstatniegoAdresata;
}


Adresat AdresatMenedzer::podajDaneNowegoAdresata()
{
    string Imie, Nazwisko, NumerTelefonu, Email, Adres;
    Adresat adresat;

    adresat.ustawId(++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    cin >> Imie;
    zamienPierwszaLitereNaDuzaAPozostaleNaMale(Imie);
    adresat.ustawImie(Imie);

    cout << "Podaj nazwisko: ";
    cin >> Nazwisko;
    zamienPierwszaLitereNaDuzaAPozostaleNaMale(Nazwisko);
    adresat.ustawNazwisko(Nazwisko);

    cout << "Podaj numer telefonu: ";
    cin >> NumerTelefonu;
    adresat.ustawNumerTelefonu(NumerTelefonu);

    cout << "Podaj numer email: ";
    cin >> Email;
    adresat.ustawEmail(Email);

    cout << "Podaj adres: ";
    cin >> Adres;
    adresat.ustawAdres(Adres);

    return adresat;
}


void AdresatMenedzer::dopiszAdresataDoPliku(Adresat adresat)
{
    plikZAdresatami.dopiszAdresataDoPliku(Adresat adresat);
}


string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst)
{
    MetodyPomocnicze.zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
}
