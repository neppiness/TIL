#include <iostream>

using namespace std;

int N, S, cnt, totalNum;
bool isUsed[30] = {false};
int input[30], ans[30];

void check() {
    int sum = 0;
    for(int i = 0; i < totalNum; i++) sum += ans[i];
    if(sum == S) cnt++;
}

void search(int n, int cur) {
    if(n == 0) check();
    else {
        for(int i = cur; i < N; i++){
            if(isUsed[i]) continue;
            else {
                ans[totalNum-n] = input[i];
                isUsed[i] = 1;
                search(n-1, i);
                isUsed[i] = 0;
            }
        }
    }
}

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> S;
    for(int i = 0; i < N; i++) cin >> input[i];

    for(int n = 1; n <= N; n++) {totalNum = n; search(n, 0);}

    cout << cnt;
}