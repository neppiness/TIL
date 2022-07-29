#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int num[10], ans[10];
bool isUsed[10];

void search(int m) {
    if(m == M) {
        for(int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int i = 0; i < N; i++) {
            if(isUsed[i]) continue;
            ans[m] = num[i];
            isUsed[i] = 1;
            search(m+1);
            isUsed[i] = 0;
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> num[i];

    do {} while(next_permutation(num, num + N));
    search(0);
}