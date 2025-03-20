#include <iostream>
#include <string>
using namespace std;

#include "komendy.hpp"
#include "obiekt.hpp"
#include "Magazyn.hpp"
#include "inputProtection.hpp"

int main()
{
    system("clear");
    cout << "Witaj w symulatorze obslugi magazynu!" << endl;
    cout << "Z poziomu tej strony mozesz zarzadzac twoimi towarami... " << endl;
    cout << "Wybierz opcje, ktora chcesz uzyc:" << endl;
    cout << endl;

    first_info();

    Magazyn magazyn; // create object magazyn

    open_fun(magazyn); // choose what you want to do now... - with the argument of exact Magazyn object(will work on this object all the time)

    return 0;
}