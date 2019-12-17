/*********************
 *Program: Home.hpp
 *Date:8/10/19
 *Author: Glenn Frutiz
 *Description: This is the class 
 *declaration for the Home class.
 * *******************/
#include "Node.hpp"
#ifndef HOME_H
#define HOME_H

class Home : public Node
{
   private:
    
   
   public:
      Home(Node* nextNode, Node* prevNode);

      virtual int event();


};
#endif

