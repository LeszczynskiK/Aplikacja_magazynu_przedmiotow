#ifndef KOMENDY_HPP
#define KOMENDY_HPP

#include <iostream>
#include <string>
#include <vector>

#include "obiekt.hpp"
#include "inputProtection.hpp"
#include "Magazyn.hpp"

class Magazyn;//forward declaration(inform that this class exist)

using namespace std;


void first_info();           // 1st message in app - welcome etc...
void open_fun(Magazyn &mag); // funcitonality action based on your choose - with the reference to Magazyn object! (we will work on input type of Magazyn)

#endif // KOMENDY_HPP