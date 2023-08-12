#include <iostream>
#define ll long long
using namespace std;

int K, N;
int num[1000002];

bool solve(long long x){
    int cnt = 0;
    for(int i = 0; i < K; i++) {
        cnt += num[i]/x;
        if(cnt >= N) return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> K >> N;

    for(int i = 0; i < K; i++) cin >> num[i];

    ll begin = 1, end = 2147483647;
    ll mid = (end + begin)/2;
    while(begin != mid) {
        if(!solve(mid)) end = mid - 1;
        else begin = mid;
        mid = (end + begin)/2;
    }
    if(solve(end)) cout << end;
    else cout << begin;
}