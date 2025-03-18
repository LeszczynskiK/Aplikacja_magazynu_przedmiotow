#include "komendy.hpp"
#include <algorithm>

void first_info()
{
     //inform about possible ways to work with!
     cout << "1. Dodawanie nowych produktów do magazynu" << endl;
     cout << "2. Usuwanie istniejących produktów" << endl;
     cout << "3. Edytowanie szczegółów produktu" << endl;
     cout << "4. Kopiowanie produktów" << endl;
     cout << "5. Wyświetlanie zawartości magazynu" << endl;
     cout << "6. Wyjscie z aplikacji... " << endl;
     cout << endl;
}

bool your_choice_bool = false;//are we in your_choice function? 

//get not empty string as input
string getString(const string& msg)//msg is value which we put in and display here...
{
     string input;//string tye input

     do//load nazwa untill is not empty - can be any type becouse its string, but can not be empty
     {
          cout <<msg;
          cin >> input;
          if (input.empty()) 
          {
               system("clear");
               cout << "Wartosc nie moze byc pusta! Wprowadz ponownie." << endl;
          }

     } while (input.empty());

     return input;
}

//get not empty float(with some conditions on it) as input
float getFloat(const string& msg)//msg is value which we put in and display here...
{
     float value;
     bool correct_float;
     do {
          cout <<msg;
          cin >> value;
          if (cin.fail() || value < 0) //cin.fail() - if typped other than declarated type, will return 1 so fail..
          {
               system("clear");
              cout << "Wartosc musi byc liczba nieujemna! Wprowadz ponownie." << endl;
              cin.clear(); //clear fail flag
              cin.ignore();//clear buffor
          } else {
               correct_float = true;//correct data was written, change bool variable to true
          }
      } while (!correct_float);//loop untill you get correct price\

      return value;
}

//get not empty int(with some conditions on it) as input
int getInt(const string& msg)//msg is value which we put in and display here...
{
     bool correct_int = false;//ilosc can not be <0 and have to be int
     int value;
      do {
          cout <<msg;
          cin >> value;
          if (cin.fail() || value < 0) //if <0 and not int, fail
          {
               system("clear");
              cout << "Wartosc musi byc liczba calkowita nieujemna! Wprowadz ponownie." << endl;
              cin.clear();//clear error flag
              cin.ignore();//clear buffor
              if(your_choice_bool)//if we are in your_choice function now, print this
               {
                    cout << "1. Dodawanie nowych produktów do magazynu" << endl;
                    cout << "2. Usuwanie istniejących produktów" << endl;
                    cout << "3. Edytowanie szczegółów produktu" << endl;
                    cout << "4. Kopiowanie produktów" << endl;
                    cout << "5. Wyświetlanie zawartości magazynu" << endl;
                    cout << "6. Wyjscie z aplikacji... " << endl<<endl;
               }
          } else {
               correct_int = true;//correct data was written, change bool variable to true
          }
      } while (!correct_int);//loop untill you get correct ilosc

      return value;
}

//get value 0,1,2 to use it later to enum type
Kategoria getCategory(const string& msg)//msg is value which we put in and display here...
{
       // based on enum type(so put 0,1 or 2)
       bool correct_kategoria = false;
       int value;
       do {
           cout <<msg;
           cin >> value;
           if (cin.fail() || value < 0 || value > 2) {//have to be int type, and have to be 0,1, or 2
               system("clear");
               cout << "Kategoria musi byc liczba calkowita od 0 do 2! Wprowadz ponownie." << endl;
               cin.clear();//clear error flag
               cin.ignore();//clear buffor
           } else {
            correct_kategoria = true;//correct data was written, change bool variable to true
           }
       } while (!correct_kategoria);//loop untill you get correct input

       return static_cast<Kategoria>(value);//int have to be changed on Kategoria type
}

int your_choice()
{
     your_choice_bool = true;//means that we are in this funciton right now!

     //number of option(option is displayed in first_info())
     int temp1 = getInt("Wybor: ");

     if (temp1 < 1 || temp1 > 6) // can be only 1,2,3,4,5,6 - any over/bellow this is wrong choice! int type
     {
          //manage wrong input (get input once again - will we get correct one!)
          system("clear");
          cout << "Wybor niepoprawny... " << endl;
          cout << "Wybierz jeszcze raz!" << endl<<endl;

          cout << "1. Dodawanie nowych produktów do magazynu" << endl;
          cout << "2. Usuwanie istniejących produktów" << endl;
          cout << "3. Edytowanie szczegółów produktu" << endl;
          cout << "4. Kopiowanie produktów" << endl;
          cout << "5. Wyświetlanie zawartości magazynu" << endl;
          cout << "6. Wyjscie z aplikacji... " << endl<<endl;
          cout << "Wybor: ";
          cin >> temp1;
     }
     your_choice_bool = false;//means that we are leavig this funciton right now!
     return temp1; // operation choise is returned
}

void Magazyn::addItem()//add new item
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

void Magazyn::deleteItem()//delete item from vector
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

     if (it != magazyn.end())//if we did not get to the end of vector
     {                                      // if iterator is not on the end of vector
          magazyn.erase(it, magazyn.end()); // means we found item, so can erase it!
          cout << "Produkt usuniety!" << endl;
     }
     else
     { // if iterator at the end... product is not found
          cout << "Nie znaleziono produktu!" << endl;
     }
}

void Magazyn::editItem()//edid existing in vector item
{
     system("clear");
     cout << "3. Edytowanie szczegolow produktu" << endl
          << endl;

   
          string nazwa = getString("Nazwa do edycji przedmiotu: ");

     for (auto &produkt : magazyn)//work on oryginal producs(reference)
     { // iterate throw vector
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

void Magazyn::copyItem()//copy item which exist in vector
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

void Magazyn::displayItems()//display all items which are in vector
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
          first_info();//show possible operations to work on
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