#include "inputProtection.hpp"

bool your_choice_bool = false; // Definicja zmiennej globalnej

string getString(const string &msg) {
    string input;
    bool valid = false;

    do {
        cout << msg;
        getline(cin, input);

        if (input.empty()) {
            system("clear");
            cout << "Wartosc nie moze byc pusta! Wprowadz ponownie." << endl;
        } else {
            valid = true;
        }
    } while (!valid);

    return input;
}

float getFloat(const string &msg) {
    float value;
    string input;
    bool valid = false;

    do {
        cout << msg;
        getline(cin, input);

        try {
            size_t pos;
            value = stof(input, &pos);
            if (pos != input.length()) {
                throw invalid_argument("Nieprawidłowy format");
            }
            if (value < 0) {
                system("clear");
                cout << "Wartosc musi byc nieujemna! Wprowadz ponownie." << endl;
            } else {
                valid = true;
            }
        } catch (...) {
            system("clear");
            cout << "Wartosc musi byc liczba nieujemna! Wprowadz ponownie." << endl;
        }
    } while (!valid);

    return value;
}

int getInt(const string &msg) {
    int value;
    string input;
    bool valid = false;

    do {
        cout << msg;
        getline(cin, input);

        try {
            size_t pos;
            value = stoi(input, &pos);
            if (pos != input.length()) {
                throw invalid_argument("Nieprawidłowy format");
            }
            if (value < 0) {
                system("clear");
                cout << "Wartosc musi byc liczba calkowita nieujemna! Wprowadz ponownie." << endl;
                if (your_choice_bool) {
                    cout << "1. Dodawanie nowych produktów do magazynu" << endl;
                    cout << "2. Usuwanie istniejących produktów" << endl;
                    cout << "3. Edytowanie szczegółów produktu" << endl;
                    cout << "4. Kopiowanie produktów" << endl;
                    cout << "5. Wyświetlanie zawartości magazynu" << endl;
                    cout << "6. Wyjscie z aplikacji... " << endl << endl;
                }
            } else {
                valid = true;
            }
        } catch (...) {
            system("clear");
            cout << "Wartosc musi byc liczba calkowita nieujemna! Wprowadz ponownie." << endl;
            if (your_choice_bool) {
                cout << "1. Dodawanie nowych produktów do magazynu" << endl;
                cout << "2. Usuwanie istniejących produktów" << endl;
                cout << "3. Edytowanie szczegółów produktu" << endl;
                cout << "4. Kopiowanie produktów" << endl;
                cout << "5. Wyświetlanie zawartości magazynu" << endl;
                cout << "6. Wyjscie z aplikacji... " << endl << endl;
            }
        }
    } while (!valid);

    return value;
}

Kategoria getCategory(const string &msg) {
    int value;
    string input;
    bool valid = false;

    do {
        cout << msg;
        getline(cin, input);

        try {
            size_t pos;
            value = stoi(input, &pos);
            if (pos != input.length()) {
                throw invalid_argument("Nieprawidłowy format");
            }
            if (value < 0 || value > 2) {
                system("clear");
                cout << "Kategoria musi byc liczba calkowita od 0 do 2! Wprowadz ponownie." << endl;
            } else {
                valid = true;
            }
        } catch (...) {
            system("clear");
            cout << "Kategoria musi byc liczba calkowita od 0 do 2! Wprowadz ponownie." << endl;
        }
    } while (!valid);

    return static_cast<Kategoria>(value);
}

int your_choice() {
    your_choice_bool = true;
    int choice;
    bool valid = false;

    do {
        choice = getInt("Wybor: ");
        if (choice < 1 || choice > 6) {
            system("clear");
            cout << "Wybor niepoprawny! Wybierz jeszcze raz!" << endl << endl;
            cout << "1. Dodawanie nowych produktów do magazynu" << endl;
            cout << "2. Usuwanie istniejących produktów" << endl;
            cout << "3. Edytowanie szczegółów produktu" << endl;
            cout << "4. Kopiowanie produktów" << endl;
            cout << "5. Wyświetlanie zawartości magazynu" << endl;
            cout << "6. Wyjscie z aplikacji... " << endl << endl;
        } else {
            valid = true;
        }
    } while (!valid);

    your_choice_bool = false;
    return choice;
}