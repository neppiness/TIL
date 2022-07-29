#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
bool isDuplicated[10001] = {false};
int num[10], ans[10];

void search(int m) {
    if(M == m) {
        for(int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int i = 0; i < N; i++) {
            ans[m] = num[i];
            search(m+1);
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
        isDuplicated[input] = true;
        num[idx++] = input;
    }
    N = idx; sort(num, num+N);
    // do {} while(next_permutation(num, num+N));

    search(0);
}