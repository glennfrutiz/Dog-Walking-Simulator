/*************************
 *Program: DLL.cpp
 *Date: 7/31/19
 *Author:Glenn Frutiz
 *Description: This is the class 
 *implementation file for DLL
 *the Doubly Linked List
 * ************************/
#include "Node.hpp"
#include "DLL.hpp"
#include "inputVal.hpp"
#include "GoodDog.hpp"
#include "TreatFound.hpp"
#include "Home.hpp"
#include "LeashPull.hpp"
#include <string>
#include <iostream>
/***************************
 *	DLL::DLL
 *This is a default constructor
 *that sets the head and tail 
 *pointers to null
 * ************************/
DLL::DLL()
{
   
   head = nullptr;

   tail = nullptr;

   current = nullptr;

   numNodes = 0;
   

}
/******************************
 *	DLL::~DLL()
 *
 *this destructor calls the delete list function
 *the delete list function deallocates the doubly linked list.
 ******************************/
DLL::~DLL()
{
   deleteList();
  
}
/****************************
 *	DLL::setCurrent
 *
 * *************************/
bool DLL::setCurrent()
{

   bool gameStillRunning;
   std::string choice;
   int choiceInt;
   std::cout<<std::endl;
   std::cout<<"Where would you like to go?\n"
            <<"1. Left\n"
            <<"2. Right\n"
            <<"3. Exit Current Game"<<std::endl;
   std::cin>>choice;
   std::cout<<std::endl;
   choiceInt = integerValInRange(1,3, choice);
   switch(choiceInt)
   {
      case 1:
      {
         gameStillRunning = true;
         
         if(current->getLeft() == nullptr)
         {
            std::cout<<"That Node does not exist. "
                     <<" Make another choice."<<std::endl;
        
            setCurrent();
            
         }
         else
         {
            
            if(current->getIsHome() == true)
            {
               current->setSpace("[home]"); 

            }
            else
            {
               current->setSpace("[ ]"); 
       
            } 
                       
            current = current->getLeft();
            current->setSpace("[dog]");
           

         }
         break;
      }
      case 2:
      {
         gameStillRunning = true;
         
         if(current->getRight() == nullptr)
         {
            std::cout<<"That Node does not exist. "
                     <<" Make another choice."<<std::endl;
            
            setCurrent();
         }
         else
         {
            if(current->getIsHome() == true)
            {
               current->setSpace("[home]"); 

            }
            else
            {
               current->setSpace("[ ]"); 
       
            }
           
            current = current->getRight();
            
         
            current->setSpace("[dog]");
         }
         break;
      case 3:
         gameStillRunning = false;
         break;
      }

   } 
   return gameStillRunning;
}
Node* DLL::getCurrent()
{
   
   return current;

}
/*******************************
 *	DLL::displayCurrentVal
 *returns value from 
 * ****************************/
int DLL::getValFromNode()
{
  
   int eventInt = current->event();   
   return eventInt;
                  
}
/*******************************
 *	DLL::dieRoll
 *generates a random number. adapted from the tutorial on learncpp.com
 *www.learncpp.com/cpp-tutorial/59-random-number-generation/
 * ****************************/
int DLL::dieRoll(int N)
{
   double fraction = 1.0 / (RAND_MAX + 1.0);   
   return 1 + static_cast<int>(N * (std::rand() * fraction));//return an int
                                         // from a range of 1 to N inclusive
}
/********************************
 *	DLL::randomAllocator
 *
 *This version of the over loaded function  takes a node pointer
 *a value, a next pointer and a previous pointer. Dynamically
 * allocates a derived class of Node.
 * *****************************/

void DLL::randomAllocator(Node* &pointer, Node* next, Node* prev)
{
   int randomSpaceInt = dieRoll(10);//makes a random number in range 1-10

   switch(randomSpaceInt)
   {
      case 1:
      case 2:
      case 3:
      case 4://4 out 10 times makes a leash pull space
         {
             
            pointer = new LeashPull(next, prev);
           
         }
         break;
      case 5:
      case 6://4 out of 10 times makes a Good dog space
      case 7:
      case 8:
         pointer = new GoodDog(next, prev);
         break;
      case 9://2 out of 10 times makes a treat found space
      case 10:      
         pointer = new TreatFound(next, prev);
         break;
   }
   

}
/********************************
 *	DLL::randomAllocator
 *
 *This version of the over loaded function only takes a node pointer
 *and a value. Dynamically allocates a derived class of Node.
 * *****************************/
void DLL::randomAllocator(Node* &pointer)
{
   int randomSpaceInt = dieRoll(10);//make a random num in range 1-10

   switch(randomSpaceInt)
   {
      case 1://4 out of 10 times make a LeashPull node
      case 2:
      case 3:
      case 4:
         {
            
            pointer = new LeashPull(nullptr, tail);
           
         }
         break;
      case 5://4 out of 10 times make a GoodDog node
      case 6:
      case 7:
      case 8:
         pointer = new GoodDog(nullptr, tail);
         break;
      case 9://2 out of 10 times make a TreatFound node
      case 10:      
         pointer = new TreatFound(nullptr, tail);
         break;
   }
}      

/**************************
 *	DLL::addN2Tail
 *This functions adds a node to the tail
 *of a doubly linked list
 *this code was modified from code found on the ch17 textbook slides and 
 * code found in this youtube video by Paul Programming
 * https://www.youtube.com/watch?v=YJRRpXYldVQ
 * **********************/
void DLL::addN2Tail()
{
   
   
   
   if(numNodes ==0)//if there are no nodes in the list
   {
     
      Node* n;
      
      n = new Home(nullptr, tail);
      n->setSpace("[home]");

      head =n;//make the member variables point at this lone node
      tail =n;
      n->setIsHome(true); 
      
      incNumNodes();//increase count of nodes
      current = n;
    
   
   }
   else//if there are already nodes
   {
     
      Node* n;
      randomAllocator(n);

      n->setSpace("[ ]");
     
     
      tail->setRight(n);//make the prev node point to new node
      tail = n;//make the new node the tail
      head->setLeft(tail);//turn the doubly linked list into a circular one
      tail->setRight(head);//
      n->setIsHome(false);
          
    
      incNumNodes();
     
       
   }  
   
 
   
}

/***************************
 *	DLL::delNAtTail()
 *this funciton deletes the node located at the tail.
 *
 *
 * This code was adapted from code found on youtube video by Vivekanand 
 * Khyade - Algorithm Every Day https://www.youtube.com/watch?v=LvUgew66zOQ
 * ************************/
 void DLL::delNAtTail()
{  
   if(numNodes==0)//if no nodes in list
   {
      std::cout<<"There are no nodes to delete from tail."<<std::endl;
   }
   else if(numNodes==1)//if only one node is in list
   {
      Node* p = head;//set pointer to head, unlink pointer, and deallocate
      head = nullptr;
      tail = nullptr;
      delete p;
      numNodes--;//decrease count of nodes
   }
   else
   {
      Node* p = head;//set pointer to head
      while(p->getRight() != nullptr)//traverse list until we reach tail
      {
         p = p->getRight();
      }
      Node* storePrev = p->getLeft();//store node before tail
      storePrev->setRight(nullptr);//make the previous node the new tail
     
      delete p;  //deallocate node that was at tail
      numNodes--; 
   }

}

/****************************
 *	DLL::deleteList
 *
 *this code is a combination of the directions found on the ch17 slides
 *for the test book and the link found below. This function deallocates
 *the doubly linked list
 *
 *
 *https://www.geeksforgeeks.org/write-a-function-to-delete-a-linked-list/
 * ****************************/
void DLL::deleteList()
{
   int numNode = 0;
   Node* curr = head;//set a pointer to head
   Node* next = nullptr;
   tail->setRight(nullptr);//?
   while(curr!=nullptr)//traverse list starting at head
   {
      numNode++;
      next = curr->getRight();//set a pointer to the next node
      curr->setRight(nullptr);//unlink current node
      curr->setLeft(nullptr);
      delete curr;//delete current node
      curr = next;//prepare for next iteration
     
   }
   head = nullptr;//set head and tail member variables to nullptr
   tail = nullptr;
   curr = nullptr;
   current = nullptr;
   next = nullptr;
   int numNodes = 0;
 
}

/***********************************
 *	DLL::incNumNodes()
 *this function increases the value of
 *numNodes after a new node is added to list
 * ********************************/
void DLL::incNumNodes()
{
   numNodes++;





}
/************************************
 *	DLL::printForward
 *
 *This code is a combination of directions found on the ch 17 slides for 
 * the textbook and a youtube video by Paul Programming.
 * https://www.youtube.com/watch?v=5s0x8bc9DvQ
 *
 *it iterates through the doubly linked list starting at the head
 * and it displays the values found there
 * **********************************/
void DLL::printForward()
{
   
   Node* tPtr = head;
   if(tPtr == nullptr)//if head points to nothing
   {
      std::cout<<"This list is empty."<<std::endl;
   }
   else
   {
      tail->setRight(nullptr);//undo the circular doubly linked list
      
      while(tPtr!=nullptr)//traverse list starting at head and display next 
      {                   //node.
        std::cout<<tPtr->getSpace();
	
         tPtr = tPtr->getRight();
        
      }
      std::cout<<std::endl;
      tail->setRight(head);//reconnect the circular doubly linked list
   }



}



