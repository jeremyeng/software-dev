#ifndef A1DATATYPES_H
#define A1DATATYPES_H

#include <string>
#include <iostream>
//this file defines functions to check if data of of the data types
//as defined in assignment one

/**
 * @brief determine if the given data is of string type
 * @note data will be given as it is in the file but without the <> separators
 */ 
int isString(std::string data)
{
    //TODO
}

/**
 * @brief determine if the given data is of float type
 * @note data will be given as it is in the file but without the <> separators
 */ 
int isFloat(std::string data)
{
    //TODO
}

/**
 * @brief determine if the given data is of int type
 * @note data will be given as it is in the file but without the <> separators
 * @warning a bool is technically an int, so always check to confirm it is not a bool
 */ 
int isInt(std::string data)
{
    //if all characters are digits, it is an int
    for(int i = 0; i < data.length(); i++)
    {
        if(data[i] > 57 || data[i] < 48)
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief determine if the given data is of bool type
 * @note data will be given as it is in the file but without the <> separators
 * and without any whitespace that may have followed < or preceeded >
 */ 
int isBool(std::string data)
{
    // a value is bool if it is either 0 or 1
    if(data.length() != 1)
    {
        return false;
    }
    else 
    {
        return data[0] == '1' || data[0] == '0';
    }

}

void testIsBool()
{
    std::string testString("1");
    if(!isBool(testString))
    {
        std::cout<<"failed 1\n";
    }

    testString = "2";
    if(isBool(testString))
    {
        std::cout<<"failed 2\n";
    }

    testString = "";
    if(isBool(testString))
    {
        std::cout<<"failed 3\n";
    }

    testString = "0";
    if(!isBool(testString))
    {
        std::cout<<"failed 4\n";
    }
}

void testIsInt()
{
    std::string testString("1");
    if(!isInt(testString))
    {
        std::cout<<"failed 1\n";
    }

    testString = "2";
    if(!isInt(testString))
    {
        std::cout<<"failed 2\n";
    }

    testString = "";
    if(isInt(testString))
    {
        std::cout<<"failed 3\n";
    }

    testString = "0";
    if(!isInt(testString))
    {
        std::cout<<"failed 4\n";
    }

    testString = "1234";
    if(!isInt(testString))
    {
        std::cout<<"failed 5\n";
    }

    testString = "12.34";
    if(isInt(testString))
    {
        std::cout<<"failed 6\n";
    }

    testString = "12345a";
    if(isInt(testString))
    {
        std::cout<<"failed 6\n";
    }
}
#endif