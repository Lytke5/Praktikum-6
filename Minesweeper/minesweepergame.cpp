#include "minesweepergame.h"
#include <iostream>

using namespace std;

MinesweeperGame::MinesweeperGame(int newSize, int bombAmount)
{
    size = newSize;

    srand(time(0));

    for(int i = 0; i < size; i++) // Feld befüllung
    {
        for (int j = 0; j < size; j++)
        {
            field[i][j] = '*';
            fieldIntern[i][j] = false;
        }
    }

    for(int i = 0; i < bombAmount; i++) // Bomben werden plaziert
    {
        int h = rand() % size;
        bombPositions.push_back(h);
        int v = rand() % size;
        bombPositions.push_back(v);

        fieldIntern[v][h] = true;
    }
}

MinesweeperGame::MinesweeperGame(int newSize, vector<int> newBombPositions)
{
    size = newSize;

    srand(time(0));

    for(int i = 0; i < size; i++) // Feld befüllung
    {
        for (int j = 0; j < size; j++)
        {
            field[i][j] = '*';
            fieldIntern[i][j] = false;
        }
    }

    for(int i = 0; i < newBombPositions.size(); i=i+2) // Bomben werden plaziert
    {
        int h = newBombPositions[i];
        int v = newBombPositions[i+1];

        fieldIntern[v][h] = true;
    }
}

char MinesweeperGame::sweepMine(int v, int h)
{
    int mines = 0;
    if(h-1 >= 0)
    {
    if(fieldIntern[v-1][h-1] == true)
        mines++;
    if(fieldIntern[v][h-1] == true)
        mines++;
    if(fieldIntern[v+1][h-1] == true)
        mines++;
    }
    if(h+1 <= size)
    {
    if(fieldIntern[v-1][h+1] == true)
        mines++;
    if(fieldIntern[v][h+1] == true)
        mines++;
    if(fieldIntern[v+1][h+1] == true)
        mines++;
    }

    if(fieldIntern[v-1][h] == true)
        mines++;
    if(fieldIntern[v+1][h] == true)
        mines++;


 return (char)mines+48;
}

void MinesweeperGame::openField(int v, int h)
{
    if(sweepMine(v, h) == '0')
    {
        if(fieldIntern[v][h] == false)
        {
        field[v][h] = '_';

        if(h-1 >= 0)
        {
        if(field[v-1][h-1] == '*')
        openField(v-1, h-1);
        if(field[v][h-1] == '*')
        openField(v, h-1);
        if(field[v+1][h-1] == '*')
        openField(v+1, h-1);
        }

        if(h +1 < size)
        {
        if(field[v-1][h+1] == '*')
        openField(v-1, h+1);
        if(field[v+1][h+1] == '*')
        openField(v+1, h+1);
        if(field[v][h+1] == '*')
        openField(v, h+1);
        }

        if(field[v-1][h] == '*')
        openField(v-1, h);
        if(field[v+1][h] == '*')
        openField(v+1, h);
        }
    }
    else
    {
        field[v][h] = sweepMine(v, h);
    }
}

bool MinesweeperGame::getFieldIntern(int v, int h)
{
    return fieldIntern[v][h];
}

char MinesweeperGame::getField(int v, int h)
{
    return field[v][h];
}

void MinesweeperGame::setField(int v, int h, char c)
{
    field[v][h] = c;
}

int MinesweeperGame::getScore()
{
    int score = 0;
    for(int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(field[i][j] != '*' && field[i][j] != '#' && field[i][j] != 'P')
                score++;
        }
    }
    return score;
}

vector<int> MinesweeperGame::getBombPositions()
{
    return bombPositions;
}
