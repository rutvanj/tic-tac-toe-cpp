#include <iostream>
using namespace std;

char board[3][3] = {
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

void displayBoard() {
    cout << endl;
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout << " " << board[i][j] << " ";
            if(j<2) cout << "|";
        }
        cout << endl;
        if(i<2) cout << "---+---+---" << endl;
    }
    cout << endl;
}

bool checkWin(char player) {
    for(int i=0;i<3;i++)
        if(board[i][0]==player && board[i][1]==player && board[i][2]==player)
            return true;

    for(int i=0;i<3;i++)
        if(board[0][i]==player && board[1][i]==player && board[2][i]==player)
            return true;

    if(board[0][0]==player && board[1][1]==player && board[2][2]==player)
        return true;

    if(board[0][2]==player && board[1][1]==player && board[2][0]==player)
        return true;

    return false;
}

void makeMove(int pos, char player) {
    int row = (pos-1)/3;
    int col = (pos-1)%3;
    board[row][col] = player;
}

int main() {

    int move;
    char player = 'X';

    for(int turn=0; turn<9; turn++) {

        displayBoard();

        cout << "Player " << player << " choose position: ";
        cin >> move;

        makeMove(move, player);

        if(checkWin(player)) {
            displayBoard();
            cout << "Player " << player << " wins!" << endl;
            return 0;
        }

        player = (player=='X') ? 'O' : 'X';
    }

    displayBoard();
    cout << "It's a draw!" << endl;

    return 0;
}