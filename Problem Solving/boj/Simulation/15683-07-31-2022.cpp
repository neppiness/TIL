#include <iostream>

using namespace std;

int N, M, MX;
int board[10][10];

int minDeadArea = 100;

int noOfCams = 0;
int camPosition[10], camRotation[10], camType[10];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

bool OOB(int x, int y) {return x >= N || x < 0 || y >= M || y < 0;}

void firstCamActs(int camIdx, int rot) {
    int position = camPosition[camIdx];
    int cx = position / M; int cy = position % M;

    while(true) {
        cx += dx[rot]; cy += dy[rot];

        if(OOB(cx, cy)) break;
        if(board[cx][cy] == 6) break;
        if(board[cx][cy] != 0) continue;
        board[cx][cy] = 7;
    }
}

void allCamsAct(int camIdx) {
    if(camType[camIdx] == 1) {
        firstCamActs(camIdx, camRotation[camIdx]);
    } else if(camType[camIdx] == 2) {
        firstCamActs(camIdx, camRotation[camIdx]);
        firstCamActs(camIdx, camRotation[camIdx] + 2);
    } else if(camType[camIdx] == 3) {
        firstCamActs(camIdx, (camRotation[camIdx]) % 4);
        firstCamActs(camIdx, (camRotation[camIdx] + 1) % 4);
    } else if(camType[camIdx] == 4) {
        for(int i = 0; i < 4; i++) {
            if(i == camRotation[camIdx]) continue;
            firstCamActs(camIdx, i);
        }
    } else if(camType[camIdx] == 5) {
        firstCamActs(camIdx, 0); firstCamActs(camIdx, 1);
        firstCamActs(camIdx, 2); firstCamActs(camIdx, 3);
    }
}

void boardReset() {
    for(int idx = 0; idx < MX; idx++)
        if(board[idx / M][idx % M] == 7) board[idx / M][idx % M] = 0;
}

void rotComb(int m) {
    int deadAreaCnt = 0;
    if(m == noOfCams) {
        for(int camIdx = 0; camIdx < noOfCams; camIdx++) allCamsAct(camIdx);

        for(int idx = 0; idx < MX; idx++)
            deadAreaCnt += (board[idx / M][idx % M] == 0);
        minDeadArea = min(deadAreaCnt, minDeadArea);
        boardReset();
        return;
    }

    int rotMX;
    if(camType[m] == 2) rotMX = 2;
    else if(camType[m] == 5) rotMX = 1;
    else rotMX = 4;

    for(int rot = 0; rot < rotMX; rot++) {
        camRotation[m] = rot;
        rotComb(m + 1);
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    MX = N*M;
    
    for(int idx = 0; idx < MX; idx++) {
        int row = idx / M; int col = idx % M;
        cin >> board[row][col];
        if(board[row][col] == 0 || board[row][col] == 6) continue;
        camType[noOfCams] = board[row][col];
        camPosition[noOfCams++] = idx;
    }

    rotComb(0);
    cout << minDeadArea;
}