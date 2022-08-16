#include <iostream>
using namespace std;

int N, cnt[1000002];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> N;

    cnt[1] = 0;
    for(int i = 2; i <= N; i++) {
        cnt[i] = 0x7f7f7f7f;
        if(i%2 == 0) cnt[i] = cnt[i/2] + 1;
        if(i%3 == 0) cnt[i] = min(cnt[i], cnt[i/3] + 1);
        cnt[i] = min(cnt[i], cnt[i-1] + 1);
    }

    cout << cnt[N] << '\n';
    cout << N << ' ';
    while(N != 1) {
        if(cnt[N]-1 == cnt[N-1]){N--; cout << N << ' ';}
        else if(N%2 == 0 && cnt[N]-1 == cnt[N/2]){N /= 2; cout << N << ' ';}
        else if(N%3 == 0 && cnt[N]-1 == cnt[N/3]){N /= 3; cout << N << ' ';}
    }
}