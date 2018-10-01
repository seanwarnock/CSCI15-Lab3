/*
Sean Warnock warlock.da.newbie@gmail.com
Alton Nguyen atnguyen0035@zonemail.clpccd.edu
prasoon shakya prasshakya1@gmail.com
*/
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

void makeSpiral(int rows, int columns, int numArray[][20])
{
/*
This function fills a two dimensional array with an incrementing
integer value.
*/
    int num = 1;

    int startingRow = 0;
    int endingRow = rows - 1;
    int startingColumn = 0;
    int endingColumn = columns - 1;

    int i;
    while(num <= rows*columns)
    {
        i = startingRow;
        while((i <= endingRow) && (!numArray[i][startingColumn]))
        {
            numArray[i][startingColumn] = num++;
            i++;
        }
        startingColumn++;

        i = startingColumn;
        while((i <= endingColumn) && (!numArray[endingRow][i]))
        {
            numArray[endingRow][i] = num++;
            i++;
        }
        endingRow--;

        i = endingRow;
        while((i >= startingRow) && (!numArray[i][endingColumn]))
        {
            numArray[i][endingColumn] = num++;
            i--;
        }
        endingColumn--;

        i = endingColumn;
        while((i >= startingColumn) && (!numArray[startingRow][i]))
        {
            numArray[startingRow][i] = num++;
        }
        startingRow++;
    }
}

void printSpiral(ofstream &outputFile, int numArray[][20], int rowsToPrint, int columnsToPrint)
{
    for(int i = 0; i < 15; i++)
    {
        for(int j = 0; j < 20; j++)
        {
            cout << setw(4) << numArray[i][j] ;;
            outputFile << setw(4) << numArray[i][j] ;
        }

        cout << endl;
        outputFile << endl;
    }
}

void fillArray(int row, int column, int arraytofill[][20])
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
    const int MAXROW = 15;
    const int MAXCOLUMN = 20;

    int numArray[MAXROW][MAXCOLUMN];

    ofstream outputFile("outputFile.txt");
    if(!outputFile)
    {
        cout << "output file not found";
        return -1;
    }

    int rows = 15;
    int columns = 3;

    fillArray(MAXROW, MAXCOLUMN, numArray);
    makeSpiral(rows, columns, numArray);
    printSpiral(outputFile, numArray, MAXROW, MAXCOLUMN);
    outputFile.close();
}
