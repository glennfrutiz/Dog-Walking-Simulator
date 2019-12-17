/**************************
 *Program: Node.hpp
 *Author:Glenn Frutiz
 *Date: 7/30/19
 *Description: This is the class declaration file for 
 *the Node class.
 * ***********************/
#include <string>
#ifndef	NODE_H
#define NODE_H

class Node 
{
   protected:
      
      bool isHome;
      
      Node* right;
      Node* left;
      Node* up;
      Node* down;
      std::string space;
   public:
      Node(){}
      Node( Node* nextNode, Node* prevNode) : right(nextNode), 
                                              left(prevNode){}
      Node* getRight();
      Node* getLeft();
      //int getVal();
      //void setVal(int value);
      void setRight(Node* pointer);
      void setLeft(Node* pointer);
      virtual int event() = 0;
      void setSpace(std::string);
      std::string getSpace();
     
      void setIsHome(bool);
      bool getIsHome();


};
#endif
