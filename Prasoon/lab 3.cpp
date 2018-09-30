//
//lab3.cpp
//
//Sean Warnock
//Alton Nguyen
//Prasoon Shakya
//Lab 3
//It prints the numbers in anti-clockwise spiral form.
//
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void makeSpiral(int rows, int columns, int numArray[][20])
{
    int num = 1;

    int startingRow = 0;
    int endingRow = rows;
    int startingColumn = 0;
    int endingColumn = columns;

    while(num <= rows*columns)
    {
        for (int i = startingRow; i < endingRow; i++)
        {
            numArray[i][startingColumn] = num++;
        }
        startingColumn++;

        for (int i = startingColumn; i < endingColumn; i++)
        {
            numArray[endingRow - 1][i] = num++;
        }
        endingRow--;

        for(int i = (endingRow - 1); i >= startingRow; i--)
        {   if(num > (rows*columns))
                return;
            numArray[i][endingColumn - 1] = num++;
        }
        endingColumn--;

        for(int i = (endingColumn - 1); i >= startingColumn; i--)
        {
            if(num > (rows*columns))
                return;
            numArray[startingRow][i] = num++;
        }
        startingRow++;


    }
}

void printSpiral(ofstream &outputFile, int numArray[][20], int rowsToPrint,
                 int columnsToPrint)
{
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            outputFile << setw(4) << numArray[i][j] ;
        }
        outputFile << endl;
    }
}

int main()
{
    const int MAXROW = 15;
    const int MAXCOLUMN = 20;

    int numArray[MAXROW][MAXCOLUMN] = {{0}};

    ofstream outputFile("outputFile-15X20.txt");
    if(!outputFile)
    {
        cout << "output file not found";
        return -1;
    }

    int rows = 15;
    int columns = 20;

    makeSpiral(rows, columns, numArray);
    printSpiral(outputFile, numArray, MAXROW, MAXCOLUMN);
    outputFile.close();
    return 0;
}
