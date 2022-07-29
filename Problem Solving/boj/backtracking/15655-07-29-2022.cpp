#include <iostream>
#include <algorithm>

using namespace std;
int N, M, num[10], ans[10];
bool isUsed[10] = {false};

void search(int m, int cur){
    if(m == M) {
        for(int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int idx = cur; idx < N; idx++) {
            if(isUsed[idx] == true) continue;
            isUsed[idx] = true;
            ans[m] = num[idx];
            search(m + 1, idx);
            isUsed[idx] = false;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    for(int i = 0; i < N; i++) cin >> num[i];

    do {} while(next_permutation(num, num+N));

    search(0, 0);
}