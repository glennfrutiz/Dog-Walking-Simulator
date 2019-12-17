/*********************
 *Program: GoodDog.hpp
 *Date:8/7/19
 *Author: Glenn Frutiz
 *Description: This is the class 
 *declaration for the GoodDog class.
 * *******************/
#include "Node.hpp"
#ifndef GOODDOG_H
#define GOODDOG_H

class GoodDog : public Node
{
   private:
    
   public:
      GoodDog(Node* nextNode, Node* prevNode);

      virtual int event();


};
#endif
