#include <iostream>

using namespace std;

int colors[2];
bool board[130][130];

bool isMatch(int N, int x, int y){
    bool color = board[x][y];
    for(int row = x; row < x + N; row++)
        for(int col = y; col < y + N; col++)
            if(color != board[row][col]) return false;
    return true;
}

void count(int N, int x, int y) {
    if(isMatch(N, x, y)) colors[board[x][y]]++;
    else for(int row = 0; row < 2; row++)
        for(int col = 0; col < 2; col++) count(N/2, x + row*N/2, y + col*N/2);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    colors[0] = 0; colors[1] = 0;

    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++) cin >> board[row][col];

    count(N,0,0);

    cout << colors[0] << '\n';
    cout << colors[1] << '\n';
}