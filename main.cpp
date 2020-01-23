#include <iostream>
#include <cstdio>
#include <string>
#include <fstream>
#include <cstring>
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
    char * targetFileName;

    bool from = false;
    bool len = false;
    bool print_col_type = false;
    bool print_col_idx = false;
    bool is_missing_idx = false;

    size_t from_value = 0;
    size_t len_value = 0;
    size_t col_type_value = 0;
    size_t col_idx_a = 0;
    size_t col_idx_b = 0;
    size_t missing_idx_a = 0;
    size_t missing_idx_b = 0;


    //ignore the first arg, which is the name of the program
    for(int i = 1; i < argc; i++)
    {
        if(strcmp(argv[i], "-f") == 0)
        {
            targetFileName = argv[i + 1];
            //iterate so we don't bother to check the arg value
            i++;
        }
        else if (strcmp(argv[i], "-from") == 0)
        {
            from = true;
            from_value = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-len") == 0)
        {
            len = true;
            len_value = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-print_col_type") == 0)
        {
            print_col_type = true;
            col_type_value = atoi(argv[i + 1]);
            i++;
        }
        else if (strcmp(argv[i], "-print_col_idx") == 0)
        {
            print_col_idx = true;
            col_idx_a = atoi(argv[i + 1]);
            col_idx_b = atoi(argv[i + 2]);
            i+=2;
        }
        else if (strcmp(argv[i], "-is_missing_idx") == 0)
        {
            is_missing_idx = true;
            missing_idx_a = atoi(argv[i + 1]);
            missing_idx_b = atoi(argv[i + 2]);
            i+=2;
        }
    }
    //readFile("input.txt");
    testIsBool();
    testIsInt();
}