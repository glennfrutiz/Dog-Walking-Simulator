/*************************
 *Program: Dog.hpp
 *Date: 8/13/19
 *Description: This is the class 
 *declaration file for the Dog class.
 *
 * **********************/
#ifndef DOG_H
#define DOG_H

class Dog
{
   private:
      int LeashStrength;
      int stepsToPoop;
    
      bool treatUsed;
      bool dogHasPooped;
  
   public:
      Dog();
      void setTreatUsed(bool);
      bool getTreatUsed();

      void setDogHasPooped();
      bool getDogHasPooped();
   
      void setLeashStrength(int);
      int getLeashStrength();
      

      void setStepsToPoop();
      int getStepsToPoop();

      int dieRoll(int N);


};
#endif
