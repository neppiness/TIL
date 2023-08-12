#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[10], ans[10];
bool isUsed[10];

void search(int m, int cur) {
    if(m == M) {
        for(int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int i = cur; i < N; i++) {
            if(i != 0) {
                int prv = i - 1;
                if(num[i] == num[prv] && !isUsed[prv]) continue;
            }
            if(isUsed[i]) continue;
            isUsed[i] = true;
            ans[m] = num[i];
            search(m+1, i);
            isUsed[i] = false;
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