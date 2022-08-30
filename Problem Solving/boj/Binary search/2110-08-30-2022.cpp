#include <algorithm>
#include <iostream>

using namespace std;

int N, C;
int x[200002];

bool solve(int len){
    for(int idx = 0; idx <= N - C; idx++) {
        int cnt = 0;
        int st = x[idx];
        while(idx != N) {
            idx = lower_bound(x + idx, x + N, x[idx] + len) - x;
            cnt++;
        }
        if(cnt >= C) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> C;
    for(int i = 0; i < N; i++) cin >> x[i];
    sort(x, x+N);

    int begin = 1, end = 1111111111;
    int mid;
    while(begin < end) {
        mid = (begin + end + 1)/2;
        if(solve(mid)) begin = mid;
        else end = mid - 1;
    }
    cout << begin;
}