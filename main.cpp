#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "a1datatypes.h"
#include "sorer.h"
#include "test.h"

void printColumnTypes(std::vector<assignmentData_t> *column_types)
{
    for (size_t i = 0; i < column_types->size(); i++)
    {
        std::cout << column_types->at(i) << " ";
    }
    std::cout << "\n";
}
int main(int argc, char **argv)
{
    char * targetFileName = nullptr;

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
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-f") == 0)
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
            i += 2;
        }
        else if (strcmp(argv[i], "-is_missing_idx") == 0)
        {
            is_missing_idx = true;
            missing_idx_a = atoi(argv[i + 1]);
            missing_idx_b = atoi(argv[i + 2]);
            i += 2;
        }
        else
        {
            std::cout << "bad argument ignored: " << argv[i] << "\n";
        }
    }

    if(targetFileName == nullptr)
    {
        std::cout<<"error - no file name given\n";
        return 1;
    }

    size_t row_size = getMaxFieldRowSize(targetFileName);

    if(row_size == 0)
    {
        std::cout<<"Bad file. Exiting.\n";
        return 1;
    }

    std::vector<assignmentData_t> column_types;
    getColumnTypes(&column_types, targetFileName, row_size);
    std::cout << "Column Types: ";
    printColumnTypes(&column_types);

    if (print_col_type)
    {
        assignmentData_t d_type = getColumnType(col_type_value, targetFileName);
        switch (d_type)
        {
        case assignmentData_t::INT:
            std::cout << "INT\n";
            break;
        case assignmentData_t::STRING:
            std::cout << "STRING\n";
            break;
        case assignmentData_t::BOOL:
            std::cout << "BOOL\n";
            break;
        case assignmentData_t::FLOAT:
            std::cout << "FLOAT\n";
            break;
        default:
            break;
        }
    }

    if(print_col_idx)
    {
        std::string result = getRowColValue(col_idx_a, col_idx_b, targetFileName);
        if(isString(result))
        {
            std::cout<<"\""<<result<<"\"\n";
        }
        else
        {
            std::cout<<result<<'\n';
        }
    }

    if(is_missing_idx)
    {
        if(isInvalid(missing_idx_a, missing_idx_b, targetFileName))
        {
            std::cout<<"1\n";
        }
        else 
        {
            std::cout<<"0\n";
        }
    }

    testIsBool();
    testIsInt();
    testIsFloat();
    testIsString();
    testGetRowFieldVector();

    testGetColumn();
}