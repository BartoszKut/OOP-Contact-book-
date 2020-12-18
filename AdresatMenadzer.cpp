#include "AdresatMenadzer.h"


Adresat AdresatMenadzer::podajDaneNowegoAdresata(){
    Adresat adresat;
    string imie, nazwisko, numerTelefonu, email, adres;
    adresat.ustawId(pobierzIdOstatniegoAdresata()); //zwracana jest wartosc o 1 wieksza od id ostaniego adresat
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    imie = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj nazwisko: ";
    nazwisko = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj numer telefonu: ";
    numerTelefonu = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj email: ";
    email = MetodyPomocnicze::wczytajLinie();

    cout << "Podaj adres: ";
    adres = MetodyPomocnicze::wczytajLinie();

    adresat.ustawImie(imie);
    adresat.ustawNazwisko(nazwisko);
    adresat.ustawNumerTelefonu(numerTelefonu);
    adresat.ustawEmail(email);
    adresat.ustawAdres(adres);

    return adresat;
}


int AdresatMenadzer::pobierzIdOstatniegoAdresata(){
    if (adresaci.empty() == true)
        return 1;
    else
        return adresaci.back().pobierzId() + 1;
}


void AdresatMenadzer::wyswietlDaneAdresata(Adresat adresat){
    cout << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Id zal. uzyt. :     " << adresat.pobierzIdUzytkownika() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}


void AdresatMenadzer::dodajAdresata(){
    Adresat adresat = podajDaneNowegoAdresata();

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    cout << endl << "Adresat dodany pomyslnie" << endl;
    system("pause");
}


void AdresatMenadzer::wyswietlWszystkichAdresatow(){
    system("cls");
    if (!adresaci.empty()){
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> ::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
            wyswietlDaneAdresata(*itr);
            cout << "-----------------------------------------------" << endl;
        }
        cout << endl;
    }
    else{
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}


void AdresatMenadzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                wyswietlDaneAdresata(*itr);
                cout << endl;
                iloscAdresatow++;
            }
        }
        wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}


void AdresatMenadzer::wyswietlIloscWyszukanychAdresatow(int iloscAdresatow){
    if (iloscAdresatow == 0)
        cout << endl << "W ksiazce adresowej nie ma adresatow z tymi danymi." << endl;
    else
        cout << endl << "Ilosc adresatow w ksiazce adresowej wynosi: " << iloscAdresatow << endl << endl;
}


void AdresatMenadzer::wyszukajAdresatowPoNazwisku(){
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++){
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata){
                wyswietlDaneAdresata(*itr);
                cout << endl;
                iloscAdresatow++;
            }
        }
         wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else{
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}


/*int AdresatMenadzer::usunAdresata() {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    odczytywanyPlikTekstowy.open(plikZAdresatami(nazwaPlikuZAdresatami).c_str(), ios::in);
    tymczasowyPlikTekstowy.open("AdresaciTymczasowy.txt".c_str(), ios::out | ios::app);

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++) {
        if (itr -> pobierzId() == idUsuwanegoAdresata) {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't') {
                //continue;
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;
            } else {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("p       ause");
                return 0;
            }

        }
        if (odczytywanyPlikTekstowy.good() == true && numerUsuwanejLinii != 0) {
            while (getline(odczytywanyPlikTekstowy, wczytanaLinia)) {
                // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
                // aby na koncu pliku nie bylo pustej linii
                if (numerWczytanejLinii == numerUsuwanejLinii) {}
                else if (numerWczytanejLinii == 1 && numerWczytanejLinii != numerUsuwanejLinii)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii == 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << wczytanaLinia;
                else if (numerWczytanejLinii > 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
                else if (numerWczytanejLinii > 1 && numerUsuwanejLinii != 1)
                    tymczasowyPlikTekstowy << endl << wczytanaLinia;
                numerWczytanejLinii++;
            }
        }
        if (czyIstniejeAdresat == false) {
            cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
            system("pause");
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        usunPlik(nazwaPlikuZAdresatami);
        zmienNazwePliku(nazwaTymczasowegoPlikuZAdresatami, nazwaPlikuZAdresatami);
        return 0;
    }
}*/


int AdresatMenadzer::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}


void AdresatMenadzer::usunPlik(string nazwaPlikuZRozszerzeniem) {
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}


void AdresatMenadzer::zmienNazwePliku(string staraNazwa, string nowaNazwa){
    if (rename(staraNazwa.c_str(), nowaNazwa.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << staraNazwa << endl;
}
