#ifndef OBIEKT_HPP
#define OBIEKT_HPP

#include <iostream>
#include <string>
using namespace std;

enum class Kategoria // kategoria base on these types, cant be created ny more option!
{
    //3 categories of object are avaiable so far - will work only on these types!
    ZWIERZETA,//0
    ELEKTRONIKA,//1
    DOM//2
};

template <typename T1, typename T2, typename T3, typename T4>//4 types from 5 can be random type (set in object creating)
class Produkt
{
public:
    // object fields- only amoun of item have to be int, res can be interpreted in any type(even described as a word)
    T1 nazwa;
    T2 cena;
    int ilosc; // this have to be int, rest can be any type of variable
    T3 opis;

    Kategoria kategoria; // enum type(3 types possible to work on )

    Produkt(T1 n, T2 c, int i, T3 o, Kategoria k) : nazwa(n), cena(c), ilosc(i), opis(o), kategoria(k) // i have to be int(number of items), rest will be set in creating object
    {
        // constructor
    }

    ~Produkt() = default; // destructor

    void disp() // show current item
    {
        cout << "Nazwa: " << nazwa << endl;
        cout << "Cena: " << cena << endl;
        cout << "Ilosc: " << ilosc << endl;
        cout << "Opis: " << opis << endl;
        cout << "Kategoria: ";

        // based on enum type
        switch (kategoria)//categoria can be 0,1 or 2
        {
        case Kategoria::ZWIERZETA:
            cout << "ZWIERZETA";
            break;
        case Kategoria::ELEKTRONIKA:
            cout << "ELEKTRONIKA";
            break;
        case Kategoria::DOM:
            cout << "DOM";
            break;
        }
        cout << endl;
    }
};

#endif // OBIEKT_HPP