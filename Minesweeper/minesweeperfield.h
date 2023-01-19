#ifndef MINESWEEPERFIELD_H
#define MINESWEEPERFIELD_H
#include <Windows.h>


class MinesweeperField
{   
public:
    void printField();

protected:
    int size;
    char field[26][26];
    bool fieldIntern[26][26];
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


};

#endif // MINESWEEPERFIELD_H
