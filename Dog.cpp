/************************
 *Program: Dog.cpp
 *Date: 8/13/19
 *Author: Glenn Frutiz
 *Description: THis is the 
 *class definition file for the dog class
 * **********************/
#include "Dog.hpp"
#include <cstdlib>
#include <iostream>
/**********************
 *	Dog::Dog
 *This constructor initializes the member variables of the Dog class.
 *
 * *******************/
Dog::Dog()
{
       LeashStrength = 20;
       stepsToPoop = dieRoll(10);//sets value to N in range 6 to 10 
      
       treatUsed = false;
       dogHasPooped = false;


}
/***********************
 *	Dog::setTreatUsed
 *takes a bool by value and returns value
 *
 * ********************/
void Dog::setTreatUsed(bool tOrF)
{
    treatUsed = tOrF;

}
/***************************
 *	Dog::getTreatUsed
 *returns the value of treatUsed
 *
 *
 * ************************/
bool Dog::getTreatUsed()
{
    return treatUsed;

}
/***************************
 *	Dog::setDogHasPooped
 *sets the value of dog has pooped and displays a message if the value
 * has been set for the first time.
 *
 * *************************/
void Dog::setDogHasPooped()
{
   if(stepsToPoop <=  0 && dogHasPooped)
   {
      dogHasPooped = true;
   }
   else if(stepsToPoop<=0 && !dogHasPooped)//ensures message is only
                                           //displayed once
   {
      std::cout<<"Your dog has pooped!"<<std::endl;
      dogHasPooped = true;
   }   
}
/***************************
 *	Dog::getDogHasPooped
 *
 *returns the vale of dogHasPooped
 * ************************/
bool Dog::getDogHasPooped()
{
   return dogHasPooped;
}
/*************************
 *	Dog::setLeashStrength
 *takes an integer by value and 
 *uses it to decrease the value of 
 *LeashStrength 
 * *********************/
void Dog::setLeashStrength(int damage)
{
   LeashStrength -=damage;
   if(LeashStrength<=0)//if LeashStrength is less than or equal to 0 
                       //keep its value at zero
   {

      LeashStrength = 0;
   }

}
/************************
 *	Dog::getLeashStrength
 *retusn the value of LeashStrength
 *
 * *********************/
int Dog::getLeashStrength()
{
   return LeashStrength;
}
/************************
 *	Dog::setStepsToPoop
 *when called it decreases the value of 
 *setStepsToPoop
 * ********************/
void Dog::setStepsToPoop()
{
   stepsToPoop--;
   if(stepsToPoop <=0)//keep the value of setSteps to poop at 0
   {
      stepsToPoop =0;
   }
}
/****************************
 *	Dog::getStepsToPoop
 *returns value of stepsToPoop
 *
 * ************************/
int Dog::getStepsToPoop()
{
   return stepsToPoop;
}
/***********************
 *	Dog::dieRoll
 *Returns a random number in the range
 *6-10
 * ********************/
int Dog::dieRoll(int N)
{
   double fraction = 1.0 / (RAND_MAX + 1.0);   
   return 6 + static_cast<int>((N-6+1) * (std::rand() * fraction));//return an int
                                         // from a range of 5 to N inclusive
}

