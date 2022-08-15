#include <iostream>
#include <algorithm>

using namespace std;

int stair[3][302];
int score[302];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> score[i];

    for(int i = 0; i < 3; i++) fill(stair[i], stair[i] + N, 0);

    stair[1][0] = score[0]; // 1st stair with a 1-step increment
    stair[2][1] = stair[1][0] + score[1]; // 2nd stair with two 1-step inc.
    stair[0][1] = score[1]; // 2nd stair with a 2-step inc.

    for(int step = 2; step < N; step++) {
        for(int seq = 0; seq < 3; seq++) {
            if(stair[seq][step-1] != 0 && seq < 2) stair[seq+1][step] = stair[seq][step-1] + score[step];
            stair[0][step] = max(stair[seq][step-2] + score[step], stair[0][step]);
        }
    }

    int MX = 0;
    for(int i = 0; i < 3; i++) MX = max(MX, stair[i][N-1]);

    for(int i = 0; i < 3; i++) cout << stair[i][N-1] << ' ';
    cout << MX;
}