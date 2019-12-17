/*********************
 *Program: GoodDog.cpp
 *Date:8/10/19
 *Author: Glenn Frutiz
 *Description: This is the class 
 *declaration for the GoodDog class.
 *GoodDog is a derived class of Node.
 * *******************/

#include "Node.hpp"
#include "GoodDog.hpp"
#include <iostream>
/**********************
 *	GoodDog::GoodDog
 *
 *This sets the values of the
 * member variables inherited from the Node class.
 *
 *
 * *******************/     
GoodDog::GoodDog(Node* nextNode, Node* prevNode)
{
  // setVal(value);
   setRight(nextNode);
   setLeft(prevNode);
   up = nullptr;
   down = nullptr;
} 
/*********************
 *	GoodDog::event
 *This displays a message when the node is accessed and returns a value 
 *of 2. The value of 2 is passed to a switch statement to cause nothing to
 *happen.
 * *******************/
int GoodDog::event()
{
   std::cout<<"Your dog was a good dog this turn. "<<std::endl;
   return 2;
}

