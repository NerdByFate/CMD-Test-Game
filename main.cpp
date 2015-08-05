/*
/This is a test program in which we use the console to emulate a fully functional game.
/
/This program was authored by Cherokee Parker (aka NerdByFate; 33kingkiller; John Wot) on 8-3-15.
/
/This program was last updated on 8-5-15.
*/

#include "libs.h"

const int dimension = 10;

int main() {
    //Precondition:
    //  N/A.
    //Postcondition:
    //  The game has ended.

    using namespace std;

    bool close = false;
    char board[dimension][dimension]; //Creates 2D array.
    char input;
    cout << "Welcome to my test game! Enter 'w' to move up, 'a' to move to the left, and 'd' to move to the right. You can also use '~' to quit the game and 'r' to reset th-e board. Press enter after each character.\n\n";

    //Main Module:
    CreateBoard(board);
    while(close == false) { //Game loop.
        close = TestClose(input);
        if(close == true) {
            break;
        }
        PrintBoard(board);
        GetInput(input);
        MovePlayer(board, input);
    }
    cout << "Thank you for playing this test game by Cherokee Parker!\n" << "Press ENTER to continue...\n\n";
    cin.ignore(1);
    cin.get();
    return 0;
}

void CreateBoard(char board[dimension][dimension]) { //Sets player to middle ('0'), everything else '-'.
    //Precondition:
    //  2D Array has been declared and passed.
    //Postcondition:
    //  The board is set.

    for(int i = 0; i < (dimension-1); i++) {
        board[i][0] = '-';
        board[i][1] = '-';
        board[i][2] = '-';
        board[i][3] = '-';
        board[i][4] = '-';
        board[i][5] = '-';
        board[i][6] = '-';
        board[i][7] = '-';
        board[i][8] = '-';
        board[i][(dimension-1)] = '-';
    }
    board[4][4] = '0';
}

void PrintBoard(char board[dimension][dimension]) { //Prints 2D array.
    //Precondition:
    //  The board is set.
    //Postcondition:
    //  The player can see the board.

    using namespace std;

    for(int i = 0; i < (dimension-1); i++) {
        cout << board[i][0] << board[i][1] << board[i][2] << board[i][3] << board[i][4] << board[i][5] << board[i][6] << board[i][7] << board[i][8] << board[i][(dimension-1)] << endl;
    }
}

void GetInput(char& input) { //"cin".
    //Precondition:
    //  N/A.
    //Postcondition:
    //  Player's input is read and stored.

    using namespace std;

    cin >> input;
    if(!cin) {
        cout << "ERROR: Input failure\n";
        return;
    }
}

void MovePlayer(char board[dimension][dimension], char& userInput) { //Does not directly move the player.
    //Precondition:
    //  N/A; level 2 has precondition.
    //Postcondition:
    //  The player has been moved.

    TestPlayerLocation(board, userInput);
}

void TestPlayerLocation(char board[dimension][dimension], char input) { //Runs "RelocatePlayer" with the player's coordinates.
    //Precondition:
    //  The board is set && "RelocatePlayer" has been prototyped.
    //Postcondition:
    //  The player's coordinates have been passed to "RelocatePlayer".

    for (int i = 0; i < (dimension-1); i++) {
        if(board[i][0] == '0') {
            RelocatePlayer(i, 0, board, input);
        }else if(board[i][1] == '0') {
            RelocatePlayer(i, 1, board, input);
        }else if(board[i][2] == '0') {
            RelocatePlayer(i, 2, board, input);
        }else if(board[i][3] == '0') {
            RelocatePlayer(i, 3, board, input);
        }else if(board[i][4] == '0') {
            RelocatePlayer(i, 4, board, input);
        }else if(board[i][5] == '0') {
            RelocatePlayer(i, 5, board, input);
        }else if(board[i][6] == '0') {
            RelocatePlayer(i, 6, board, input);
        }else if(board[i][7] == '0') {
            RelocatePlayer(i, 7, board, input);
        }else if(board[i][8] == '0') {
            RelocatePlayer(i, 8, board, input);
        }else if(board[i][(dimension-1)] == '0') {
            RelocatePlayer(i, (dimension-1), board, input);
        }
    }
}

void RelocatePlayer(const int x, const int y, char board[dimension][dimension], char input) { //Actually moves the player.
    //Precondition:
    //  The player's input is read and stored && The board has been set && The player's coordinates have been passed.
    //Postcondition:
    //  The player ('0') has been assigned a new location on the board.

    board[x][y] = '-';
    if(tolower(input) == 'w' && x > 0 && x <= (dimension-1)) {
        board[x - 1][y] = '0';
    }else if(tolower(input) == 's' && x >= 0 && x < (dimension-1)) { //BROKEN!!
        board[x + 1][y] = '0';
    }else if(tolower(input) == 'a' && y > 0 && y <= (dimension-1)) {
        board[x][y - 1] = '0';
    }else if(tolower(input) == 'd' && y >= 0 && y < (dimension-1)) {
        board[x][y + 1] = '0';
    }else if(tolower(input) == 'r') {
        board[4][4] = '0';
    }else {
        board[x][y] = '0';
    }
}

bool TestClose(char& input) { //Test if player inputs '~'.
    //Precondition:
    //  The player's input is read and stored.
    //Postcondition:
    //  Returns boolean value true or false.

    if(input == '~') {
        return true;
    }else {
        return false;
    }
}
