#include <iostream>
#include <algorithm>

int N;
int board[22][22];
int MIN = 987654321;

using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    for(int row = 0; row < N; row++)
        for(int col = 0; col < N; col++) cin >> board[row][col];

    bool comb[N] = {0};
    int member[2][N] = {0}; // member[team][id] to save index
    
    int half = N/2;
    fill(comb + half, comb + N, 1);

    bool perm[2][half];
    fill(perm[0], perm[0] + half - 1, false);
    fill(perm[1], perm[1] + half - 1, false);
    fill(perm[0] + half - 2, perm[0] + half, true);
    fill(perm[1] + half - 2, perm[1] + half, true);

    do{
        int synZero = 0, synOne = 0;

        int zeroTCnt = 0, oneTCnt = 0;
        for(int idx = 0; idx < N; idx++) {
            if(comb[idx] == 0) member[0][zeroTCnt++] = idx;
            else member[1][oneTCnt++] = idx;
        }

        do{
            int a[2]; int tmp = 0;
            for(int i = 0; i < N/2; i++) {
                if(perm[0][i]) a[tmp++] = member[0][i];
            }
            synZero += board[a[0]][a[1]] + board[a[1]][a[0]];
        } while(next_permutation(perm[0], perm[0] + N/2));

        do{
            int a[2]; int tmp = 0;
            for(int i = 0; i < N/2; i++) {
                if(perm[1][i]) a[tmp++] = member[1][i];
            }
            synOne += board[a[0]][a[1]] + board[a[1]][a[0]];
        } while(next_permutation(perm[1], perm[1] + N/2));

        MIN = min(max(synZero, synOne) - min(synZero, synOne), MIN);
    } while(next_permutation(comb, comb+N));

    std::cout << MIN;
}