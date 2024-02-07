#include <iostream>
#define ll long long
using namespace std;

int N; ll M;
int H[1000002];

bool solve(int m) {
    ll h = 0;
    for(int i = 0; i < N; i++) {
        h += max(0, H[i] - m);
        if(h >= M) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> H[i];

    ll begin = 0; ll end = 2000000000;

    while(begin < end) {
        ll mid = (begin + end + 1) / 2;
        if(solve(mid)) begin = mid;
        else end = mid - 1;
    }
    cout << begin;
}