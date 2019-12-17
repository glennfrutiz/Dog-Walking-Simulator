/*********************
 *Program: LeashPull.cpp
 *Date:8/10/19
 *Author: Glenn Frutiz
 *Description: This is the class 
 *definition for the LeashPull class.
 *The LeashPull class is a derived class of Node.
 * *******************/

#include "DLL.hpp"
#include "Node.hpp"
#include "LeashPull.hpp"
#include <iostream>
/*********************
 *	LeashPull::LeashPull
 *This constructor sets the values for the 
 *member variables inherited from Node.
 *
 * *******************/
LeashPull::LeashPull(Node* nextNode, Node* prevNode)
{
   //setVal(value);
   setRight(nextNode);
   setLeft(prevNode);
   up = nullptr;
   down = nullptr; 
} 
/************************
 *	LeashPull::event
 *This displays a message if this Node is selected. 
 *It returns 3 to interact with the switch statement that 
 *decides whether to decrease LeashStrength or pop a treat.
 * *********************/
int LeashPull::event()
{
   std::cout<<"Your dog sees a squirrel."<<std::endl;
   
   return 3;
  
}





