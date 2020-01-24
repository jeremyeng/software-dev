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

std::string sanatizeStr(std::string *str)
{
    size_t count = 0;

    while (str->at(count) == 32)
    {
        count++;
    }
    size_t start = count;
    if (str->at(count) == 34)
    {
        size_t end = str->find(34, count + 1);
        if (end >= str->length()) 
        {
            end = str->length();
            return str->substr(start, end - start);
        }
        return str->substr(start, end - start + 1);
    }
    else
    {
        size_t end = str->find(32, start);
        if (end >= str->length()) 
        {
            end = str->length();
        }
        return str->substr(start, end - start);
    }
}

/**
 * @brief get a vector containing all the fields in a given row
 * @param rowData a string representing all the row's data
 * @return a vector of strings representing the individual data points
 */
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
        std::string fullStr = rowData->substr(start + 1, end - start - 1);
        rowFields.push_back(sanatizeStr(&fullStr));
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
 * @param column_types the vector that will hold the column type data
 * @param file_name the name of the target file
 * @param row size the row size of this file, as determined by the schema
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

/**
 * @brief get the number of fields in the row with the most fields
 * @param file_name the name of the target file
 * @return the number of fields
 * @note only the first 500 rows are checked
 */
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
    //std::cout << "Row length: " << row_size << "\n";

    myFile.close();
    return row_size;
}

/**
 * @brief get the given row from a file
 * @param row the target row indexed from one
 * @param filename the target file
 */
std::string getRow(size_t row, const char *filename)
{
    std::ifstream myFile;
    std::string file_input;
    myFile.open(filename);

    for (int index = 1; index <= row; index++)
    {
        if (!myFile)
        {
            myFile.close();
            return "";
        }
        if (index == row)
        {
            std::getline(myFile, file_input);
            myFile.close();
            //TODO remove debug line
            return file_input;
        }
    }
}

/**
 * @brief get the value of the given row at the given column
 * @param row the string representing the data at that row
 * @param column the column to target
 * @param column_types the types each column belongs to
*/
std::string getColumn(std::string *row, size_t column, std::vector<assignmentData_t> *column_types)
{
    char const *INVALID = "invalid";

    std::vector<std::string> *values = getRowFieldVector(row);

    //std::cout<<*row<<"has "<<values->size()<<" data points\n";

    assignmentData_t dataTypeOfColumn = column_types->at(column);

    // if we look beyond the max column, we error
    if (column > column_types->size())
    {
        return "failed";
    }

    if (column > values->size())
    {
        //std::cout << "row too short\n";
        return INVALID;
    }
    switch (dataTypeOfColumn)
    {
    case INT:
        if (isInt(values->at(column)) && !isBool(values->at(column)))
        {
            return values->at(column);
        }
        break;
    case STRING:
        if (isString(values->at(column)))
        {
            return values->at(column);
        }
        break;
    case BOOL:
        if (isBool(values->at(column)))
        {
            return values->at(column);
        }
        break;
    case FLOAT:
        if (isInt(values->at(column)) && !isBool(values->at(column)))
        {
            return values->at(column);
        }
        break;

    default:
        return INVALID;
        break;
    }
}

/**
 * @brief get the value at the given row and column in the given file
 * @param row the target row, indexed from 1 on
 * @param col the target col, indexed from 0 on
 * @param filename the name of the target file
 * @return the string being either the value of "invalid"
 */
std::string getRowColValue(size_t row, size_t col, const char *filename)
{
    std::string rowData = getRow(row, filename);
    //std::cout<<"row data: "<<rowData<<"\n";
    size_t row_size = getMaxFieldRowSize(filename);
    std::vector<assignmentData_t> columnTypes;

    getColumnTypes(&columnTypes, filename, row_size);

    return getColumn(&rowData, col, &columnTypes);
}

/**
 * @brief is there an invalid value at the given index?
 * @param row the row of the value, indexed from 1
 * @param col the col of the value, indexed from 0
 * @param filename the file to read from
 * @return true if there is an invalid value, false if there is not
 * @note if the data at the index does not match the schema for its column
 * then we consider it invalid
 */
bool isInvalid(size_t row, size_t col, const char *filename)
{
    return getRowColValue(row, col, filename) == "invalid";
}

/**
 * @brief get the data type of the given column in the given file
 * @param col the column to look at
 * @param filename the file to read from
 */
assignmentData_t getColumnType(size_t col, const char *filename)
{
    size_t row_size = getMaxFieldRowSize(filename);
    std::vector<assignmentData_t> columnDataTypes;

    getColumnTypes(&columnDataTypes, filename, row_size);

    return columnDataTypes.at(col);
}
