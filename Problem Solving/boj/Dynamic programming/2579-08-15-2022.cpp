#include <iostream>
#include <algorithm>

using namespace std;

int stair[2][302];
int score[302];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    int N; cin >> N;
    for(int i = 0; i < N; i++) cin >> score[i];

    for(int i = 0; i < 2; i++) fill(stair[i], stair[i] + N, 0);

    stair[0][0] = score[0]; // 1st stair with a 1-step increment
    stair[1][1] = stair[0][0] + score[1]; // 2nd stair with two 1-step inc.
    stair[0][1] = score[1]; // 2nd stair with a 2-step inc.

    for(int step = 2; step < N; step++) {
        stair[1][step] = stair[0][step-1] + score[step];
        stair[0][step] = max(stair[0][step-2] + score[step], stair[0][step]);
        stair[0][step] = max(stair[1][step-2] + score[step], stair[0][step]);
    }

    int MX = 0;
    MX = max(stair[0][N-1], stair[1][N-1]);
    cout << MX;
}

// 0-indexed solution