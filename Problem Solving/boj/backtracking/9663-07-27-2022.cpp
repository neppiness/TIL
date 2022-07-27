#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N;
bool isOccupied[20][20] = {false};
int cnt = 0;

queue<pair<int,int>> validCoords(int x, int y) {
    queue<pair<int,int>> Q;
    bool isInQ[N][N] = {false};
    for(int row = 0; row < N; row++) if(!isInQ[row][y]) {Q.push({row, y}); isInQ[row][y] = 1;}
    for(int col = 0; col < N; col++) if(!isInQ[x][col]) {Q.push({x, col}); isInQ[x][col] = 1;}
    
    int nx = x; int ny = y;
    while(nx > 0 && ny > 0) {nx--; ny--;}
    while(nx < N && ny < N) {
        if(!isInQ[nx][ny]) {Q.push({nx, ny}); isInQ[nx][ny] = 1;}
        nx++; ny++;
    }
    
    nx = x; ny = y;
    while(nx > 0 && ny < N-1) {nx--; ny++;}
    while(nx < N && ny >= 0) {
        if(!isInQ[nx][ny]) {Q.push({nx, ny}); isInQ[nx][ny] = 1;}
        nx++; ny--;
    }

    return Q;
}

bool canOccupy(queue<pair<int,int>> Q){
    while(!Q.empty()) {
        auto coord = Q.front(); Q.pop();
        int nx = coord.first; int ny = coord.second;
        if(isOccupied[nx][ny]) return false;
    }
    return true;
}

void occupy(queue<pair<int,int>> Q) {
    while(!Q.empty()) {
        auto coord = Q.front(); Q.pop();
        int nx = coord.first; int ny = coord.second;
        isOccupied[nx][ny] = 1;
    }
}

void unoccupy(queue<pair<int,int>> Q) {
    while(!Q.empty()) {
        auto coord = Q.front(); Q.pop();
        int nx = coord.first; int ny = coord.second;
        isOccupied[nx][ny] = 0;
    }
}

void BT(int x, int y, int n){
    if(n == 0) cnt++;
    else for(int row = x; row < N; row++)
        for(int col = y; col < N; col++) {
            if(isOccupied[row][col]) continue;
            else {
                queue<pair<int,int>> Q = validCoords(row, col);

                if(canOccupy(Q)) occupy(Q);
                else continue;
                
                BT(row, col, n-1);
                
                unoccupy(Q);
            }
        }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    BT(0, 0, N);

    cout << cnt;
}