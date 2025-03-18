#include "komendy.hpp"
#include <algorithm>

void first_info()
{
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
     int temp1;
     cout << "Wybor: ";
     cin >> temp1;

     while (temp1 < 1 || temp1 > 6) // can be only 1,2,3,4,5,6 - any over/bellow this is wrong choice! int type
     {
          system("clear");
          cout << "Wybor niepoprawny... " << endl;
          cout << "Wybierz jeszcze raz!" << endl;
          cout << "Wybor: ";
          cin >> temp1;
     }
     return temp1; // operation choise is returned
}

void Magazyn::addItem()
{
     system("clear");
     cout << "1. Dodawanie nowych produktów do magazynu" << endl
          << endl;

     string nazwa;
     string opis;
     float cena;
     int ilosc;
     int kat;

     cout << "Nazwa: ";
     cin >> nazwa;

     cout << "Cena: ";
     cin >> cena;

     cout << "Ilosc: ";
     cin >> ilosc;

     cout << "Opis: ";
     cin >> opis;

     // based on enum type(so put 0,1 or 2)
     cout << "Kategoria (0-ZWIERZETA, 1-ELEKTRONIKA, 2-DOM): "; // only 0,1,2 is acceptable
     cin >> kat;

     Kategoria kategoria = static_cast<Kategoria>(kat); // cast kat(int type) to Kategoria type(and save it to kategoria variable)

     magazyn.push_back(Produkt<string, float, string, Kategoria>(nazwa, cena, ilosc, opis, kategoria)); // save this object in vector(i want Producs to have this type of arguments...)
     cout << "Produkt dodany!" << endl;                                                                 // inform that adding suceed
}

void Magazyn::deleteItem()
{
     system("clear");
     cout << "2. Usuwanie istniejących produktow" << endl
          << endl;

     string nazwa;
     cout << "Podaj nazwe produktu do usuniecia: ";
     cin >> nazwa; // put name of item  - delete item will base on this name here

     auto it = remove_if(magazyn.begin(), magazyn.end(),
                         [&nazwa](Produkt<string, float, string, Kategoria> &p) // lambda funciton - get nazwa, arguments is object Product with specyfic arguments(its name is p - will ge tinto with reference)
                         {
                              return p.nazwa == nazwa; // return 1 if found item with typped by us fields
                         });

     if (it != magazyn.end())
     {                                      // if iterator is not on the end of vector
          magazyn.erase(it, magazyn.end()); // means we found item, so can erase it!
          cout << "Produkt usuniety!" << endl;
     }
     else
     { // if iterator at the end... product is not found
          cout << "Nie znaleziono produktu!" << endl;
     }
}

void Magazyn::editItem()
{
     system("clear");
     cout << "3. Edytowanie szczegolow produktu" << endl
          << endl;

     string nazwa;
     cout << "Podaj nazwe produktu do edycji: ";
     cin >> nazwa; // put name of item  - edit item will base on this name here

     for (auto &produkt : magazyn)
     { // iterate throw vector
          if (produkt.nazwa == nazwa)
          { // if your typeed name found...

               // edit rest of fields here
               cout << "Nowa cena: ";
               cin >> produkt.cena;

               cout << "Nowa ilosc: ";
               cin >> produkt.ilosc;

               cout << "Nowy opis: ";
               cin >> produkt.opis;

               cout << "Produkt zaktualizowany!" << endl; // and inform that changed
               return;
          }
     }
     cout << "Nie znaleziono produktu!" << endl;
}

void Magazyn::copyItem()
{
     system("clear");
     cout << "4. Kopiowanie produktów" << endl
          << endl;

     string nazwa;
     cout << "Podaj nazwe produktu do skopiowania: ";
     cin >> nazwa;

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

void Magazyn::displayItems()
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

void open_fun(Magazyn &mag)
{ // this methor is to call method which you choose(with the argument of vector which collects items)
     while (true)
     {
          first_info();
          int opt = your_choice(); // get value (number) of your method choose

          switch (opt)
          { // run this function whuch you choosen in your_choice()
          case 1:
               mag.addItem();
               break;
          case 2:
               mag.deleteItem();
               break;
          case 3:
               mag.editItem();
               break;
          case 4:
               mag.copyItem();
               break;
          case 5:
               mag.displayItems();
               break;
          case 6:
               exit(0);
          }
          cout << "Nacisnij Enter aby kontynuowac...";
          cin.ignore(); // clear buffor from old chars (is any left in buffor)
          cin.get();    // and wait wor any cin here to continue while(true)
          system("clear");
     }
}