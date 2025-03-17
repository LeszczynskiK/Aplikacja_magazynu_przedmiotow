#include <iostream>
#include <string>
using namespace std;


enum class Kategoria //kategoria base on these types, cant be created ny more option!
{
    ZWIERZETA,
    ELEKTRONIKA,
    DOM
};

template<typename T1, typename T2, typename T3, typename T4> class Produkt 
{
    public:

    //object fields- only amoun of item have to be int, res can be interpreted in any type(even described as a word)
    T1 nazwa;
    T2 cena;
    int ilosc;//this have to be int, rest can be any type of variable
    T3 opis;

    Kategoria kategoria;//enum type

    
    Produkt(T1 n, T2 c, int i, T3 o, Kategoria k) : nazwa(n), cena(c), ilosc(i), opis(o), kategoria(k) 
    {
            //constructor
    }

    ~Product() =default;//destructor
};