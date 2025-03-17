#include "komendy.hpp"

string nazwa;
float cena;
int ilosc;
string opis;
string kategoria;

vector<Produkt<string, float, string, string>> magazyn;//vector with item based on class Product

void first_info()
{
    cout << "Witaj w symulatorze obslugi magazynu!" << endl;
    cout << "Z poziomu tej strony mozesz zarzadzac twoimi towarami... " << endl;
    cout << "Wybierz opcje, ktora chcesz uzyc:" << endl;
    cout << endl;
    cout << "1. Dodawanie nowych produktów do magazynu" << endl;
    cout << "2. Usuwanie istniejących produktów" << endl;
    cout << "3. Edytowanie szczegółów produktu" << endl;
    cout << "4. Kopiowanie produktów" << endl;
    cout << "5. Wyświetlanie zawartości magazynu" << endl;
    cout << "6. Wyjscie z aplikacji... " << endl;
    cout << endl;
}

int your_choice()
{
    cout << endl;
    cout << "Wybor: ";
    int temp1;
    cin >> temp1;

    if (temp1 < 1 || temp1 > 6) // only possible options
    {
        system("clear");
        cout << "Wybor niepoprawny... " << endl;
        cout << "Wybierz jeszcze raz!";
        cout << endl;
        cout << "Wybor: ";
        cin >> temp1;
    }

    return temp1;
}

void open_fun()
{
    while (true)
    {
        int opt = your_choice();

        switch (opt)
        {
        case 1:
            system("clear");
            cout << "1. Dodawanie nowych produktów do magazynu" << endl
                 << endl;

            cout << "Nazwa: ";
            cin >> nazwa;
            cout << endl
                 << endl;

            cout << "Cena: ";
            cin >> cena;
            cout << endl
                 << endl;

            cout << "Ilosc: ";
            cin >> ilosc;
            cout << endl
                 << endl;

            cout << "Opis: ";
            cin >> opis;
            cout << endl
                 << endl;

            cout << "Kategoria: ";
            cin >> kategoria;
            cout << endl
                 << endl;

            break;

        case 2:
            system("clear");
            cout << "2. Usuwanie istniejących produktów" << endl
                 << endl;

            cout << "Wprowadz nazwe, kategorie, cene oraz ilosc: " << endl;

            cout << "Nazwa: ";
            cin >> nazwa;
            cout << endl
                 << endl;

            cout << "Kategoria: ";
            cin >> kategoria;
            cout << endl
                 << endl;

            cout << "Cena: ";
            cin >> cena;
            cout << endl
                 << endl;

            cout << "Ilosc: ";
            cin >> ilosc;
            cout << endl
                 << endl;

            break;

        case 3:
            system("clear");
            cout << "3. Edytowanie szczegółów produktu" << endl
                 << endl;

            cout << "Wprowadz nazwe, kategorie: " << endl;

            cout << "Nazwa: ";
            cin >> nazwa;
            cout << endl
                 << endl;

            cout << "Kategoria: ";
            cin >> kategoria;
            cout << endl
                 << endl;

            break;

        case 4:
            system("clear");
            cout << "4. Kopiowanie produktów" << endl;

            cout << "Wprowadz nazwe, kategorie oraz ilosc: " << endl;

            cout << "Nazwa: ";
            cin >> nazwa;
            cout << endl
                 << endl;

            cout << "Kategoria: ";
            cin >> kategoria;
            cout << endl
                 << endl;

            cout << "Ilosc: ";
            cin >> ilosc;
            cout << "Cena: ";
            cin >> cena;
            cout << endl
                 << endl;

            cout << endl
                 << endl;

            break;

        case 5:
            system("clear");
            cout << "5. Wyświetlanie zawartości magazynu" << endl;

            break;

        case 6:
            exit(0);

            break;

        default:
            //
            break;
        }
    }
}
