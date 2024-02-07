#include <iostream>
#include <algorithm>

using namespace std;

int N, M, x, y, K;
int board[22][22];

int xDirDice[3] = {0};
int yDirDice[3] = {0};

int top = 0;

int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};

void moveEast() {
    rotate(yDirDice, yDirDice + 1, yDirDice + 3);
    swap(yDirDice[2], top);
    xDirDice[1] = yDirDice[1];
}
void moveWest() {
    rotate(yDirDice, yDirDice + 2, yDirDice + 3);
    swap(yDirDice[0], top);
    xDirDice[1] = yDirDice[1];
}
void moveNorth() {
    rotate(xDirDice, xDirDice + 2, xDirDice + 3);
    swap(xDirDice[0], top);
    yDirDice[1] = xDirDice[1];
}
void moveSouth() {
    rotate(xDirDice, xDirDice + 1, xDirDice + 3);
    swap(xDirDice[2], top);
    yDirDice[1] = xDirDice[1];
}

bool OOB(int nx, int ny) {return nx >= N || nx < 0 || ny >= M || ny < 0;}

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M >> x >> y >> K;

    for(int row = 0; row < N; row++)
        for(int col = 0; col < M; col++) cin >> board[row][col];

    int nx = x; int ny = y;
    while(K--) {
        int move; cin >> move;
        if(OOB(nx + dx[move], ny + dy[move])) continue;

        nx += dx[move]; ny += dy[move];

        if(move == 1) {moveEast();}
        else if(move == 2) {moveWest();}
        else if(move == 3) {moveNorth();}
        else {moveSouth();}

        if(board[nx][ny] == 0) {
            board[nx][ny] = xDirDice[1];
        } else {
            xDirDice[1] = board[nx][ny];
            yDirDice[1] = board[nx][ny];
            board[nx][ny] = 0;
        }

        cout << top << '\n';
    }
}