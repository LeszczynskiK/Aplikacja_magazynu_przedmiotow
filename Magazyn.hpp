#ifndef MAGAZYN_HPP
#define MAGAZYN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "obiekt.hpp"
#include "inputProtection.hpp"

using namespace std;

class Magazyn
{ // class to manage warehouse
private:
    vector<Produkt<string, float, string, Kategoria>> magazyn; // we need to pass type of: nazwa,cena,opis,kategoria(this is enum type)
    // so it will be string, float, string and enum type(Kategoria - 3 possibilities to work on here 0,1,2)

public:
    // methods to work on warehouse
    void addItem();      // add new item
    void deleteItem();   // delete item
    void editItem();     // edit fields of item
    void copyItem();     // put the same item in vector (copy)
    void displayItems(); // show all of the items in vecotr
};

void open_fun(Magazyn &mag); // funcitonality action based on your choose - with the reference to Magazyn object! (we will work on input type of Magazyn)

#endif // MAGAZYN_HPP