#include "UzytkownikMenedzer.h"

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while(czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}


int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}


bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}


void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl;
    system("pause");
}


void UzytkownikMenedzer::wypiszWszytkichUzytkownikow()
{
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzLogin() << endl;
        cout << uzytkownicy[i].pobierzHaslo() << endl;
        cout << uzytkownicy[i].pobierzId() << endl;
    }
}

void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    //PlikZUzytkownikami plikZUzytkownikami;
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

int UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << "Podaj login: ";
    cin >> login;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while (itr != uzytkownicy.end())
    {
        if (itr->pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                cin >> haslo;
                uzytkownik.ustawHaslo(haslo);

                if (itr->pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = itr->pobierzId();
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    Uzytkownik uzytkownik;
    for (int i = 0; i < uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
            string noweHaslo = "";
            cout << "Podaj nowe haslo: ";
            getline(cin, noweHaslo);
            uzytkownicy[i].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }

    }
    //plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownik);
}

int UzytkownikMenedzer::wylogujUzytkownika()
{
    idZalogowanegoUzytkownika = 0;
    cout << "Wylogowano" << endl;
}


bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if (idZalogowanegoUzytkownika > 0) {
        return true;
    }
    else
        return false;
}


int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
{
    return idZalogowanegoUzytkownika;
}


void UzytkownikMenedzer::zapiszWszystkichUzytkownikowDoPliku()
{
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}



