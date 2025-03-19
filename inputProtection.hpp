#ifndef INPUTPROTECTION_HPP
#define INPUTPROTECTION_HPP

#include <iostream>
#include <string>
using namespace std;

#include "obiekt.hpp"

//HERE are defined functions which protect from typing not required type of data to cin...

extern bool your_choice_bool; // are we in your_choice function? (here is declaration, not definition)
//this have to be extern becouse if not, each file using inputProtection.hpp will create its local copy.. i dont want it

int your_choice();//you can choose 1,2,3,4,5 or 6 mode (save to make impossible to choose any other than these which i said)
Kategoria getCategory(const string &msg);//you can choose only option which is included in Kategoria (so mode 0, 1 or 2)
int getInt(const string &msg);//here can be typped only int one (also not empty, so enter will not pass)
float getFloat(const string &msg);//here can be typped only float one (also not empty, so enter will not pass)
string getString(const string &msg);//here can be typped only string one (also not empty, so enter will not pass)


#endif // INPUTPROTECTION_HPP