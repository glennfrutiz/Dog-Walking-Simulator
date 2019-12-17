/*************************
 *Program: Node.cpp
 *Author: Glenn Frutiz
 *DateL7/30/19
 *Description: This is the class implmentation file for the Node class
 * *************************/
#include "Node.hpp"
#include <string>
#include <iostream>
/******************
 *	Node::event
 *used to see if there is a logic error for the event pure member function.
 * *****************/
int Node::event()
{
   std::cout<<"There is no event in the Node class."<<std::endl;

}
/**********************
 *	Node::getIsHome
 *returns the value of the isHome variable
 * *******************/
bool Node::getIsHome()
{
   return isHome;

}
/***********************
 *	Node::setIsHome
 *sets the bool variable used to determine if a Node is a Home derived class
 *
 * ********************/
void Node::setIsHome(bool homeOrNotHome)
{
   isHome = homeOrNotHome;

}

/***********************
 *	Node::getNext
 *returns Node* next
 *
 * ********************/
Node* Node::getRight()
{
  return right;

}
/**************************
 *	Node::getPrev
 *returns Node* prev
 *
 *
 * ***********************/
 Node* Node::getLeft()
{
   return left;

}
/************************
 *	Node::getVal
 *returns val
 *
 * **********************/
// int Node::getVal()
//{
//   return val;

//}
/*************************
 *	Node::setVal
 *takes integer to set al
 *
 * ***********************/
//void Node::setVal(int value)
//{
//   val = value;


//}
/*************************
 *	Node::setNext
 *
 *takes pointer to node to set next
 * **********************/
void Node::setRight(Node* pointer)
{
   right = pointer;

}
/************************
 *	Node::setPrev
 *takes pointer to node to set prev
 *
 * *********************/
void Node::setLeft(Node* pointer)
{
   left = pointer;

}
/**********************
 *	Node::setSpace
 *sets the string that will be displayed to 
 *visualize each space
 * *******************/
void Node::setSpace(std::string spaceSettings)
{
   space = spaceSettings;
}
/***************************
 *	Node::getSpace
 *returns the string that has been initialized to the space
 *It helps visualize the spaces.
 **************************/
std::string Node::getSpace()
{
   return space;

}
