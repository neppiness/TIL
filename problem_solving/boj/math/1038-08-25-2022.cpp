#include <iostream>
using namespace std;

int temp[6];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    
    int N; cin >> N;

    int i = 0, seq = 0;
    if(N == 0) {cout << 0; return 0;}

    for(i = 1; i < 10; i++) {
        seq++;
        if(seq == N) {cout << seq; return 0;}
    }

    for(;i < 1000000; i++) {
        int n = i, len = 0;
        while(n != 0) {n /= 10; len++;}

        int cnt = len;
        n = i;
        while(cnt) {
            temp[--cnt] = n % 10;
            n /= 10;
        }

        bool isAns = 1;
        while(--len)
            if(temp[len-1] <= temp[len]) isAns = 0;
        if(isAns) {
            seq++;
            if(seq == N) {cout << i; return 0;}
        }
    }
    cout << -1;
}