/********************************
 *Program: inputVal.hpp
 *Author: Glenn Frutiz
 *Date: 7/14/19
 *Description: These are the function declarations for 
 *integerValidation and only1or2.
 * *******************************/
#include <string>
#ifndef INTEGERVALIDATION_H
#define INTEGERVALIDATION_H


int integerValidation(std::string);//makes sure input is a positive int 
int only1or2(std::string);//makes sure input only 1 or 2
int only12or3(std::string);//makes sure input only 1 2 or 3
std::string stringValidation(std::string user_string);//makes sure input
                                              //has char necessary for a                                               //name

int integerValInRange(int min, int max, std::string user_string_num);  
//makes sure an integer is from a minimum to maximum value
#endif
