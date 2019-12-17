/**************************
 *Program: Menu.hpp
 *Author: Glenn Frutiz
 *Date: 7/28/19
 *Description: this is the class declaration for the Menu class
 * ************************/
#include "DLL.hpp"
#include "Dog.hpp"
#include <queue>
#ifndef MENU_H
#define MENU_H

class Menu
{
   private:
      bool isHome;
      //int LeashStrength;
      Dog* chihuahua;
      DLL* doubly;
      std::queue<bool> tp;
   public:
      //void chooseFunction();
      void startGame();
      void runGame();      
      void coordinateSpaces();


};
#endif


