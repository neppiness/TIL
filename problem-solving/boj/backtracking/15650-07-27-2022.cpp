#include <iostream>

using namespace std;

int N, M;
int ans[10];
bool isUsed[10] = {false};

void perm(int m, int cur){
    if(m == 0) {
        for(int i = 1; i <= M; i++) cout << ans[i] << ' ';
        cout << '\n';
    }
    else {
        for(int i = cur; i <= N; i++) {
            if(isUsed[i]) continue;
            else {
                isUsed[i] = true;
                ans[M-m+1] = i;
                perm(m-1, i);
                isUsed[i] = false;
            }
        }
    }
}


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    int arr[M];

    perm(M, 1);
}