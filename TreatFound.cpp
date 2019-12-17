/***********************
` *Program:TreatFound.cpp
 *Date:8/13/19
 *Author:Glenn Frutiz
 *Description: This is the class definition file for the TreatFound class
 *The TreatFound class is a derived class of Node.
 * ********************/
#include "Node.hpp"
#include "TreatFound.hpp"
#include <iostream>
/**********************
 *	TreatFound::TreatFound
 *This sets the values of the member variables.
 *
 * *******************/     
TreatFound::TreatFound(Node* nextNode, Node* prevNode)
{
   //setVal(value);
   setRight(nextNode);
   setLeft(prevNode);

   up = nullptr;
   down = nullptr;
   
} 
/*********************
 *	TreatFound::event()
 *This displays a message when the user chooses a node
 *and it returns a value of 4 for the switch statement
 *that adds a treat to the treat queue.
 * *****************/
int TreatFound::event()
{
   std::cout<<"Your found a dog treat this turn. "<<std::endl;

   return 4;
}


