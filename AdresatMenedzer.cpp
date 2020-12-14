#include "AdresatMenedzer.h"


/*int AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku()
{
    plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku();
}*/


int AdresatMenedzer::pobierzIdOstatniegoAdresata()
{
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}


int AdresatMenedzer::dodajAdresata()
{
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

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
    MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(Imie);
    adresat.ustawImie(Imie);

    cout << "Podaj nazwisko: ";
    cin >> Nazwisko;
    MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(Nazwisko);
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


void AdresatMenedzer::wyswietlDaneAdresata(Adresat adresat)
{
    cout << "Id: " << adresat.pobierzId() << endl;
    cout << "Id zal. uzyt. : " << adresat.pobierzIdUzytkownika() << endl;
    cout << "Imie: " << adresat.pobierzImie() << endl;
    cout << "Nazwisko: " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu: " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email: " << adresat.pobierzEmail() << endl;
    cout << "Adres: " << adresat.pobierzAdres() << endl;
}


void AdresatMenedzer::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> ::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}


/*void AdresatMenedzer::dopiszAdresataDoPliku(Adresat adresat)
{
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
}*/
