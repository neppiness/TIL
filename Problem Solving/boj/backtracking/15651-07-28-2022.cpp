#include <iostream>

using namespace std;

int M, N;
int ans[10];

void search(int m) {
    if(m == M) {
        for(int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int num = 1; num <= N; num++) {ans[m] = num; search(m + 1);}
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    
    search(0);
}