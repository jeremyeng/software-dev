#pragma once
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <vector>
#include "a1datatypes.h"

std::vector<std::string> *getRowFieldVector(std::string *rowData)
{
    static std::vector<std::string> rowFields;
    rowFields.clear();
    size_t count = 0;
    while (count < rowData->length())
    {
        size_t start = rowData->find(60, count);
        size_t end = rowData->find(62, start);
        // increment start beacuse start is the the < and substract 1 from size because of the >
        rowFields.push_back(rowData->substr(start + 1, end - start - 1));
        count = end + 1;
    }

    return &rowFields;
}

void getRowDataTypes(std::vector<std::string> *row_data, std::vector<assignmentData_t> &column_types, size_t row_size)
{
    if (column_types.size() < row_size)
    {
        for (int i = 0; i < row_size; i++)
        {
            column_types.push_back(assignmentData_t::BOOL);
        }
    }

    for (int index = 0; index < row_data->size(); index++)
    {
        if (isInt(row_data->at(index)) && !isBool(row_data->at(index)) && column_types.at(index) != assignmentData_t::FLOAT && column_types.at(index) != assignmentData_t::STRING)
        {
            column_types[index] = assignmentData_t::INT;
        }
        else if (isFloat(row_data->at(index)) && column_types.at(index) != assignmentData_t::STRING)
        {
            column_types[index] = assignmentData_t::FLOAT;
        }
        else if (isString(row_data->at(index)))
        {
            column_types[index] = assignmentData_t::STRING;
        }
    }
}

/**
 * @brief determine the data type of each of the columns
 * @param file_name the name of the target file
 */
void getColumnTypes(std::vector<assignmentData_t> *column_types, const char *file_name, size_t row_size)
{
    /*
    1 - get the data from each row into a string vector
    2 - clean those strings
    3 - check the data type of each string
    4 - on the first pass, put that data type into the column types vector
    5 - on subsequent passes, follow the heirarchy and replace accordingly
    */

    std::vector<std::string> *dataValues;

    std::ifstream my_file;
    std::string file_input;
    my_file.open(file_name);

    //only the first 500 lines matter
    size_t count = 0;

    while (my_file && count < 500)
    {
        std::getline(my_file, file_input);
        dataValues = getRowFieldVector(&file_input);
        getRowDataTypes(dataValues, *column_types, row_size);
        count++;
    }

    my_file.close();
}

//returns the number of fields in the row with the most fields
size_t getMaxFieldRowSize(const char *file_name)
{
    std::ifstream myFile;
    std::string file_input;
    size_t row_size = 0;
    myFile.open(file_name);

    //only the first 500 lines matter
    size_t count = 0;

    while (myFile && count < 500)
    {
        std::getline(myFile, file_input);
        size_t this_length = std::count(file_input.begin(), file_input.end(), '<');
        if (this_length > row_size)
        {
            row_size = this_length;
        }
        count++;
    }
    std::cout << "Row length: " << row_size << "\n";

    myFile.close();
    return row_size;
}

/**
 * @brief get the value of the given row at the given column
 * @param row the string representing the data at that row
 * @param column the column to target
*/
void getColumn(std::string row, size_t column)
{
}
