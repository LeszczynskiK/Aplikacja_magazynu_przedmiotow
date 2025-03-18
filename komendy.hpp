#ifndef KOMENDY_HPP
#define KOMENDY_HPP

#include <iostream>
#include <string>
#include <vector>

#include "obiekt.hpp"

using namespace std;

class Magazyn
{ // class to manage warehouse
private:
    vector<Produkt<string, float, string, Kategoria>> magazyn; // we need to pass type of: nazwa,cena,opis,kategoria(this is enum type)

public:
    // methods to work on warehouse
    void addItem();      // add new item
    void deleteItem();   // delete item
    void editItem();     // edit fields of item
    void copyItem();     // put the same item in vector (copy)
    void displayItems(); // show all of the items in vecotr
};

void first_info();           // 1st message in app - welcome etc...
int your_choice();           // your choise of operation
void open_fun(Magazyn &mag); // funcitonality action based on your choose

#endif // KOMENDY_HPP