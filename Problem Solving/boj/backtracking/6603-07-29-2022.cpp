#include <iostream>

using namespace std;

int K, num[15], ans[6];
bool isUsed[10];

void sixNumCom(int m, int cur){
    if(m == 6) {
        for(int i = 0; i < 6; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int idx = cur; idx < K; idx++) {
            if(isUsed[idx]) continue;
            isUsed[idx] = 1;
            ans[m] = num[idx];
            sixNumCom(m + 1, idx);
            isUsed[idx] = 0;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    while(true) {
        cin >> K;
        if(K == 0) break;

        for(int i = 0; i < K; i++) {
            cin >> num[i];
        }

        sixNumCom(0, 0);
        cout << '\n';
    }
}