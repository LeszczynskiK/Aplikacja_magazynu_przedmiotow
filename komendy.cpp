#include "komendy.hpp"
#include "Magazyn.hpp"
#include <algorithm>

void first_info()
{
     // inform about possible ways to work with!
     cout << "1. Dodawanie nowych produktów do magazynu" << endl;
     cout << "2. Usuwanie istniejących produktów" << endl;
     cout << "3. Edytowanie szczegółów produktu" << endl;
     cout << "4. Kopiowanie produktów" << endl;
     cout << "5. Wyświetlanie zawartości magazynu" << endl;
     cout << "6. Wyjscie z aplikacji... " << endl;
     cout << endl;
}

void open_fun(Magazyn &mag)//commands to manage warehouse
{ // this methor is to call method which you choose(with the argument of vector which collects items)
     while (true)
     {
          first_info();
          cout<<endl;
     
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
          cout<<endl<<endl;
          cout << "Nacisnij Enter aby kontynuowac..."<<endl;
          cin.ignore(); // clear buffor from old chars (is any left in buffor)
          system("clear");
          cout<<"Przejdz do menu wyboru!"<<endl;
          cin.get();    // and wait wor any cin here to continue while(true)
          system("clear");
     }
}