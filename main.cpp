#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include "a1datatypes.h"

size_t row_size;



void readFile(const char *filename)
{
    std::ifstream myFile;
    std::string fileInput;
    myFile.open(filename);

    while (myFile)
    {
        std::getline(myFile, fileInput);
        std::cout<<fileInput<<"\n";
    }

    myFile.close();
}


/**
 * @brief get the value of the given row at the given column
 * @param row the string representing the data at that row
 * @param column the column to target
*/
void getColumn(std::string row, size_t column)
{

}

int main(int argc, char **argv)
{
    //readFile("input.txt");
    testIsBool();
    testIsInt();
}