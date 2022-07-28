#include <iostream>
#include <algorithm>

using namespace std;

int N, M;

int num[10];
bool isUsed[10];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) num[i] = i + 1;

    do {
        bool isAccending = true;
        for(int i = 0; i < M-1; i++) {
            if(num[i] >= num[i+1]) isAccending = false;
        }
        if(!isAccending) continue;
        bool isDuplicated = true;
        for(int i = 0; i < M; i++) {
            if(!isUsed[num[i] - 1]) {isDuplicated = false; break;}
        }

        if(isDuplicated) continue;
        else fill(isUsed, isUsed + 10, false);

        for(int i = 0; i < M; i++) {
            isUsed[num[i] - 1] = true;
        }
        for(int i = 0; i < M; i++) cout << num[i] << ' ';
        cout << '\n';
    } while(next_permutation(num, num + N));
}