/***********************
 *Program: DLL.hpp
 *Author: Glenn Frutiz
 *Date:7/30/19
 *Description: This is the class declaration file
 * for the DLL class. This class creates doubly linked lists.
 * *********************/
#include "Node.hpp"
#ifndef DLL_H
#define DLL_H

class DLL
{
   private:
      Node* current; 
      Node* head;
      Node* tail;
      int numNodes = 0;

   public:
      DLL();
      ~DLL();

      Node* getCurrent();
      bool setCurrent();
      int getValFromNode();

      
      void addN2Tail();
      
     
      void delNAtTail();

      void deleteList();
      void printForward();
     
      void incNumNodes();

      void randomAllocator(Node* &pointer);
      void randomAllocator(Node* &pointer, Node* next, Node* prev);

      
      int dieRoll(int N);

};
#endif
