/*********************
 *Program: Home.cpp
 *Date:8/10/19
 *Author: Glenn Frutiz
 *Description: This is the class 
 *definition for the Home class.
 *This is a derived class of Node.
 * *******************/

#include "Node.hpp"
#include "Home.hpp"
#include <iostream>
/**********************
 *	Home::Home
 *
 *This sets the values of the member variables inherited from the 
 *Node class.
 *
 * ********************/
Home::Home(Node* nextNode, Node* prevNode)
{
  // setVal(value);
   setRight(nextNode);
   setLeft(prevNode);
   up = nullptr;
   down = nullptr;
} 
/**********************
 *	Home::event
 *This displays a message when this node is accessed.
 *Returns a value of 1 so that it may be passed to the switch 
 *statement that may end the game or not.
 *
 * *******************/
int Home::event()
{
   std::cout<<"You are home. "<<std::endl;
   return 1;
}



