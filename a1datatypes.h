#ifndef A1DATATYPES_H
#define A1DATATYPES_H

#include <string>
#include <iostream>
//this file defines functions to check if data of of the data types
//as defined in assignment one

typedef enum {
    STRING, 
    BOOL,
    FLOAT,
    INT
} assignmentData_t;

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
    if (data.length() == 0) {
        return false;
    }

    int count = 0;

    if (data[count] == 43 || data[count] == 45) {
        count++;
    }

    bool decimalSeen = false;
    if (data[count] == 46) {
        count++;
        decimalSeen = true;
    }

    //if all characters are digits, it is an int
    for(int i = count; i < data.length(); i++)
    {
        if (data[i] == 46) {
            if (decimalSeen) {
                return false;
            }

            decimalSeen = true;
            i++;

            if (i >= data.length()) {
                return false;
            }
        } 

        if(data[i] > 57 || data[i] < 48)
        {
            return false;
        }
    }

    return true;
}

/**
 * @brief determine if the given data is of int type
 * @note data will be given as it is in the file but without the <> separators
 * @warning a bool is technically an int, so always check to confirm it is not a bool
 */ 
int isInt(std::string data)
{
    if (data.length() == 0) {
        return false;
    }

    int count = 0;

    if (data[count] == 43 || data[count] == 45) {
        count++;
    }

    //if all characters are digits, it is an int
    for(int i = count; i < data.length(); i++)
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

void testIsBoolHelper(const char* input, bool testAgainst) {
     std::string testString(input);
    if(isBool(testString) != testAgainst)
    {
        std::cout << "ERROR: " << input << " for isBool was " << testAgainst << "\n";
    }
}

void testIsBool()
{
    testIsBoolHelper("1", true);
    testIsBoolHelper("0", true);
    testIsBoolHelper("", false);
    testIsBoolHelper("2", false);
    testIsBoolHelper("a", false);
    testIsBoolHelper("abc", false);
}

void testIsIntHelper(const char* input, bool testAgainst) {
    std::string testString(input);
    if(isInt(testString) != testAgainst)
    {
        std::cout << "ERROR: " << input << " for isInt was " << testAgainst << "\n";
    }
}

void testIsInt()
{
    testIsIntHelper("0", true);
    testIsIntHelper("1", true);
    testIsIntHelper("2", true);
    testIsIntHelper("1234", true);
    testIsIntHelper("+12", true);
    testIsIntHelper("-12", true);
    testIsIntHelper("", false);
    testIsIntHelper("12.34", false);
    testIsIntHelper("12345a", false);
    testIsIntHelper("- 12", false);
} 

void testFloatHelper(const char *input, bool testAgainst) {
    std::string testInput(input);
    if (isFloat(testInput) != testAgainst) {
        std::cout << "ERROR: " << input << " for isFloat was " << testAgainst << "\n";
    }
}

void testIsFloat() {
    testFloatHelper("1.0", true);
    testFloatHelper("+1.0", true);
    testFloatHelper("-1.0", true);
    testFloatHelper("-114214124.2124124124512", true);
    testFloatHelper("-1 .0", false);
    testFloatHelper("-1.", false);
    testFloatHelper("-11421a4124.2124124124512", false);
};
#endif