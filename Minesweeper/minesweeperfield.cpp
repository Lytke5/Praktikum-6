#include "minesweeperfield.h"
#include <iostream>

using namespace std;

void MinesweeperField::printField()
{
    cout << "   ";
    SetConsoleTextAttribute(hConsole, 11);
    for(int i = 0; i < size; i++) // Buchstabenausgabe
    {
        int a = i+65;
        cout << (char)a << " ";
    }
    cout << endl;

    for(int i = 0; i < size; i++) // Feldausgabe
    {
        SetConsoleTextAttribute(hConsole, 11);
        if(i < 10)
            cout << " ";
        cout << i << " ";
        SetConsoleTextAttribute(hConsole, 15);
        for (int j = 0; j < size; j++)
        {
            if(field[i][j] == '#')
                SetConsoleTextAttribute(hConsole, 12);
            else if(field[i][j] == 'P')
                SetConsoleTextAttribute(hConsole, 10);

            cout << field[i][j] << " ";
            SetConsoleTextAttribute(hConsole, 15);
        }
        cout << endl;
    }
}
