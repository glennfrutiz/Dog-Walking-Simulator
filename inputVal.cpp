/***************************************
 *Program: inputVal.cpp
 *Author: Glenn Frutiz
 *Date: 7/14/19
 *Description: This are the function definitions for integerValidation 
 * and string Validation
 *
 * ***********************************/
#include "inputVal.hpp"
#include <iostream>
#include <limits>
#include <ctype.h>  // isdigit()
#include <sstream>  // stringstream
//modified this program from
//https://jesushilarioh.com/how-to-validate-an-integer-in-c-plus-plus/
//using namespace std;
//I  want to use this for all of my future assignments.
//I want to ask the user for an integer. Then I will pass the input here.
//If the input is invalid then I will keep asking.
//It depends on me taking in the users input as a string.
/************************************************
 * integerValidation
 *
 *This function checks to make sure a user inputs a postive integer
 * ********************************************/
int integerValidation(std::string user_string_num)  
{
    //string user_string_num = "";

    unsigned int is_num = 0;//initialize necessary variables
    int decimal_count = 0,
        user_converted_num,
        iteration = 0,
        negative_count =0;
    bool is_num_bool = 0;

    do
    {
    	if(iteration !=0)//if the user has give an invalid number before
	{
           std::cout << "Enter a number: ";//ask user for input 
           std::cin >> user_string_num;//store in string
	}

        

        if (user_string_num[0] == '0' &&//if the string begins with a zero 
            isdigit(user_string_num[1]))//and is followed by a number
            is_num = 0;
        else if(user_string_num[0] == '0' && user_string_num.size() == 1)
            is_num = 0;//if the string begins with 0 and contains other num
        else //if the string does not set off the previous statements
        {
            for (unsigned int i = 0; i < user_string_num.size(); i++)
            {
                if (isdigit(user_string_num[i]))
                    is_num++;//count the amount of numbers
                if (user_string_num[i] == '.')
                    decimal_count++;//count the amount of decimals
		if (user_string_num[i] == '-')
		    negative_count++;//count the amount of negative sigs
            }
        }

        if (decimal_count == 1|| negative_count == 1)
            is_num = 0;//if there are decimals or negative signs 
                       //set is_num to zero
        if (is_num == user_string_num.size())//if the amount of numbers 
        {                                    //is equal to the size of string
            std::stringstream str_stream_object(user_string_num);
            str_stream_object >> user_converted_num;//convert string to int

            is_num_bool = 1;//set this variable to 1 to break out of loop
        }
        else//if the amount of numbers is not equal to string size
        {
           std::cout << std::endl//display the following messages
                 << "Number must be a positive integer.\n"
                // << "Number must NOT contain letters.\n"
                // << "Number must NOT contain symbols.\n"
                // << "Number must NOT be a decimal number.\n"
		// << "Number must NOT be a negative number.\n"
                // << "Number must NOT be zero.\n" 
                 << std::endl;

            std::cin.clear();//remove any flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');//clear stream of all unwanted inputs

            is_num_bool     = 0;//reset variables before we iterate again
            is_num          = 0;
            decimal_count   = 0;
	    negative_count  = 0;
            iteration++;//count how many times we have gone through loop	
        }


    } while (is_num_bool == 0);
    

    return user_converted_num;
}
/**********************************
 *	only1or2
 *This is a modified version of the function above
 *modifications will be commented to highlight them.
 * ******************************/
int only1or2(std::string user_string_num)  
{
    

    unsigned int is_num = 0;
    int decimal_count = 0,
        user_converted_num,
        iteration = 0,
        negative_count =0;
    bool is_num_bool = 0;

    do
    {
    	if(iteration !=0)
	{
           std::cout << "Enter a number: ";
           std::cin >> user_string_num;
	}



        if (user_string_num[0] == '0' && isdigit(user_string_num[1]))
        {    
	    is_num = 0;
        }
        else if((user_string_num[0] == '1' || user_string_num[0] == '2') && isdigit(user_string_num[1]))//mod: if there are numbers past 1 or 2
        {
            is_num = 0;
        }
        else if((user_string_num[0] != '1' && user_string_num[0] != '2'))
        { 
            is_num = 0;//mod: if the first number is not a 1 or 2
        }
	else
        {
            for (unsigned int i = 0; i < user_string_num.size(); i++)
            {
                if (isdigit(user_string_num[i]))
                    is_num++;
                if (user_string_num[i] == '.')
                    decimal_count++;
		if (user_string_num[i] == '-')
		    negative_count++;
            }
        }

        if (decimal_count == 1|| negative_count == 1)
            is_num = 0;
        
        if (is_num == user_string_num.size()) 
        {
            std::stringstream str_stream_object(user_string_num);
            str_stream_object >> user_converted_num;

            is_num_bool = 1;
        }
        else
        {
           std::cout << std::endl//mod: tell user to not input 1 or 2
                // << "Number must NOT contain spaces.\n"
                // << "Number must NOT contain letters.\n"
                // << "Number must NOT contain symbols.\n"
                // << "Number must NOT be a decimal number.\n"
		// << "Number must NOT be a negative number.\n"
                 << "Number must be either 1 or 2.\n"
                 << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            is_num_bool     = 0;
            is_num          = 0;
            decimal_count   = 0;
	    negative_count  = 0;
            iteration++;	
        }


    } while (is_num_bool == 0);
    

    return user_converted_num;
}
/**********************************
 *	only12or3
 *This is a modified version of the function above
 *modifications will be commented to highlight them.
 * ******************************/
int only12or3(std::string user_string_num)  
{
    

    unsigned int is_num = 0;
    int decimal_count = 0,
        user_converted_num,
        iteration = 0,
        negative_count =0;
    bool is_num_bool = 0;

    do
    {
    	if(iteration !=0)
	{
           std::cout << "Enter a number: ";
           std::cin >> user_string_num;
	}



        if (user_string_num[0] == '0' && isdigit(user_string_num[1]))
        {    
	    is_num = 0;
        }
        else if((user_string_num[0] == '1' || user_string_num[0] == '2' || user_string_num[0] == '3') && isdigit(user_string_num[1]))//mod: if there 
                                                                                                                        //are numbers past 1,2, or 3
        {
            is_num = 0;
        }
        else if((user_string_num[0] != '1' && user_string_num[0] != '2' && user_string_num[0]!= '3'))
        { 
            is_num = 0;//mod: if the first number is not a 1,2,or3
        }
	else
        {
            for (unsigned int i = 0; i < user_string_num.size(); i++)
            {
                if (isdigit(user_string_num[i]))
                    is_num++;
                if (user_string_num[i] == '.')
                    decimal_count++;
		if (user_string_num[i] == '-')
		    negative_count++;
            }
        }

        if (decimal_count == 1|| negative_count == 1)
            is_num = 0;
        
        if (is_num == user_string_num.size()) 
        {
            std::stringstream str_stream_object(user_string_num);
            str_stream_object >> user_converted_num;

            is_num_bool = 1;
        }
        else
        {
           std::cout << std::endl//mod: tell user to input either 1,2,or3
                // << "Number must NOT contain spaces.\n"
                // << "Number must NOT contain letters.\n"
                // << "Number must NOT contain symbols.\n"
                // << "Number must NOT be a decimal number.\n"
		// << "Number must NOT be a negative number.\n"
                 << "Number must be either 1,2, or 3.\n"
                 << std::endl;

            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            is_num_bool     = 0;
            is_num          = 0;
            decimal_count   = 0;
	    negative_count  = 0;
            iteration++;	
        }


    } while (is_num_bool == 0);
    

    return user_converted_num;
}



/************************************************
 * stringValidation
 *
 *This function checks to make sure a user inputs a valid string.
 * ********************************************/
std::string stringValidation(std::string user_string)  
{
    //string user_string_num = "";

    unsigned int is_word = 0;//initialize necessary variables
    int num_count=0,
        iteration = 0;
    bool is_word_bool = 0;

    do
    {
    	if(iteration !=0)//if the user has give an invalid number before
	{
           std::cout << "Enter a input again: ";//ask user for input 
           std::cin >> user_string;//store in string
	}

        

        if(isalpha(user_string[0]) && user_string.size() == 1)
            is_word = 0;//if the string only has one character
        else if(isalpha(user_string[0]) == false)
            is_word = 0;
        else //if the string does not set off the previous statements
        {
            for (unsigned int i = 0; i < user_string.size(); i++)
            {
               
                if (isalpha(user_string[i]))
                    is_word++;//count the amount of letters
                if (isdigit(user_string[i]))
                    num_count++;//count the amount of numbers
                if (user_string[i] == '\'')
                    is_word++;//count the apostrophes
                if (user_string[i] == ' ')
                    is_word++;//count the spaces
                if (user_string[i] == '.')
                    is_word++;//count the amount periods
		if (user_string[i] == '-')
		    is_word++;//count the hyphens
            }
        }

        if (num_count>=1)
            is_word = 0;//if there are numbers 
                       //set is_word to zero to ask for input again

        if (is_word == user_string.size())//if the amount of desired 
                                          //characters is equal to 
        {                                 //the size of string


            is_word_bool = 1;//set this variable to 1 to get out of loop
        }
        else//if amount of characters is not equal to string size
        {
           std::cout << std::endl//display the following messages
                 << "First character must be a letter.\n"
                 << "Input must NOT contain digits.\n"
                 << "Input must NOT contain symbols.\n"
                 << std::endl;

            std::cin.clear();//remove any flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                            ,'\n');//clear stream of all unwanted inputs

            is_word_bool    = 0;//reset variables before we iterate again
            num_count       = 0;
            iteration++;//count how many times we have gone through loop	     user_string     = "";
        }


    } while (is_word_bool == 0);
    

    return user_string;
}

/************************************************
 * integerValInRange
 *
 *This function checks to make sure a user inputs a positive 
 *integer that is within a range.
 * ********************************************/
int integerValInRange(int min, int max, std::string user_string_num)  
{
    //string user_string_num = "";

    unsigned int is_num = 0;//initialize necessary variables
    int decimal_count = 0,
        user_converted_num,
        iteration = 0,
        negative_count =0;
    bool is_num_bool = 0;

    do
    {
    	if(iteration !=0)//if the user has give an invalid number before
	{
           
          
           std::cin >> user_string_num;//store in string
	}

        

        if (user_string_num[0] == '0' &&//if the string begins with a zero 
            isdigit(user_string_num[1]))//and is followed by a number
            is_num = 0;
        else if(user_string_num[0] == '0' && user_string_num.size() == 1)
            is_num = 0;//if the string is just zero
        else //if the string does not set off the previous statements
        {
            for (unsigned int i = 0; i < user_string_num.size(); i++)
            {
                if (isdigit(user_string_num[i]))
                    is_num++;//count the amount of numbers
                if (user_string_num[i] == '.')
                    decimal_count++;//count the amount of decimals
		if (user_string_num[i] == '-')
		    negative_count++;//count the amount of negative sigs
            }
        }

        if (decimal_count == 1|| negative_count == 1)
            is_num = 0;//if there are decimals or negative signs 
                       //set is_num to zero
                       
        if (is_num == user_string_num.size())//if the amount of numbers 
        {                                    //is equal to the size of string
            std::stringstream str_stream_object(user_string_num);

            str_stream_object >> user_converted_num;//convert string
            
            if((user_converted_num < min) || (user_converted_num > max))
            {//if input is less than the min or greater than max
           
               std::cout << std::endl//display the following messages
                         << "Number must be integer in range "
                         <<min<<" to "<<max<<"."<< std::endl;;

               std::cin.clear();//remove any flags
               std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                               ,'\n');//clear stream of all unwanted inputs

               is_num_bool     = 0;//reset variables before we iterate again
               is_num          = 0;
               decimal_count   = 0;
	       negative_count  = 0;
               iteration++;//count how many times we have gone through loop	
             }      
             else
             {
                is_num_bool = 1;//set this variable to 1 to break out of loop
             }
            
        } 
                                           
        else
        {
            
           std::cout << std::endl//display the following messages
                     << "Number must be integer in range "
                     <<min<<" to "<<max<<"."<< std::endl;;

            std::cin.clear();//remove any flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                            
                            ,'\n');//clear stream of all unwanted inputs

            is_num_bool     = 0;//reset variables before we iterate again
            is_num          = 0;
            decimal_count   = 0;
	    negative_count  = 0;
            iteration++;//count how many times we have gone through loop	
        }
        

    } while (is_num_bool == 0);
    

    return user_converted_num;
}

