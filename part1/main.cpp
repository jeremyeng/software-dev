#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>

#include "typeChecker.h"
#include "sorer.h"
#include "args.h"
#include "test.h"

void printColType(Args *args) {
    if (args->print_col_type)
    {
        assignmentData_t d_type = getColumnType(args);
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
}

void printColIdx(Args *args) {
    if(args->print_col_idx)
    {
        std::string result = getRowColValue(args->col_idx_a, args->col_idx_b, args->targetFileName);
        if(isString(result))
        {
            std::cout<<"\""<<result<<"\"\n";
        }
        else
        {
            std::cout<<result<<'\n';
        }
    }
}

void isMissingIdx(Args *args) {
    if(args->is_missing_idx)
    {
        if(isInvalid(args->missing_idx_a, args->missing_idx_b, args->targetFileName))
        {
            std::cout<<"1\n";
        }
        else 
        {
            std::cout<<"0\n";
        }
    }
}

int main(int argc, char **argv)
{
    Args *args = Args::getInstance();
    args->setArgs(argc, argv);
   
    if(args->targetFileName == nullptr)
    {
        std::cout<<"error - no file name given\n";
        return 1;
    }

    size_t row_size = getMaxFieldRowSize(args->targetFileName);

    if(row_size == 0)
    {
        std::cout<<"Bad file. Exiting.\n";
        return 1;
    }

    std::vector<assignmentData_t> column_types;
    getColumnTypes(&column_types, args->targetFileName, row_size);

    printColType(args);
    printColIdx(args);
    isMissingIdx(args);

    runTests();
}