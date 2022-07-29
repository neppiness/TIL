#include <algorithm>
#include <iostream>

using namespace std;

int N, M;
int num[10], ans[10];

void search(int m) {
    if(m == M) {
        for(int i = 0; i < M; i++) cout << ans[i] << ' ';
        cout << '\n';
    } else {
        for(int i = 0; i < N; i++) {
            ans[m] = num[i];
            search(m+1);
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