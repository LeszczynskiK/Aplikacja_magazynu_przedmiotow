#include "Magazyn.hpp"

void Magazyn::addItem() // add new item
{
     system("clear");
     cout << "1. Dodawanie nowych produktów do magazynu" << endl
          << endl;

     string nazwa = getString("Nazwa: ");
     float cena = getFloat("Cena: ");
     int ilosc = getInt("Ilosc: ");
     string opis = getString("Opis: ");
     Kategoria kategoria = getCategory("Kategoria (0-ZWIERZETA, 1-ELEKTRONIKA, 2-DOM): ");

     magazyn.push_back(Produkt<string, float, string, Kategoria>(nazwa, cena, ilosc, opis, kategoria)); // save this object in vector(i want Producs to have this type of arguments...)
     cout << "Produkt dodany!" << endl;                                                                 // inform that adding suceed
}

void Magazyn::deleteItem() // delete item from vector
{
     system("clear");
     cout << "2. Usuwanie istniejących produktow" << endl
          << endl;

     string nazwa = getString("Nazwa do usuniecia przedmiotu: ");

     auto it = remove_if(magazyn.begin(), magazyn.end(),
                         [&nazwa](Produkt<string, float, string, Kategoria> &p) // lambda funciton - get nazwa, arguments is object Product with specyfic arguments(its name is p - will ge tinto with reference)
                         {
                              return p.nazwa == nazwa; // return 1 if found item with typped by us fields(typped name exist)
                         });

     if (it != magazyn.end())               // if we did not get to the end of vector
     {                                      // if iterator is not on the end of vector
          magazyn.erase(it, magazyn.end()); // means we found item, so can erase it!
          cout << "Produkt usuniety!" << endl;
     }
     else
     { // if iterator at the end... product is not found
          cout << "Nie znaleziono produktu!" << endl;
     }
}

void Magazyn::editItem() // edid existing in vector item
{
     system("clear");
     cout << "3. Edytowanie szczegolow produktu" << endl
          << endl;

     string nazwa = getString("Nazwa do edycji przedmiotu: ");

     for (auto &produkt : magazyn) // work on oryginal producs(reference)
     {                             // iterate throw vector
          if (produkt.nazwa == nazwa)
          { // if your typeed name found...

               // edit rest of fields here
               produkt.cena = getFloat("Nowa cena: ");
               produkt.ilosc = getInt("Nowa ilosc: ");
               produkt.opis = getString("Nowy opis: ");

               cout << "Produkt zaktualizowany!" << endl; // and inform that changed
               return;
          }
     }
     cout << "Nie znaleziono produktu!" << endl;
}

void Magazyn::copyItem() // copy item which exist in vector
{
     system("clear");
     cout << "4. Kopiowanie produktów" << endl
          << endl;

     string nazwa = getString("Nazwa do skopiowania przedmiotu: ");

     for (auto &produkt : magazyn)
     { // iterate throw vector
          if (produkt.nazwa == nazwa)
          {                                // if found by bame
               magazyn.push_back(produkt); // push back item producs(it will have arguments the same co item will be copied)
               cout << "Produkt skopiowany!" << endl;
               return;
          }
     }
     cout << "Nie znaleziono produktu!" << endl;
}

void Magazyn::displayItems() // display all items which are in vector
{
     system("clear");
     cout << "5. Wyswietlanie zawartości magazynu" << endl
          << endl;

     if (magazyn.empty())
     { // if vector is empty
          cout << "Magazyn jest pusty!" << endl;
     }
     else
     {
          for (auto &produkt : magazyn)
          {                    // if not empty, iterate throw vector
               produkt.disp(); // use created in .hpp class to display info about producs! (actual one display - based on vector magazyn)
               cout << "-------------------" << endl;
          }
     }
}