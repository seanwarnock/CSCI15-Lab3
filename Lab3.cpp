/*
CSCI 15 Lab 3
Fall 2018

Sean Warnock warlock.da.newbie@gmail.com
Alton Nguyen atnguyen0035@zonemail.clpccd.edu
prasoon shakya prasshakya1@gmail.com
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

const int MAXROW = 15;
const int MAXCOLUMN = 20;

void makeSpiral(int rows, int columns, int numArray[][20])
{
/*
This function fills a two dimensional array with an incrementing
integer value.
*/
    int num = 1;

    int startingRow = 0;
    int endingRow = rows; //15
    int startingColumn = 0;
    int endingColumn = columns; //20
    int total = rows * columns;

    int i;
    // run until exit?
    while(num <= total)
    {
        i = startingRow;
        //Down
        while(i < endingRow && (num <= total))
        {
            numArray[i][startingColumn] = num++;
            i++;
        }
        i = ++startingColumn;
        //Right
        while(i < endingColumn && (num <= total))
        {
            numArray[endingRow-1][i] = num++;
            i++;
        }
        i = --endingRow-1;
        //Up
        while(i > startingRow && (num <= total))
        {
            numArray[i][endingColumn-1] = num++;
            i--;
        }
        i = --endingColumn;
        //Left
        while(i >= startingColumn && (num <= total))
        {
            numArray[startingRow][i] = num++;
            i--;
        }
        startingRow++;
    }
}

void printSpiral(ofstream &outputFile, int numArray[][20], int rows, int colums)
{
    //Print out the array
    //todo, MUST use setw using a calculated amount.
    //int total = rows + columns;
    int columnwidth = 1;
    int total = rows * colums;


    while(total=total/10)
    {
        columnwidth++;
    }
    columnwidth++;
    for(int i = 0; i < MAXROW; i++)
    {
        for(int j = 0; j < MAXCOLUMN; j++)
        {
            cout << setw(columnwidth) << numArray[i][j] ;;
            outputFile << setw(columnwidth) << numArray[i][j] ;
        }

        cout << endl;
        outputFile << endl;
    }
}

void fillArray(int row, int column, int arraytofill[MAXROW][MAXCOLUMN])
{
    //This function clears out the array
    for (int i=0; i<row; i++)
    {
        for(int j=0; j<column; j++)
        {
            arraytofill[i][j]=0;
        }
    }
}

int main(int argc, char *argv[])
{
    int numArray[MAXROW][MAXCOLUMN];
    int rows = 1;
    int columns = 20;
    string filename = "outputFile.txt";

    if (argc < 2)
    {
        cout << "Array = " << rows << "X" << columns << " Max Row =" << MAXROW << " Max column =" << MAXCOLUMN << "Total =" << rows * columns << endl;
    }

    ofstream outputFile(filename);
    if(!outputFile)
    {
        cout << "output file not found";
        return -1;
    }


    fillArray(MAXROW, MAXCOLUMN, numArray);
    makeSpiral(rows, columns, numArray);
    printSpiral(outputFile, numArray, MAXROW, MAXCOLUMN);
    outputFile.close();
}
