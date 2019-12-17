/*********************
 *Author: Glenn Frutiz
 *Date: 7/31/19
 *Description: This is the main file for 
 *the Final Project
 * *********************/


#include<cstdlib>
#include<ctime>
#include "Menu.hpp"
int main()
{
   //seed rand
   std::srand(static_cast<unsigned int>(std::time(nullptr)));
   Menu finalProject;//make Menu object
   finalProject.startGame();//start the game

   return 0;

                    
}
