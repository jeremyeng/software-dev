#include <iostream>
#include <cstdio>

void readFile(const char *filename)
{
    FILE *myFile = fopen(filename, "r");
    char readFromFile [300];
    if (myFile == NULL)
    {
        std::cout << "bad file name\n";
        exit(1);
    }

    if(fgets (readFromFile, 300, myFile) != NULL)
    {
        std::cout << readFromFile << "\n";
    }
}

int main(int argc, char **argv)
{
    readFile("input.txt");
}