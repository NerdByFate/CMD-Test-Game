#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

void CreateBoard(char board[10][10]);
void PrintBoard(char board[10][10]);
void GetInput(char& input);
void MovePlayer(char board[10][10], char userInput);
void TestPlayerLocation(char board[10][10], int& x, int& y);
void RelocatePlayer(int x, int y, char board[10][10], char input);
bool TestClose(char input);
