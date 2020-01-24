#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include "a1datatypes.h"
#include "sorer.h"

void testStringsAreEqual(std::string s1, const char* s2) {
    std::string str2(s2);
    if (s1 != str2) {
        std::cout << "ERROR: " << s1 << " != " << s2 << "\n";
    }
}

void testGetColumn()
{

    // const char * filename = "input.txt";

    // std::string row(getRow(1, "input.txt"));
    // size_t row_size = getMaxFieldRowSize("input.txt");
    // std::vector<assignmentData_t> columnTypes;
    // getColumnTypes(&columnTypes, "input.txt", row_size);

    // std::cout<< getColumn(&row, 5, &columnTypes) << "\n";
    // std::cout<< getColumn(&row, 1, &columnTypes) << "\n";

    testStringsAreEqual(getRowColValue(1, 1, "input.txt"), "string");
    testStringsAreEqual(getRowColValue(1, 5, "input.txt"), "invalid");
}

void testGetRowFieldVector()
{
    std::string testvalue("<abc> <123> <1> <5.64>");
    std::vector<std::string> *result = getRowFieldVector(&testvalue);
    testStringsAreEqual(result->at(0), "abc");
    testStringsAreEqual(result->at(1), "123");
    testStringsAreEqual(result->at(2), "1");
    testStringsAreEqual(result->at(3), "5.64");

    std::string testvalue2 = "<     abc     > <  123       >     <   1 >";
    result = getRowFieldVector(&testvalue2);
    testStringsAreEqual(result->at(0), "abc");
    testStringsAreEqual(result->at(1), "123");
    testStringsAreEqual(result->at(2), "1");
}

// void testGetColumnTypes() {
//     std::string testvalue("<abc> <123> <1> <5.64>");
//     std::vector<std::string> *result = getRowFieldVector(&testvalue);
//     getColumnTypes(&result, "input.txt", );
// }


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
    testIsBoolHelper("  abc  ", false);
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
    testIsIntHelper(" -12 ", false);
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
    testFloatHelper(" -11421a4124.2124124124512 ", false);
};

void testIsStringHelper(const char *input, bool testAgainst) {
    std::string testInput(input);
    if (isString(testInput) != testAgainst) {
        std::cout << "ERROR: " << input << " for isString was " << testAgainst << "\n";
    }
}

void testIsString() {
    testIsStringHelper("abcdef", true);
    testIsStringHelper("\"abcdefed\"", true);
    testIsStringHelper("\"abc def def\"", true);
    testIsStringHelper("\"abc def\" def\"", true);
    testIsStringHelper("abc das", false);
    testIsStringHelper("\"abc def\" def", false);
    testIsStringHelper("\"abc def def", false);
    testIsStringHelper("abc def def\"", false);
}

void runTests() {
    testIsBool();
    testIsInt();
    testIsFloat();
    testIsString();
    testGetRowFieldVector();
    testGetColumn();
}