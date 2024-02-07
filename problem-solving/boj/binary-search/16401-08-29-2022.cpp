#include <iostream>
using namespace std;

int M, N;
int num[1000002];

bool solve(int m) {
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        cnt += num[i]/m;
        if(cnt >= M) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> M >> N;
    for(int i = 0; i < N; i++) cin >> num[i];

    int begin = 1, end = 1000000000;
    while(begin < end) {
        int mid = (begin + end + 1)/2;
        if(solve(mid)) begin = mid;
        else end = mid - 1;
    }
    if(solve(begin)) cout << begin;
    else cout << 0;
}