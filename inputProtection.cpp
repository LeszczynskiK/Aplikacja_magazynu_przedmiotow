#include "inputProtection.hpp"

bool your_choice_bool = false;//definition of variable

// get not empty string as input
string getString(const string &msg) // msg is value which we put in and display here...
{
     string input; // string tye input

     do // load nazwa untill is not empty - can be any type becouse its string, but can not be empty
     {
          if (cin.peek() == '\n') // this will check 1st char before data loading from cin - so it will get enter if clicked
          {                       // if enter was clicked immediatyly (new line ) - peek will get this!
               system("clear");
               cout << "Wartosc nie moze byc pusta! Wprowadz ponownie." << endl;
               cout << msg;
               cin >> input;
               cin.ignore();;//always ignore 1 char after cin (this char is new line char!)
          }
          else // not clicked enter immediately (there is something typped in)
          {
               cout << msg;
               cin >> input;
               cin.ignore();;//always ignore 1 char after cin (this char is new line char!)
          }

          if (input.empty())
          {
               system("clear");
               cout << "Wartosc nie moze byc pusta! Wprowadz ponownie." << endl;
          }

     } while (input.empty());

     return input;
}

// get not empty float(with some conditions on it) as input
float getFloat(const string &msg) // msg is value which we put in and display here...
{
     float value;
     bool correct_float=false;
     do
     {

          if (cin.peek() == '\n') // this will check 1st char before data loading from cin - so it will get enter if clicked
          {                       // if enter was clicked immediatyly (new line ) - peek will get this!
               system("clear");
               cout << "Wartosc nie moze byc pusta! Wprowadz ponownie." << endl;
               cout << msg;
               cin >> value;
               cin.ignore();//always ignore 1 char after cin (this char is new line char!)
          }
          else // not clicked enter immediately (there is something typped in)
          {
               cout << msg;
               cin >> value;
               cin.ignore();;//always ignore 1 char after cin (this char is new line char!)
          }
          if (cin.fail() || value < 0) // cin.fail() - if typped other than declarated type, will return 1 so fail..
          {
               system("clear");
               cout << "Wartosc musi byc liczba nieujemna! Wprowadz ponownie." << endl;
               cin.clear();  // clear fail flag
               cin.ignore(); // clear buffor
          }
          else
          {
               correct_float = true; // correct data was written, change bool variable to true
          }
     } while (!correct_float); //loop untill you get correct price\

     return value;
}

// get not empty int(with some conditions on it) as input
int getInt(const string &msg) // msg is value which we put in and display here...
{
     bool correct_int = false; // ilosc can not be <0 and have to be int
     int value;
     do
     {
          if (cin.peek() == '\n') // this will check 1st char before data loading from cin - so it will get enter if clicked
          {                       // if enter was clicked immediatyly (new line ) - peek will get this!
               system("clear");
               cout << "Wartosc nie moze byc pusta! Wprowadz ponownie." << endl;
               if (your_choice_bool) // if we are in your_choice function now, print this
               {
                    cout << "1. Dodawanie nowych produktów do magazynu" << endl;
                    cout << "2. Usuwanie istniejących produktów" << endl;
                    cout << "3. Edytowanie szczegółów produktu" << endl;
                    cout << "4. Kopiowanie produktów" << endl;
                    cout << "5. Wyświetlanie zawartości magazynu" << endl;
                    cout << "6. Wyjscie z aplikacji... " << endl
                         << endl;
               }
               cout << msg;
               cin >> value;
               cin.ignore();//always ignore 1 char after cin (this char is new line char!)
          }
          else // if not enter immediately
          {
               cout << msg;
               cin >> value;

               cin.ignore(); // clear 1 char from buffor (it always be \n - new line, becouse here we are after type checking)
               // and we are sure that typped value is correct type, so we only need to delete new line char( after enter typping!)
          }

          if (cin.fail() || value < 0) // if <0 and not int, fail
          {
               system("clear");
               cout << "Wartosc musi byc liczba calkowita nieujemna! Wprowadz ponownie." << endl;
               cin.clear();          // clear error flag
               cin.ignore();         // clear buffor
               if (your_choice_bool) // if we are in your_choice function now, print this
               {
                    cout << "1. Dodawanie nowych produktów do magazynu" << endl;
                    cout << "2. Usuwanie istniejących produktów" << endl;
                    cout << "3. Edytowanie szczegółów produktu" << endl;
                    cout << "4. Kopiowanie produktów" << endl;
                    cout << "5. Wyświetlanie zawartości magazynu" << endl;
                    cout << "6. Wyjscie z aplikacji... " << endl
                         << endl;
               }
          }
          else
          {
               correct_int = true; // correct data was written, change bool variable to true
          }
     } while (!correct_int); // loop untill you get correct ilosc

     return value;
}

// get value 0,1,2 to use it later to enum type
Kategoria getCategory(const string &msg) // msg is value which we put in and display here...
{
     // based on enum type(so put 0,1 or 2)
     bool correct_kategoria = false;
     int value;
     do
     {
          if (cin.peek() == '\n') // this will check 1st char before data loading from cin - so it will get enter if clicked
          {                       // if enter was clicked immediatyly (new line ) - peek will get this!
               system("clear");
               cout << "Wartosc nie moze byc pusta! Wprowadz ponownie." << endl;
               cout << msg;
               cin >> value;
               cin.ignore();//always ignore 1 char after cin (this char is new line char!)
          }
          else // not clicked enter immediately (there is something typped in)
          {
               cout << msg;
               cin >> value;
               cin.ignore();//always ignore 1 char after cin (this char is new line char!)
          }

          if (cin.fail() || value < 0 || value > 2)
          { // have to be int type, and have to be 0,1, or 2
               system("clear");
               cout << "Kategoria musi byc liczba calkowita od 0 do 2! Wprowadz ponownie." << endl;
               cin.clear();  // clear error flag
               cin.ignore(); // clear buffor
          }
          else
          {
               correct_kategoria = true; // correct data was written, change bool variable to true
          }
     } while (!correct_kategoria); // loop untill you get correct input

     return static_cast<Kategoria>(value); // int have to be changed on Kategoria type
}

int your_choice()
{
     your_choice_bool = true;   // means that we are in this funciton right now!
     int temp1;                 // number of option(option is displayed in first_info())
     bool valid_choice = false; // it can only be 1,2,3,4,5,6

     do
     {
          temp1 = getInt("Wybor: ");//get user choose...
          if (temp1 < 1 || temp1 > 6) // can be only 1,2,3,4,5,6 - any over/bellow this is wrong choice! int type
          {
               // manage wrong input (get input once again - will we get correct one!)
               system("clear");
               cout << "Wybor niepoprawny... " << endl;
               cout << "Wybierz jeszcze raz!" << endl
                    << endl;

               cout << "1. Dodawanie nowych produktów do magazynu" << endl;
               cout << "2. Usuwanie istniejących produktów" << endl;
               cout << "3. Edytowanie szczegółów produktu" << endl;
               cout << "4. Kopiowanie produktów" << endl;
               cout << "5. Wyświetlanie zawartości magazynu" << endl;
               cout << "6. Wyjscie z aplikacji... " << endl
                    << endl;
          }
          else
          {
               valid_choice = true; // if choosed option 1,2,3,4,5 or 6 then your choose is correct
          }
     } while (!valid_choice); // if choice is not 1,2,3,4,5 or 6...

     your_choice_bool = false; // means that we are leavig this funciton right now!
     return temp1;             // operation choise is returned
}