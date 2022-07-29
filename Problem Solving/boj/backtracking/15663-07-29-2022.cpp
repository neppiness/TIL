#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int num[10], ans[10];
int isUsed[10] = {0};

bool OOB(int cur){
    if(cur >= 10 || cur < 0) return true;
    return false;
}

void search(int m) {
    if(m == M) {
        for(int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int cur = 0; cur < N; cur++) {
            if(!OOB(cur-1)) {
                if((num[cur] == num[cur-1]) && !isUsed[cur-1]) continue;
            }
            if(isUsed[cur]) continue;

            ans[m] = num[cur];
            isUsed[cur] = true;
            search(m+1);
            isUsed[cur] = false;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0); 

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> num[i];

    do {} while(next_permutation(num, num+N));

    search(0);
}