/******************************
 *Program: Menu.cpp
 *Author: Glenn Frutiz
 *Date: 7/28/19
 *Description: This file contains the function
 * definitions for the Menu class. 
 * ***************************/
#include "Menu.hpp"
#include "Dog.hpp"
#include "DLL.hpp"
#include <iostream>
#include "inputVal.hpp"
#include <string>
/***************************
 *	Menu::startGame()
 *This program displays a menu asking the user if they would like to start 
 *the game. If the user chooses yes then it displays the directions and 
 *calls the necessary function to run the game.
 *
 * *************************/
void Menu::startGame()
{
    std::cout<<std::endl; 
    std::cout<<"Welcome to That Dang Dog!"<<std::endl; 
    std::string input = "";
    std::cout<<"Choose an option from the menu.\n"
             <<"1. Start Game\n"
             
             <<"2. Quit the program. "<<std::endl;
    std::cin>>input;             
    int event = integerValInRange(1, 2, input);//validate user choice  
    switch(event)
    {
       case 1:
          std::cout<<"Your dog is scratching at the door.\n"
                   <<"Looks like he wants to go for a walk!\n"
                   <<"Walk your dog by moving from space to "
                   <<"space until he poops.\n"
                   <<"You can't come back home until he finishes the job.\n"
                   <<"If your dog sees a squirrel he may pull "
                   <<"on the leash and damage it!\n"
                   <<"If you pick up treats you will stop him "
                   <<"from pulling on the leash.\n"
                   <<"Get your dog to poop and come "
                   <<"back home before the leash breaks."<<std::endl; 
          std::cout<<std::endl; 
          runGame(); 
          startGame();//after the game ends ask user if they would like to
                      // play again
          break;
       case 2:
          std::cout<<std::endl;
          std::cout<<"You have chosen to exit the game.\n"
                   <<"Thank You For Playing!"<<std::endl;
          break;//do nothing if the user chooses to quit
         

    }
      

 }
/*******************************
 *	Menu::runGame
 *
 *This function coordinates the events to run the game and to 
 *make sure the player interacts with all the spaces.
 * ****************************/
void Menu::runGame()
{
   doubly = new DLL;//allocate circular linked list
   chihuahua = new Dog;//allocate instance of dog
   bool gameRunning = true;
   for(int i =0; i<10; i++)
   {
      doubly->addN2Tail();//make a list with 10 spaces
                          //each space is a random instance of a derived 
                          //class.
   }
   doubly->printForward();//display the board
   while(gameRunning == true)//while the game is running
   {
      chihuahua->setStepsToPoop();  
      chihuahua->setDogHasPooped(); //decrease steps needed for dog to poop
                                    //and check to see if dog has poopled
     
      gameRunning = doubly->setCurrent();
      if(gameRunning==true)
      {    
         coordinateSpaces();//see what kind of event will occur due to space
         if(chihuahua->getDogHasPooped() && isHome)
         //end game if dog has pooped and you are home
         {
            std::cout<<std::endl;
            std::cout<<"You have walked the dog successfully!.\n"
                     <<"I guess he's a good boy after all.\n"
                     <<std::endl;
            std::cout<<"Final Score for Leash Strength: "
                     <<chihuahua->getLeashStrength()
                     <<std::endl;

            gameRunning = false;
         } 
         else if(isHome && !(chihuahua->getDogHasPooped()))
         //don't end game if you are home and dog hasn't pooped
         {
            std::cout<<std::endl;
            std::cout<<"You can't go home if the dog hasn't pooped."
                     <<std::endl;  
            std::cout<<std::endl; 
            doubly->printForward();

            std::cout<<"Leash Strength: "
                     <<chihuahua->getLeashStrength()
                     <<std::endl;
         }
         else
         //display leash strength after events if not home 
         {
            std::cout<<std::endl;
            doubly->printForward();
            std::cout<<"Leash Strength: "
                     <<chihuahua->getLeashStrength()
                     <<std::endl;

         }

         if(chihuahua->getLeashStrength() <=0)//end game if leash<=0
         {
            std::cout<<std::endl;
            std::cout<<"Your leash broke!\n"
                     <<"That dang dog!\n"
                     <<"Game Over\n"
                     <<std::endl;   
            gameRunning = false;
         }
       }   
       isHome = false;  
      
   }
   while(!tp.empty())//empty queue in case player decides to play again
   {
      tp.pop();
   } 
   delete doubly;//deallocate pointers to member variables
   delete chihuahua;

}
/*****************************
 *	Menu::coordinateSpaces
 *This function causes events to happen in the game each time 
 *a player lands on a certain type of space
 ****************************/
void Menu::coordinateSpaces()
{
      

   int space = doubly->getValFromNode();
   switch(space)//try and implement this in dog or in menu
   {
      case 1:
      {
        isHome = true;//track that the player is home
        //if dog has pooped
        //set game running to false
        //if dog has not pooped 
        //tell player they can't return home until dog has pooped 
      }  
         break;
      case 2:
      {
         isHome = false;//dog was good this turn so do nothing and just note
                        //the player isnt home
      }
    
         break;
  
      case 3:
         { //the dog pulls on the leash
            isHome = false;
            bool treat;
            std::string choice;//ask the user if they want to use a treat
            std::cout<<std::endl;
            std::cout<<"Do you want to use a treat?\n"
                     <<"1. Yes\n"
                     <<"2. No"<<std::endl;
            std::cin>>choice;
            int choiceInt = integerValInRange(1,2, choice);
            switch(choiceInt)
            {
               case 1:
               
                  if(!tp.empty())//if there are no treats allow leash to
                  {              //be damaged
                     chihuahua->setTreatUsed(tp.front());
                     tp.pop();
                     std::cout<<"You used a treat."<<std::endl;
                  }
                  else
                  {
                     std::cout<<"You have no treats."<<std::endl;
                  }            
                  break;
               case 2: //if the user chooses not to use treats then display
                  std::cout<<"You chose to not use a treat."<<std::endl;
                  break;
            }


            if(chihuahua->getTreatUsed())
            {
               std::cout<<"Your dog did not pull on the leash."<<std::endl; 
            }
            else//decrease leash strength if treat is not used
            {
               chihuahua->setLeashStrength(5);
               std::cout<<"The leash strength was decreased."<<std::endl;

            }
         }
         chihuahua->setTreatUsed(false);//undo this setting till next time
         break;
      case 4:
      {
        isHome =false;
       
        if(tp.size() !=2)//add treat unless the treat pocket queue 
                         //has a capacity of 2.
        {
           bool treat = true;
           tp.push(treat);
        }
        else
        {
           std::cout<<"Your treat pocket is full."<<std::endl;
        }
       }
        break;
    

   }  
}


