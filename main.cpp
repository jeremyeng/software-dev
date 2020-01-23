#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>


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
}

/**
 * @brief determine the data type of this row
 * @note if any value in the row is a string, then the row is a string
 * @note else if any value is a float then the row is a float
 * @note else if any value is an int then the row is an int
 * @note else the row is bool
 */ 
void determineDataType(std::string row)
{

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
    readFile("input.txt");
}