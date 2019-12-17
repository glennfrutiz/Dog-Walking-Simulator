/*********************
 *Program: LeashPull.hpp
 *Date:8/10/19
 *Author: Glenn Frutiz
 *Description: This is the class 
 *declaration for the LeashPull class.
 * *******************/
#include "Node.hpp"
#ifndef LEASHPULL_H
#define LEASHPULL_H

class LeashPull : public Node
{
   private:
 
    
   
   public:
      LeashPull(Node* nextNode, Node* prevNode);

      virtual int event();

     //~LeashPull();

};
#endif


