#ifndef MINESWEEPERGAME_H
#define MINESWEEPERGAME_H
#include <Windows.h>
#include <vector>
#include "minesweeperfield.h"

using namespace std;

class MinesweeperGame : public MinesweeperField
{   
public:
    MinesweeperGame(int newSize, int bombAmount);
    MinesweeperGame(int newSize, vector<int> newBombPositions);
    char sweepMine(int v, int h);
    void openField(int v, int h);
    bool getFieldIntern(int v, int h);
    char getField(int v, int h);
    void setField(int v, int h, char c);
    int getScore();
    vector<int> getBombPositions();

private:
    vector<int> bombPositions;

};

#endif // MINESWEEPERGAME_H
