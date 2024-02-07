#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool isDuplicated[10001] = {false};
int num[10], ans[10];

void search(int m, int cur) {
    if(m == M) {
        for(int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int idx = cur; idx < N; idx++) {
            ans[m] = num[idx];
            search(m+1, idx);
        }
    }
}


int main(void){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;

    int n = N, idx = 0, input;
    while(n--) {
        cin >> input;
        if(isDuplicated[input]) continue;
        isDuplicated[input] = 1;
        num[idx++] = input;
    }

    N = idx; sort(num, num + N);

    search(0, 0);
}