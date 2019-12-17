/*********************
 *Program: TreatFound.hpp
 *Date:8/10/19
 *Author: Glenn Frutiz
 *Description: This is the class 
 *declaration for the TreatFound class.
 * *******************/
#include "Node.hpp"
#ifndef TREATFOUND_H
#define TREATFOUND_H

class TreatFound : public Node
{
   private:
    
   
   public:
      TreatFound(Node* nextNode, Node* prevNode);

      virtual int event();


};
#endif
