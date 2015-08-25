#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include <fstream>

void CreateBoard(char board[10][10]);
void PrintBoard(char board[10][10]);
void GetInput(char& input);
void MovePlayer(char board[10][10], char userInput, int& score);
void TestPlayerLocation(char board[10][10], int& x, int& y);
void TestNewLocation(char board[10][10], const int x, const int y, int& score, char input);
void RelocatePlayer(int x, int y, char board[10][10], char input);
bool TestClose(char input);
